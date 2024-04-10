#pragma GCC optimize(2)
#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
void ary(int *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void ary(ll *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void oary(int *a,int n){rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);}
void oary(ll *a,int n){rep(i,1,n) printf(i==n?"%lld\n":"%lld ",a[i]);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const int N=5005,mod=998244353;
int n,k,si[N],dp[N][N],g[N];
vector<int>e[N];
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void dfs(int u,int p)
{
  si[u]=1;
  dp[u][0]=1;
  for(int v:e[u])
  {
    if(v==p) continue;
    dfs(v,u);
    memset(g,0,sizeof(g));
    for(int i=0;i<=si[u];i++)
      for(int j=0;j<=si[v];j++)
    {
      if(i+j+1<=k) add(g[max(i,j+1)],1ll*dp[u][i]*dp[v][j]%mod);
      add(g[i],1ll*dp[u][i]*dp[v][j]%mod);
    }
    si[u]+=si[v];
    memcpy(dp[u],g,sizeof(g));
  }
}
int main()
{
  sc(n,k);
  rep(i,1,n-1)
  {
    int u,v;sc(u,v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1,0);
  int ans=0;
  rep(i,0,k) add(ans,dp[1][i]);
  out(ans);
}