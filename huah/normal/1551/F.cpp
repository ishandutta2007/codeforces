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
const int N=105,mod=1e9+7;
int n,k,c[N][N],vis[N];
vector<int>e[N];
int dp[N][N];
void dfs(int u,int p,int len)
{
  vis[len]++;
  for(int v:e[u])
  if(v!=p) dfs(v,u,len+1);
}
ll C(int n,int m)
{
  if(n<m) return 0;
  if(m==0||m==n) return 1;
  if(m==1) return n;
  if(c[n][m]) return c[n][m];
  return c[n][m]=(C(n-1,m-1)+C(n-1,m))%mod;
}
void sol(int cas)
{
  sc(n,k);
  rep(i,1,n) e[i].clear();
  rep(i,1,n-1)
  {
    int u,v;
    sc(u,v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  if(k==2) out(n*(n-1)/2);
  else
  {
    ll ans=0;
    rep(i,1,n)
    {
      memset(dp,0,sizeof(dp));
      rep(i,0,n-1) dp[i][0]=1;
      for(int v:e[i])
      {
        rep(t,0,n-1) vis[t]=0;
        dfs(v,i,0);
        rep(t,0,n-1)
        if(vis[t])
        {
          for(int h=k-1;h>=0;h--)
          dp[t][h+1]=(dp[t][h+1]+1ll*dp[t][h]*vis[t])%mod;
        }
      }
      rep(i,0,n-1) ans=(ans+dp[i][k])%mod;
    }
    out(ans);
  }
}
int main() 
{
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