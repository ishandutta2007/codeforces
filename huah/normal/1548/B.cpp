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
const int N=5e5+5,mod=1e9+7;
int n,lg[N];
ll a[N],dp[N][20];
void st()
{
  for(int i=1;1<<i<=n-1;i++)
    for(int j=1;j+(1<<i)-1<=n-1;j++)
    dp[j][i]=__gcd(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
}
ll query(int l,int r)
{
  int k=lg[r-l+1];
  return __gcd(dp[l][k],dp[r-(1<<k)+1][k]);
}
void sol(int cas)
{
  sc(n);
  rep(i,1,n) sc(a[i]);
  rep(i,1,n-1) dp[i][0]=abs(a[i+1]-a[i]);
  st();
  int ans=1;
  for(int i=1;i<=n-1;i++)
    if(dp[i][0]!=1)
    {
      int r=i;
      for(int j=1<<18;j;j>>=1)
      if(r+j<=n-1&&query(i,r+j)!=1) r+=j;
      ans=max(ans,r-i+2);
    }
  out(ans);
}
int main() 
{
  rep(i,1,N-1) lg[i]=lg[i-1]+(1<<lg[i-1]==i),lg[i-1]--;
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  scanf("%d",&t);
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