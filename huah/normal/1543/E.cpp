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
const int N =2e5+5;
int n,m,c[N],cl[N],p[N],d[N],pos[N];
vector<int>e[N];
vector<pair<int,int>>edge[N];
bool vis[N];
queue<int>q;
bool cmp(int &x,int &y)
{
  return c[x]<c[y];
}
bool cmp2(int &x,int &y)
{
  return pos[d[x]]<pos[d[y]];
}
void div(int l,int r,int k)
{
  if(l==r) return;
  rep(i,l,r) e[p[i]].clear(),c[p[i]]=0;
  for(auto x:edge[k])
  {
    e[x.first].push_back(x.second);
    e[x.second].push_back(x.first);
  }
  c[edge[k].back().first]=1;
  c[edge[k].back().second]=2;
  q.push(edge[k].back().first);
  q.push(edge[k].back().second);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for(int v:e[u])
    if(!c[v])
    {
      c[v]=c[u];
      q.push(v);
    }
  }
  sort(p+l,p+r+1,cmp);
  edge[k+1].clear();
  for(auto x:edge[k])
  if(c[x.first]==c[x.second]&&c[x.first]==1) 
    edge[k+1].push_back(x);
  else if(c[x.first]!=c[x.second])
  {
    d[x.first]=x.second,d[x.second]=x.first;
  }
  int m=(l+r)>>1;
  div(l,m,k+1);
  rep(i,l,m) pos[p[i]]=i;
  sort(p+m+1,p+r+1,cmp2);
}
void check()
{
  map<pair<int,int>,bool>vis;
  for(auto x:edge[1])
  {
    vis[x]=true;
    swap(x.first,x.second);
    vis[x]=true;
  }
  bool flag=true;
  for(int i=m;i>=2;i>>=1)
  {
    for(int j=0;j<m;j+=i)
    {
      for(int k=0;k<i/2;k++)
      if(!vis[{p[j+k],p[j+k+i/2]}])
        flag=false;
    }
  }
  assert(flag==true);
}
void sol(int cas)
{
  sc(n);
  m=1<<n;
  edge[1].clear();
  rep(i,0,m-1) p[i]=i;
  rep(i,1,n*m/2)
  {
    int u,v;sc(u,v);
    edge[1].push_back({u,v});
  }  
  div(0,m-1,1);
  check();
  rep(i,0,m-1) printf(i==m-1?"%d\n":"%d ",p[i]);
  if(n!=(n&-n)){out(-1);return;}
  rep(i,0,m-1)
  {
    cl[p[i]]=0;
    rep(j,0,n-1)
      if(i>>j&1)
      cl[p[i]]^=j;
  }
  rep(i,0,m-1) printf(i==m-1?"%d\n":"%d ",cl[i]);
}
int main() {
  // freopen("1.in", "r", stdin);
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