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
using namespace std;
const int N =5e5+5;
int n,m,roads[N],d[N],dfn[N],si[N],inq[N],low[N],id,f[N];
vector<int>e[N],ee[N];
bool z[N];
int top,s[N];
void dfs(int u)
{
  dfn[u]=low[u]=++id;
  inq[s[++top]=u]=true;
  for(int v:e[u])
  {
    if(!dfn[v])
    {
      dfs(v);low[u]=min(low[u],low[v]);
    }
    else if(inq[v]) low[u]=min(low[u],dfn[v]);
  }
  if(low[u]==dfn[u])
  {
    while(s[top]!=u)
    {
      f[s[top]]=u;
      inq[s[top--]]=false;
    }
    f[u]=u;top--;inq[u]=false;
  }
}
unordered_map<ll,bool>vis;
queue<int>q;
void sol(int cas)
{
  sc(n,m);
  id=0;
  rep(i,1,n) e[i].clear(),ee[i].clear(),dfn[i]=0,si[i]=0,roads[i]=0,d[i]=0,z[i]=false;
  rep(i,1,m)
  {
    int u,v;sc(u,v);
    if(u==v)
    {
      z[u]=true;continue;
    }
    e[u].push_back(v);
  }
  for(int i=1;i<=n;i++)
    if(!dfn[i]) dfs(i);
  for(int i=1;i<=n;i++) si[f[i]]++,z[f[i]]|=z[i];
  roads[f[1]]=si[f[1]]==1?1:-1;
  vis.clear();
  for(int i=1;i<=n;i++)
    for(int v:e[i])
    {
      int x=f[i],y=f[v];
      if(x==y||vis[x*2000000000ll+y]) continue;
      vis[x*2000000000ll+y]=true;
      ee[x].push_back(y);
      d[y]++;
    }
  for(int i=1;i<=n;i++) if(f[i]==i&&d[i]==0) q.push(i);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    if(roads[u]!=0&&(z[u]||si[u]>=2)) roads[u]=-1;
    for(int v:ee[u])
    {
      if(roads[u]==-1||roads[v]==-1)
        roads[v]=-1;
      else roads[v]+=roads[u],roads[v]=min(roads[v],999);
      d[v]--;
      if(d[v]==0) q.push(v);
    }
  }
  for(int i=1;i<=n;i++)
  {
    roads[f[i]]=min(roads[f[i]],2);
    printf(i==n?"%d\n":"%d ",roads[f[i]]);
  }
}
int main() {
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t,cas=0;scanf("%d",&t);
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