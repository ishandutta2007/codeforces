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
const int N=5e5+5,mod=998244353;
int n,m,f[N],a[N],u[N],v[N],w[N];
vector<pair<int,int>>e[N];
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
bool ans[N];
int si[N],dfn[N],id,fa[N],dep[N],top[N],son[N];
void dfs1(int u,int p)
{
  dep[u]=dep[p]+1;
  fa[u]=p;
  si[u]=1;
  for(pair<int,int>x:e[u])
  {
    int v=x.first;
    if(v==p) continue;
    a[v]=a[u]^x.second;
    dfs1(v,u);
    si[u]=max(si[u],si[v]+1);
    if(si[v]>si[son[u]]) son[u]=v;
  }
}
void dfs2(int u,int tp)
{
  dfn[u]=++id;
  top[u]=tp;
  if(son[u]) dfs2(son[u],tp);
  for(pair<int,int>x:e[u])
  {
    int v=x.first;
    if(v!=fa[u]&&v!=son[u])
      dfs2(v,v);
  }
}
int t[N<<2],lz[N<<2];
void update(int l,int r,int k)
{
  t[k]|=lz[k];
  if(l!=r)
    lz[k<<1]|=lz[k],lz[k<<1|1]|=lz[k];
}
int query(int l,int r,int k,int x,int y)
{
  if(lz[k]) update(l,r,k);
  // if(l==1&&r==n) cout<<"query: "<<x<<' '<<y<<endl;
  if(r<x||l>y) return 0;
  if(l>=x&&r<=y) return t[k];
  int m=(l+r)>>1;
  return query(l,m,k<<1,x,y)|query(m+1,r,k<<1|1,x,y);
}
void ins(int l,int r,int k,int x,int y)
{
  if(lz[k]) update(l,r,k);
  // if(l==1&&r==n) cout<<"ins: "<<x<<' '<<y<<endl;
  if(r<x||l>y) return;
  if(l>=x&&r<=y)
  {
    lz[k]=1;update(l,r,k);
    return;
  }
  int m=(l+r)>>1;
  ins(l,m,k<<1,x,y);
  ins(m+1,r,k<<1|1,x,y);
  t[k]=t[k<<1]|t[k<<1|1];
}
bool judge(int u,int v,int w)
{
  if(!(a[u]^a[v]^w)) return false;
  // cout<<"U: "<<u<<' '<<v<<endl;
  int flag=0;
  while(top[u]!=top[v])
  {
    if(dep[top[u]]>dep[top[v]])
      flag|=query(1,n,1,dfn[top[u]],dfn[u]),u=fa[top[u]];
    else flag|=query(1,n,1,dfn[top[v]],dfn[v]),v=fa[top[v]];
  }
  if(dep[u]<dep[v]) swap(u,v);
  if(dep[u]>dep[v])
    flag|=query(1,n,1,dfn[v]+1,dfn[u]);
  if(flag) return false;
  // cout<<flag<<endl;
  return true;
}
void ins(int u,int v)
{
  while(top[u]!=top[v])
  {
    if(dep[top[u]]>dep[top[v]])
      ins(1,n,1,dfn[top[u]],dfn[u]),u=fa[top[u]];
    else ins(1,n,1,dfn[top[v]],dfn[v]),v=fa[top[v]];
  }
  if(dep[u]<dep[v]) swap(u,v);
  if(dep[u]>dep[v])
    ins(1,n,1,dfn[v]+1,dfn[u]);
}
void sol(int cas)
{
  sc(n,m);
  rep(i,1,n) f[i]=i;
  rep(i,1,m)
  {
    sc(u[i],v[i],w[i]);
    int x=getf(u[i]),y=getf(v[i]);
    if(x!=y)
    {
      e[u[i]].push_back({v[i],w[i]});
      e[v[i]].push_back({u[i],w[i]});
      f[x]=y;
      ans[i]=true;
    }
  }
  rep(i,1,n)
  if(f[i]==i)
  {
    dfs1(i,0);
    dfs2(i,i);
  }
  rep(i,1,m)
  if(!ans[i])
  {
    assert(getf(u[i])==getf(v[i]));
    ans[i]=judge(u[i],v[i],w[i]);
    if(ans[i]) ins(u[i],v[i]);
  }
  rep(i,1,m) printf(ans[i]?"YES\n":"NO\n");
}
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("2.out", "w", stdout);
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