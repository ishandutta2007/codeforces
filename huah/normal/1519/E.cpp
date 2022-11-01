#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
// typedef __int128 ll;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
// void sc(ll &x) { scanf("%lld", &x); }
// void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
// void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
// void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
// void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
const int N=4e5+5;
int n,m;
pair<ll,ll>f1[N],f2[N];
map<pair<ll,ll>,int>id;
vector<pair<int,int>>e[N],ans;
bool vis[N],del[N];
/*
c*b/(a*d)
(c+d)*b/(a*d)
c*b/((a+b)*d)
*/
bool dfs(int u,int p)
{
  vis[u]=true;
  int pre=0;
  for(pair<int,int>x:e[u])
  if(!vis[x.first])
  {
    if(dfs(x.first,x.second))
    {
      del[x.second]=true;
      if(pre) ans.push_back({pre,x.second}),pre=0;
      else pre=x.second;
    }
  }
  else if(!del[x.second]&&x.second!=p)
  {
    del[x.second]=true;
    if(pre) ans.push_back({pre,x.second}),pre=0;
    else pre=x.second;
  }
  if(pre&&p)
  {
    ans.push_back({pre,p});
    return false;
  }
  return true;
}
ll gcd(ll x,ll y)
{
  if(y==0) return x;
  return gcd(y,x%y);
}
void sol(int cas)
{
  sc(n);
  m=0;id.clear();
  rep(i,1,n)
  {
    int a,b,c,d;
    sc(a,b);sc(c,d);
    ll x=1ll*(a+b)*d,y=1ll*c*b;
    ll g=gcd(x,y);
    x/=g;y/=g;
    f1[i]={x,y};
    x=1ll*a*d;y=1ll*(c+d)*b;
    g=gcd(x,y);
    x/=g;y/=g;
    f2[i]={x,y};
    if(!id[f1[i]]) id[f1[i]]=++m;
    if(!id[f2[i]]) id[f2[i]]=++m;
  }
  rep(i,1,m) e[i].clear();
  rep(i,1,n)
  {
    e[id[f1[i]]].push_back({id[f2[i]],i});
    e[id[f2[i]]].push_back({id[f1[i]],i});
  }
  ans.clear();
  rep(i,1,m) if(!vis[i]) dfs(i,0);
  printf("%d\n",int(ans.size()));
  for(pair<int,int>x:ans)
    printf("%d %d\n",x.first,x.second);
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
*/