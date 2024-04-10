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
int n,k,son[N],dep[N];
vector<int>e[N];
void dfs(int u)
{
  son[u]=0;
  for(int v:e[u])
  {
    dfs(v);
    if(dep[v]>dep[son[u]]) son[u]=v;
  }
  dep[u]=dep[son[u]]+1;
}
vector<int>ans;
void getres(int u,int &t)
{
  if(!t) return;
  ans.push_back(u);
  t--;
  for(int v:e[u])
  if(t)
  {
    getres(v,t);
    ans.push_back(u);
  }
}
void getans(int u,int k)
{
  if(!k) return;
  ans.push_back(u);
  k--;
  if(!k) return;
  if(dep[son[u]]>=k)
    getans(son[u],k);
  else
  {
    int t=k-dep[son[u]];
    k-=t;
    for(int v:e[u])
      if(v!=son[u])
      {
        if(!t) continue;
        getres(v,t);
        ans.push_back(u);
      }
    k+=t;
    getans(son[u],k);
  }
}
void sol(int cas)
{
  sc(n,k);
  rep(i,1,n) e[i].clear();
  ans.clear();
  rep(i,2,n)
  {
    int p;sc(p);
    e[p].push_back(i);
  }
  dfs(1);
  getans(1,k);
  printf("%d\n",int(ans.size()-1));
  for(int i=0;i<ans.size();i++) printf(i==ans.size()-1?"%d\n":"%d ",ans[i]);
}
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  scanf("%d",&t);
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