#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
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
#define inf 0x3f3f3f3f
const int N=16005;
struct node
{
  int u,v,w;
  bool operator<(const node&o)const
  {
    return w>o.w;
  }
};
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
vector<node>e;
vector<pair<int,int>>es[2000005];
int n,k,m,s,t,tot=1,sum,a[2000005],b[2000005],id[2000005];
bool use[2000005];
int head[N],nex[N<<2],to[N<<2],flow[N<<2],wi[N<<2];
void add(int u,int v,int f,int w)
{
  to[++tot]=v;nex[tot]=head[u];head[u]=tot;flow[tot]=f;wi[tot]=w;
  to[++tot]=u;nex[tot]=head[v];head[v]=tot;flow[tot]=0;wi[tot]=-w;
}
int dis[N],pre[N];
queue<int>q;
bool vis[N];
bool spfa()
{
  memset(dis,inf,sizeof(dis));
  dis[s]=0;  
  q.push(s);
  vis[s]=true;
  while(!q.empty())
  {
    int u=q.front();q.pop();
    vis[u]=false;
    for(int i=head[u];i;i=nex[i])
    {
      int v=to[i];
      if(flow[i]&&dis[v]>dis[u]+wi[i])
      {
        dis[v]=dis[u]+wi[i];
        pre[v]=i;
        if(!vis[v]) q.push(v),vis[v]=true;
      }
    }
  }
  return dis[t]!=inf;
}
int cal(int k)
{
  int ans=0;
  while(k--&&spfa()&&dis[t]<0)
  {
    for(int i=t;i!=s;i=to[pre[i]^1])
    {
      flow[pre[i]]--;
      flow[pre[i]^1]++;
      ans+=wi[pre[i]];
    }
  }
  return ans;
}
void sol(int cas)
{
  sc(n,k);
  m=min(2*n*k,(1<<n)*n/2);
  rep(i,0,(1<<n)-1)
  {
    sc(a[i]);
    for(int j=0;j<n;j++)
      if(i>>j&1)
      es[a[i]+a[i^(1<<j)]].push_back({i^(1<<j),i});
  }
  int st=m;
  for(int i=2000000;i>=0&&st;i--)
    for(int j=0;j<es[i].size()&&st;j++)
    {
      st--;
      e.push_back({es[i][j].first,es[i][j].second,i});
    }
  for(int i=0;i<m;i++)
  {
    if(!use[e[i].u]) use[e[i].u]=true,b[++sum]=e[i].u;
    if(!use[e[i].v]) use[e[i].v]=true,b[++sum]=e[i].v;
  }
  sort(b+1,b+1+sum);
  rep(i,1,sum) id[b[i]]=i;
  s=sum+1;t=s+1;
  for(int i=0;i<m;i++)
  {
    if(__builtin_popcount(e[i].u)&1) swap(e[i].u,e[i].v);
    add(id[e[i].u],id[e[i].v],1,-e[i].w);
  }
  rep(i,1,sum)
    if(__builtin_popcount(b[i])&1) add(i,t,1,0);
    else add(s,i,1,0);
  printf("%d\n",-cal(k));
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