#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f3f3f3f3fll
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
const int N=1005,mod=998244353;
int n,s,t,tot=1,head[N<<1],nex[N<<4],to[N<<4],x[N],y[N],w[N];
ll flow[N<<4];
map<pair<int,int>,int>id;
int td[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void add(int u,int v,ll w)
{
  // cout<<"Edge: "<<u<<' '<<v<<' '<<w<<endl;
  to[++tot]=v;nex[tot]=head[u];head[u]=tot;flow[tot]=w;
  to[++tot]=u;nex[tot]=head[v];head[v]=tot;flow[tot]=0;
}
queue<int>q;
int d[N<<1];
int bfs()
{
  memset(d,0,sizeof(d));
  d[s]=1;q.push(s);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for(int i=head[u];i;i=nex[i])
    {
      int v=to[i];
      if(!d[v]&&flow[i])
      {
        d[v]=d[u]+1;
        q.push(v);
      }
    }
  }
  return d[t];
}
ll dfs(int u,ll f)
{
  if(u==t) return f;
  ll ans=0;
  for(int i=head[u];i;i=nex[i])
  {
    int v=to[i];
    ll y;
    if(d[v]==d[u]+1&&flow[i]&&(y=dfs(v,min(f,flow[i]))))
    {
      ans+=y;
      flow[i]-=y;
      flow[i^1]+=y;
      f-=y;
      if(f==0) return ans;
    }
  }
  if(!ans) d[u]=0;
  return ans;
}
ll Dinic()
{
  ll ans=0;
  while(bfs())
    while(ll val=dfs(s,inf))
    ans+=val;
  return ans;
}
void sol(int cas)
{
  td[0][0]=1;
  td[0][1]=2;
  td[1][0]=0;
  td[1][1]=3;
  sc(n);
  ll sum=0;
  rep(i,1,n)
  {
    sc(x[i],y[i],w[i]);
    id[{x[i],y[i]}]=i;
    add(i,i+n,w[i]);
    sum+=w[i];
  }
  s=2*n+1;t=2*n+2;
  rep(i,1,n)
  {
    rep(j,0,3)
    {
      int xx=x[i]+dx[j];
      int yy=y[i]+dy[j];
      if(id[{xx,yy}]&&td[(xx%2+2)%2][(yy%2+2)%2]==td[(x[i]%2+2)%2][(y[i]%2+2)%2]+1)
        add(i+n,id[{xx,yy}],inf);
    }
    if(td[(x[i]%2+2)%2][(y[i]%2+2)%2]==0) add(s,i,inf);
    if(td[(x[i]%2+2)%2][(y[i]%2+2)%2]==3) add(i+n,t,inf);
  }
  printf("%lld\n",sum-Dinic());
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