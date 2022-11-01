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
const int N=1e6+5,mod=1e9+7;
int n,a[N];
vector<pair<int,int>>dp[2];
void update(int &x,int y){if(y<x)x=y;}
vector<int>ans;
vector<int>vc[8192];
bool vis[8192];
void ins(pair<int,int>&x,vector<pair<int,int>>&dp)
{
  if(vis[x.second]) return;
  dp.push_back(x);
  vis[x.second]=true;
}
int main()
{
  // freopen("1.in","r",stdin);
  int u=0;
  sc(n);
  rep(i,1,n) sc(a[i]),vc[a[i]].push_back(i);
  dp[u].push_back({0,0});
  rep(i,0,8191)
  if(vc[i].size())
  {
    memset(vis,false,sizeof(vis));
    int j=0,k=0;
    vector<pair<int,int>>g;
    for(int x:vc[i])
    {
      while(j<dp[u].size()&&dp[u][j].first<x)
      {
        g.push_back({x,dp[u][j].second^i});
        j++;
      }
    }
    j=0,k=0;
    while(j<dp[u].size()&&k<g.size())
    {
      if(dp[u][j].first<g[k].first) ins(dp[u][j],dp[u^1]),j++;
      else ins(g[k],dp[u^1]),k++;
    }
    while(j<dp[u].size()) ins(dp[u][j],dp[u^1]),j++;
    while(k<g.size()) ins(g[k],dp[u^1]),k++;
    dp[u].clear();
    u^=1;
  }
  for(auto x:dp[u]) ans.push_back(x.second);
  sort(ans.begin(),ans.end());
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