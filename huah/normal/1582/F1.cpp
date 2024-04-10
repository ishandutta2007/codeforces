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
const int N=1e5+5,mod=1e9+7;
int n,a[N],dp[2][555];
void update(int &x,int y){if(y<x)x=y;}
vector<int>ans;
int main()
{
  // freopen("1.in","r",stdin);
  int u=0;
  memset(dp,inf,sizeof(dp));
  dp[u][0]=0;
  sc(n);
  rep(i,1,n)
  { 
    sc(a[i]);
    update(dp[u^1][a[i]],a[i]);
    rep(j,0,511)
      if(dp[u][j]!=inf)
    {
      update(dp[u^1][j],dp[u][j]);
      if(a[i]>dp[u][j])
        update(dp[u^1][j^a[i]],a[i]);
    }
    memset(dp[u],inf,sizeof(dp[u]));
    u^=1;
  }
  rep(j,0,511)
    if(dp[u][j]!=inf)
    ans.push_back(j);
  printf("%d\n",ans.size());
  for(int i=0;i<ans.size();i++)
    printf(i==ans.size()-1?"%d\n":"%d ",ans[i]);
}
/*
dp[i][k]=dp[i+k][k-1]<=sum[i+k-1]-sum[i-1]
*/
/*
befor submit code check:
freopen
size of N
mod
debug output
*/