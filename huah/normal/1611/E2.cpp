#include<bits/stdc++.h>
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
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937_64 gen(time(0));
ll rdint(ll l,ll r){return uniform_int_distribution<ll>(l,r)(gen);}
const int N=5e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,k,low[N];
bool vis[N],ok[N],lev[N];
vector<int>e[N];
void dfs(int u,int p,int dep)
{
  low[u]=vis[u]?0:inf;
  lev[u]=true;
  for(int v:e[u])
  {
    if(v==p) continue;
    dfs(v,u,dep+1);
    low[u]=min(low[u],low[v]+1);
    lev[u]=false;
  }
  ok[u]=low[u]>dep;
}
bool gfs(int u,int p,bool ko)
{
  ko&=ok[u];
  if(lev[u]&&u!=1&&ko) return true;
  for(int v:e[u])
  {
    if(v==p) continue;
    if(gfs(v,u,ko)) return true;
  }
  return false;
}
int hfs(int u,int p)
{
  if(!ok[u]&&u!=1) return 1;
  int ans=0;
  for(int v:e[u])
  {
    if(v==p) continue;
    ans+=hfs(v,u);
  }
  return ans;
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t=1;
    sc(t);
    while(t--)
    {
      sc(n,k);
      rep(i,1,n) e[i].clear(),vis[i]=false;
      rep(i,1,k){int x;sc(x);vis[x]=true;}
      rep(i,1,n-1)
      {
        int u,v;sc(u,v);e[u].push_back(v);e[v].push_back(u);
      }
      dfs(1,0,0);
      if(gfs(1,0,true)) out(-1);
      else out(hfs(1,0));
    }
}