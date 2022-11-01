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
const int N=4e6+5;
int n,m,mod;
ll dp[N];
int get(int l,int r)
{
    r=min(r,n);
    return (dp[l]+mod-dp[r+1])%mod;
}
void sol(int cas)
{
    sc(n,mod);
    dp[n]=1;
    for(int i=n-1;i>=1;i--)
    {
        dp[i]=dp[i+1];
        for(int j=2;1ll*i*j<=n;j++)
            dp[i]=(dp[i]+get(i*j,i*j+j-1))%mod;
        dp[i]=(dp[i]+dp[i+1])%mod;
    }
    out(get(1,1));
}
int main()
{
    // freopen("1.in","r",stdin);
    srand(time(0));
    int t=1,cas=0;
    // scanf("%d",&t);
    while(t--)
    {
        sol(++cas);
    }
}