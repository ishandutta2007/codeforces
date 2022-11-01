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
const int N=305,mod=998244353;
int n,dp[N][N][2],g[N][2];
vector<int>e[N];
int r,si[N],h[N];
void update(int &x,int y){x+=y;if(x>=mod)x-=mod;}
ll qpow(ll a,ll n)
{
  ll ans=1;for(;n;n>>=1,a=a*a%mod)if(n&1) ans=ans*a%mod;return ans;
}
void dfs(int u,int p)
{
  memset(dp[u],0,sizeof(dp[u]));
  si[u]=1;
  dp[u][0][1]=dp[u][0][0]=1;
  for(int v:e[u])
  {
    if(v==p) continue;
    dfs(v,u);
    memset(g,0,sizeof(g));
    for(int i=0;i<=min(r+1,si[u]);i++)
      for(int j=0;j<=min(r+1,si[v]);j++)
    {
      if(j<=r) update(g[max(i,j+1)][0],1ll*dp[u][i][0]*dp[v][j][0]%mod);
      update(g[min(i,j+1)][1],1ll*dp[u][i][1]*dp[v][j][1]%mod);
      if(i+(j+1)<=r)
      {
        update(g[j+1][1],1ll*dp[u][i][0]*dp[v][j][1]%mod);
        if(j<=r) update(g[i][1],1ll*dp[u][i][1]*dp[v][j][0]%mod);
      }
      else
      {
        update(g[i][0],1ll*dp[u][i][0]*dp[v][j][1]%mod);
        if(j<=r) update(g[j+1][0],1ll*dp[u][i][1]*dp[v][j][0]%mod);
      }
    }
    si[u]+=si[v];
    memcpy(dp[u],g,sizeof(g));
  }
  // cout<<"U: "<<u<<endl;
  // rep(i,0,si[u])
  //   cout<<dp[u][i][0]<<' '<<dp[u][i][1]<<endl;
}
void sol(int cas)
{
  sc(n);
  rep(i,1,n-1)
  {
    int u,v;sc(u,v);e[u].push_back(v);e[v].push_back(u);
  }
  ll ans=0;
  h[0]=1;
  rep(i,1,n)
  {
    r=i;
    dfs(1,0);
    rep(j,0,i+1) h[i]=(h[i]+dp[1][j][1])%mod;
    ll s=(h[i]+mod-h[i-1])%mod;
    ans=(ans+s*(i-1))%mod;
    // cout<<i<<' '<<s<<' '<<h[i]<<' '<<h[i-1]<<endl;
  }
  ans=(ans-1+n)%mod;
  ans=ans*qpow(qpow(2,n),mod-2)%mod;
  out(ans);
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
what is the equal problem?
*/