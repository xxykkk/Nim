#include <bits/stdc++.h>
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,int> PLI;
const int INF=0x3f3f3f3f,MOD=998244353,P=131,N=15, M=110;

int e[M],h[N],ne[M],idx;

void add(int a, int b)
{
	e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}


int a[N], n;

bool check()
{
    rep(i,1,n) if(a[i]) return true;
    return false;
}

void get()
{
    int x=0;
    rep(i,1,n) x ^= a[i];
    if(x==0)
    {
        cout<<"当前处于必败态"<<endl;
        rep(i,1,n)
        {
            if(a[i])
            {
                a[i]--;
                printf("解答：第%d堆拿出1个石子\n", i);
                return;
            }
        }
    }
    else cout<<"当前处于必胜态"<<endl;

    for(int i=31;i>=0;i--)
    {
        if(x>>i&1)
        {
            rep(j,1,n) if(a[j] >> i & 1)
            {
                printf("解答：第%d堆拿出%d个石子\n", j, a[j] - (a[j] ^ x));
                a[j] ^= x;
                break;
            }
            break;
        }
    }
}

void adver()
{
    cout<<"请输入对方操作的《堆编号》和《取走的数量》：";
    int kk, cnt; cin>>kk>>cnt;
    a[kk]-=cnt;
}

int main()
{
    cout<<"请输入石子《堆数》：";
    cin>>n;
    cout<<"请输入《每一堆石子的数量》，以空格分开：";
    rep(i,1,n) cin>>a[i];
    cout<<"我是先手，输入《1》，否则输入《0》"<<endl;
    int t; cin>>t;

    if(!t) adver();
    while(check())
    {
        cout<<"-------------------------------------------"<<endl;
        cout<<"现在的石子数量信息："<<endl;
        rep(i,1,n) cout<<a[i]<<' '; cout<<endl;

        get();
        if(!check()) 
        {
            cout<<"拿完此次，对手输了"<<endl;
            break;
        }
        adver();
        if(!check())
        {
            cout<<"对手拿完此次，我输了"<<endl;
        }
    }
    return 0;
}









