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
const int N=20,mod=1e9+7;
int n,a[N],p[N][N];
ll qpow(ll a,ll b)
{
  ll ans=1;
  for(;b;b>>=1,a=a*a%mod)
  if(b&1) ans=ans*a%mod;
  return ans;
}
int lose[14][1<<14];
int lg[1<<14];
int dp[1<<14];
int getp(int x,int y)
{
  int ans=1;
  while(x)
  {
    ans=1ll*ans*lose[lg[x&-x]][y]%mod;
    x^=x&-x;
  }
  return ans;
}
void sol(int cas)
{
  rep(i,1,(1<<14)-1) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
  rep(i,1,(1<<14)-1) lg[i]--;
  sc(n);
  rep(i,0,n-1) sc(a[i]);
  rep(i,0,n-1)
    rep(j,0,n-1)
    if(i!=j)
    p[i][j]=a[i]*qpow(a[i]+a[j],mod-2)%mod;
  rep(i,0,n-1)
  {
    lose[i][0]=1;
    for(int j=1;j<1<<n;j++)
      lose[i][j]=1ll*lose[i][j^(j&-j)]*p[lg[j&-j]][i]%mod;
  }
  int ans=0;
  rep(i,0,n-1)
  {
    dp[1<<i]=1;
    for(int j=1;j<1<<n;j++)
    if(j>>i&1)
    {
      dp[j]=1;
      for(int k=(j-1)&j;k;k=(k-1)&j)
        if(k>>i&1)
        {
          dp[j]=(dp[j]+mod-1ll*dp[k]*getp(k,k^j)%mod)%mod;
        }
    }
    ans=(ans+dp[(1<<n)-1])%mod;
  }
  out(ans);
}
int main()
{
  // freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
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