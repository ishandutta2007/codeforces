#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
const int N=1e5+5,mod=998244353;
int n,a[N];
int main() 
{
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,1,n) sc(a[i]);
        if(a[1])
        {
            printf("%d ",n+1);
            for(int i=1;i<=n;i++)
                printf(i==n?"%d\n":"%d ",i);
        }
        else
        {
            bool flag=false;
            a[n+1]=1;
            for(int i=1;i<=n;i++)
                if(a[i]==0&&a[i+1])
                {
                    flag=true;
                    for(int j=1;j<=i;j++)
                        printf("%d ",j);
                    printf(i==n?"%d\n":"%d ",n+1);
                    for(int j=i+1;j<=n;j++)
                        printf(j==n?"%d\n":"%d ",j);
                    break;
                }
            if(!flag) out(-1);
        }
    }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/