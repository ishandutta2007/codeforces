#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
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
#define inf 0x3f3f3f3f
const int N=205;
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
int n,k,x[N],y[N];
pair<int,ll>dp[N][N];
int cal(ll m)
{
  for(int len=1;len<n;len++)
    for(int l=0;l+len<n;l++)
    {
      int r=l+len;
      if(r==l+1)
        dp[l][r]={0,0};
      else
      {
        dp[l][r]={0,0};
        for(int k=l+1;k<r;k++)
        {
          ll s=abs(1ll*(y[r]-y[l])*(x[k]-x[l])-1ll*(x[r]-x[l])*(y[k]-y[l]));
          pair<int,ll>cur={dp[l][k].first+dp[k][r].first,dp[l][k].second+dp[k][r].second+s};
          if(cur.second>=m) cur.first++,cur.second=0;
          dp[l][r]=max(dp[l][r],cur);
        }
      }
    }
  return dp[0][n-1].first;
}
void sol(int cas)
{
  sc(n,k);
  rep(i,0,n-1) sc(x[i],y[i]);
  ll l=1,r=1e18,ans;
  while(l<=r)
  {
    ll m=(l+r)>>1;
    if(cal(m)>=k+1) ans=m,l=m+1;
    else r=m-1;
  }
  out(ans);
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
  return 0;
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/