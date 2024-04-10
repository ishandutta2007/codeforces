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
const int N=4e2+5;
int n,mod,dp[N][N];
int inv[N],f[N],invf[N],p[N];
void sol(int cas)
{
  sc(n,mod);
  f[0]=f[1]=inv[1]=invf[0]=invf[1]=1;
  rep(i,2,N-1) f[i]=1ll*f[i-1]*i%mod,inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod,invf[i]=1ll*invf[i-1]*inv[i]%mod;
  p[0]=1;
  rep(i,1,N-1) p[i]=2ll*p[i-1]%mod;
  for(int i=1;i<=n;i++)
    dp[i][i]=1ll*p[i-1]*invf[i]%mod;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
      for(int k=i+2;k<=n;k++)
        dp[k][j+(k-i-1)]=(dp[k][j+(k-i-1)]+1ll*dp[i][j]*p[k-i-2]%mod*invf[k-i-1]%mod)%mod;
    }
  int ans=0;
  for(int i=1;i<=n;i++) ans=(ans+1ll*dp[n][i]*f[i]%mod)%mod;
  printf("%d\n",ans);
}
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  // scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/