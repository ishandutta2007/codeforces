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
const int N=4e5+5;
int n,m,tot,head[N],nex[N],to[N],wi[N],lg[N];
void add(int u,int v,int w){to[++tot]=v;nex[tot]=head[u];head[u]=tot;wi[tot]=w;}
int dfn[N],low[N];
int id,fa[N][20],f[N],len[N],top,s[N],dep[N];
ll dis[N],g[N];
ll gcd(ll x,ll y)
{
  if(!y) return x;
  return gcd(y,x%y);
}
bool inq[N];
vector<int>nodes[N];
vector<int>e[N];
void dfs(int u)
{
  s[++top]=u;inq[u]=true;
  dfn[u]=low[u]=++id;
  for(int i=head[u];i;i=nex[i])
  {
    int v=to[i];
    if(!dfn[v])
    {
      fa[v][0]=u;len[v]=wi[i];
      dfs(v);
      low[u]=min(low[u],low[v]);
    }
    else if(inq[v]) low[u]=min(low[u],dfn[v]);
  }
  if(dfn[u]==low[u])
  {
    while(s[top]!=u)
    {
      f[s[top]]=u;
      e[fa[s[top]][0]].push_back(s[top]);
      inq[s[top--]]=false;
    }
    f[u]=u;top--;inq[u]=false;
    fa[u][0]=len[u]=0;
  }
}
int LCA(int u,int v)
{
  if(dep[u]<dep[v]) swap(u,v);
  while(dep[u]>dep[v]) u=fa[u][lg[dep[u]-dep[v]]];
  if(u==v) return u;
  for(int i=lg[dep[u]];i>=0;i--)
    if(fa[u][i]!=fa[v][i])
    u=fa[u][i],v=fa[v][i];
  return fa[u][0];
}
ll Dis(int u,int v)
{
  return dis[v]-dis[u];
}
void dfs(int u,int p,int rt)
{
  dep[u]=dep[p]+1;
  dis[u]=dis[p]+len[u];
  assert(fa[u][0]==p);
  for(int i=1;1<<i<dep[p];i++) fa[u][i]=fa[fa[u][i-1]][i-1];
  for(int v:e[u])
    dfs(v,u,rt);
}
vector<pair<pair<int,int>,int>>edge;
void sol(int cas)
{
  sc(n,m);
  rep(i,1,m)
  {
    int u,v,w;
    sc(u,v,w);
    add(u,v,w);
    edge.push_back({{u,v},w});
  }
  for(int i=1;i<=n;i++)
    if(!dfn[i]) dfs(i);
  rep(i,1,n) 
  if(f[i]==i)
    dfs(i,0,i);
  for(pair<pair<int,int>,int>&x:edge)
  {
    int &u=x.first.first,&v=x.first.second,&w=x.second;
    if(f[u]==f[v])
      g[f[u]]=gcd(g[f[u]],w-Dis(u,v));
  }
  int q;sc(q);
  while(q--)
  {
    int v,s,t;
    sc(v,s,t);
    if((t-s)%gcd(g[f[v]],1ll*t)==0) printf("YES\n");
    else printf("NO\n");
  }
}
int main() 
{
  for(int i=1;i<N;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i),lg[i-1]--;
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
*/