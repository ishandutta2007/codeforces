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
const int N=5e3+5,mod=1e9+7;
int n,k;
ll f[N],inv[N];
int c[405][405];
ll C(int nn,int m)
{
  if(c[n-nn][m]) return c[n-nn][m];
  ll ans=1;
  for(int i=1;i<=m;i++) ans=ans*(nn-i+1)%mod*inv[i]%mod;
  return c[n-nn][m]=ans;
}
int dp[405][205][205];
ll ans[205],invf[N];
void sol(int cas)
{
  f[0]=f[1]=inv[1]=invf[0]=invf[1]=1;
  rep(i,2,N-1) f[i]=f[i-1]*i%mod,inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  rep(i,2,N-1) invf[i]=invf[i-1]*inv[i]%mod;
  sc(n,k);
  dp[0][0][0]=1;
  int m=min(n,k*2);
  for(int i=0;i<=m;i++)
    for(int j=0;j<=k;j++)
    for(int t=0;t<=j;t++)
  {
    if(dp[i][t][j])
    {
      ans[j]=(ans[j]+dp[i][t][j]*invf[t]%mod)%mod;
      for(int h=2;j+h-1<=k&&i+h<=m;h++)
      dp[i+h][t+1][j+(h-1)]=(dp[i+h][t+1][j+(h-1)]+dp[i][t][j]*C(n-i,h)%mod*f[h-1]%mod)%mod;
    }
  }
  for(int i=2;i<=k;i++) ans[i]=(ans[i]+ans[i-2])%mod;
  rep(i,1,k) printf(i==k?"%lld\n":"%lld ",ans[i]);
}
int main() {
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
re Alaysis new problem
*/