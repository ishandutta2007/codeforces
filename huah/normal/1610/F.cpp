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
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=1e6+5,mod=998244353;
#define inf 0x3f3f3f3f
int n,m,mm,g,dir[N],d[N];
pair<int,int>f[N<<1];
vector<pair<int,int>>e[N][2];
queue<int>q;
bool vis[N],del[N];
pair<int,int>edge[N];
int to(int x,int y,int id)
{
  if(x==edge[id].first&&y==edge[id].second) return id<<1;
  return id<<1|1;
}
void dfs(int s)
{
  if(s==0) return;
  dir[s>>1]=s&1;
  dfs(f[s].first);dfs(f[s].second);
}
vector<pair<int,int>>ee[N];
int p[N];
bool vv[N];
void gfs(int u)
{
  for(auto x:ee[u])
  {
    if(vv[x.second]) continue;
    vv[x.second]=true;
    dfs(to(u,x.first,x.second));
    gfs(x.first);
  }
}
int main()
{
  	// freopen("1.in","r",stdin);
    sc(n,m);
    mm=m;
    rep(i,1,n) q.push(i),vis[i]=true;
    rep(i,1,m)
    {
      int u,v,w;sc(u,v,w);
      w--;
      if(w==0) p[u]^=1,p[v]^=1;
      edge[i]={u,v};
      e[u][w].push_back({v,i});
      e[v][w].push_back({u,i});
    }
    int ans=0;
    rep(i,1,n) ans+=p[i];
    while(!q.empty())
    {
      int u=q.front();q.pop();
      vis[u]=false;
      vector<pair<int,int>>vc;
      for(pair<int,int>x:e[u][0])
        if(!del[x.second])
        {
          if(x.first==u) dfs(x.second<<1);
          else vc.push_back(x);
        }
      e[u][0]=vc;
      vc.clear();
      for(pair<int,int>x:e[u][1])
        if(!del[x.second])
        {
          if(x.first==u) dfs(x.second<<1);
          else vc.push_back(x);
        }
      e[u][1]=vc;
      vc.clear();
      while(e[u][0].size()>=2)
      {
        auto x=e[u][0].back();e[u][0].pop_back();
        auto y=e[u][0].back();e[u][0].pop_back();
        del[x.second]=del[y.second]=true;
        ++m;
        edge[m]={x.first,y.first};
        f[to(x.first,y.first,m)]={to(x.first,u,x.second),to(u,y.first,y.second)};
        f[to(y.first,x.first,m)]={to(u,x.first,x.second),to(y.first,u,y.second)};
        e[x.first][0].push_back({y.first,m});
        e[y.first][0].push_back({x.first,m});
        if(!vis[x.first]) q.push(x.first),vis[x.first]=true;
        if(!vis[y.first]) q.push(y.first),vis[y.first]=true;
      }
      while(e[u][1].size()>=2)
      {
        auto x=e[u][1].back();e[u][1].pop_back();
        auto y=e[u][1].back();e[u][1].pop_back();
        del[x.second]=del[y.second]=true;
        ++m;
        edge[m]={x.first,y.first};
        f[to(x.first,y.first,m)]={to(x.first,u,x.second),to(u,y.first,y.second)};
        f[to(y.first,x.first,m)]={to(u,x.first,x.second),to(y.first,u,y.second)};
        e[x.first][1].push_back({y.first,m});
        e[y.first][1].push_back({x.first,m});
        if(!vis[x.first]) q.push(x.first),vis[x.first]=true;
        if(!vis[y.first]) q.push(y.first),vis[y.first]=true;
      }
    }
    rep(i,1,m)
      if(!del[i])
      {
        d[edge[i].first]++;
        d[edge[i].second]++;
        ee[edge[i].first].push_back({edge[i].second,i});
        ee[edge[i].second].push_back({edge[i].first,i});
      }
    rep(i,1,n)
      if(d[i]==1) gfs(i);
    rep(i,1,n) gfs(i);
    out(ans);
    rep(i,1,mm)
      putchar(dir[i]+1+'0');
    putchar('\n');
    
}