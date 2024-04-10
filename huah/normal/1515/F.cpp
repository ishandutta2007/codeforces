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
int n,m,x,f[N];
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
vector<pair<int,int>>e[N],edge;
vector<int>ans;
ll a[N],b[N];
struct node
{
  int u;
  ll s;
  node(int u=0,ll s=0):u(u),s(s){}
  bool operator<(const node&o)const
  {
    return s<o.s;
  }
};
priority_queue<node>q;
void check()
{
  assert(ans.size()==n-1);
  rep(i,1,n) f[i]=i;
  for(int z:ans)
  {
    int u=edge[z-1].first,v=edge[z-1].second;
    u=getf(u);v=getf(v);
    if(u==v||b[u]+b[v]<x) assert(0);
    b[v]=b[v]+b[u]-x;
    f[u]=v;
  }
}
void sol(int cas)
{
  sc(n,m,x);
  ll sum=0;
  rep(i,1,n) sc(a[i]),sum+=a[i],b[i]=a[i],f[i]=i;
  if(sum<1ll*x*(n-1))
  {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  rep(i,1,m)
  {
    int u,v;sc(u,v);
    if(getf(u)!=getf(v))
    {
      e[u].push_back({v,i});
      e[v].push_back({u,i});
      f[getf(u)]=getf(v);
    }
    edge.push_back({u,v});
  }
  rep(i,1,n) f[i]=i;
  rep(i,1,n) q.push(node(i,a[i]));
  while(!q.empty())
  {
    int u=q.top().u;
    ll s=q.top().s;
    q.pop();
    if(s!=a[u]||f[u]!=u) continue;
    while(e[u].size()&&getf(e[u].back().first)==u) e[u].pop_back();
    if(e[u].size()==0) continue;
    ans.push_back(e[u].back().second);
    int v=getf(e[u].back().first);
    e[u].pop_back();
    if(e[u].size()>e[v].size())
    {
      a[u]=a[u]+a[v]-x;
      f[v]=u;
      for(auto y:e[v]) e[u].push_back(y);
      q.push(node(u,a[u]));
    }
    else
    {
      a[v]=a[v]+a[u]-x;
      f[u]=v;
      for(auto y:e[u]) e[v].push_back(y);
      q.push(node(v,a[v]));
    }
  }
  for(int x:ans) out(x);
  check();
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
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/