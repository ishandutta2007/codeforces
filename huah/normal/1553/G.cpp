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
const int N=3e6+5,mod=1e9+7;
int n,q,a[N],tot,p[N],f[N],id[N];
vector<int>fac[N];
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
map<pair<int,int>,bool>vis;
void sol(int cas)
{
  for(int i=2;i<=1000001;i++)
    if(!fac[i].size())
    {
      p[++tot]=i;id[i]=tot;
      for(int j=i;j<=1000001;j+=i)
        fac[j].push_back(i);
    }
  sc(n,q);
  rep(i,1,n) sc(a[i]);
  rep(i,1,n+tot) f[i]=i;
  rep(i,1,n)
    for(int x:fac[a[i]])
      f[getf(tot+i)]=getf(id[x]);
  rep(i,1,n)
  {
    int x=getf(tot+i);
    vector<int>vc;
    vc.push_back(x);
    for(int y:fac[a[i]+1])
    {
      int g=getf(id[y]);
      if(g!=x) vc.push_back(g);
    }
    for(int x:vc)
      for(int y:vc) 
      vis[{x,y}]=true;
  }
  rep(qs,1,q)
  {
    int x,y;sc(x,y);
    if(getf(x+tot)==getf(y+tot)) out(0);
    else if(vis.count({getf(x+tot),getf(y+tot)})) out(1);
    else out(2);
  }
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