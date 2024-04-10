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
const int N=3e5+5,mod=998244353;
int n,m,q,U[N],V[N],W[N];
set<pair<int,int>>val[N],vals;
map<pair<int,int>,int>edges;
int lim(int u)
{
  if(val[u].size()<3) return INT_MAX;
  return next(val[u].begin(),2)->first;
}
void pop(int u)
{
  auto it=val[u].begin();
  for(int i=0;i<3&&i<val[u].size();i++,it++)
    if(vals.count(*it)) vals.erase(*it);
}
void push(int u)
{
  auto it=val[u].begin();
  for(int i=0;i<3&&i<val[u].size();i++,it++)
    if(it->first<=min(lim(U[it->second]),lim(V[it->second])))
    vals.insert(*it);
}
ll cal()
{
  ll res=1ll*(vals.begin()->first)+next(vals.begin(),1)->first+next(vals.begin(),2)->first;
  int i=0;
  for(auto a=vals.begin();a!=vals.end()&&i<6;a++)
  {
    i++;
    int j=0;
    for(auto b=next(a);b!=vals.end()&&j<6;b++)
    {
      j++;
      int x=a->second,y=b->second;
      if(U[x]!=U[y]&&U[x]!=V[y]&&V[x]!=U[y]&&V[x]!=V[y])
        res=min(res,1ll*W[x]+W[y]);
    }
  }
  return res;
}
void sol(int cas)
{
  sc(n,m);
  rep(i,1,m)
  {
    sc(U[i],V[i],W[i]);
    if(U[i]>V[i]) swap(U[i],V[i]);
    val[U[i]].insert({W[i],i});
    val[V[i]].insert({W[i],i}); 
		edges[{U[i],V[i]}]=i;
  }
  rep(i,1,n) push(i);
  out(cal());
  int q;sc(q);
  while(q--)
  {
    int op,u,v,w;
    sc(op,u,v);
    if(u>v) swap(u,v);
    if(op==1) sc(w);
    if(op==0)
    {
      pop(u);pop(v);
			int id=edges[{u, v}];
			val[u].erase({W[id],id});
      val[v].erase({W[id],id});
			edges[{u,v}]=0;
			push(u);push(v);
    }
    else
    {
      m++;U[m]=u;V[m]=v;W[m]=w;
      pop(U[m]);pop(V[m]);
			val[U[m]].insert({W[m],m});
      val[V[m]].insert({W[m],m});
			edges[{U[m],V[m]}]=m;
			push(U[m]);push(V[m]);
    }
    out(cal());
  }
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
  return 0;
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/