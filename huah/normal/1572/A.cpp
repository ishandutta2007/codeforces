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
vector<int>e[N];
int n,d[N],ans[N];
void sol(int cas)
{
  sc(n);
  rep(i,1,n) e[i].clear();
  rep(i,1,n)
  {
    sc(d[i]);
    rep(j,1,d[i])
    {
      int x;sc(x);
      e[x].push_back(i);
    }
  }
  queue<int>q;
  rep(i,1,n) ans[i]=1;
  rep(i,1,n)
    if(d[i]==0) q.push(i);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for(int v:e[u])
    {
      d[v]--;
      if(d[v]==0) q.push(v);
      ans[v]=max(ans[v],ans[u]+(v<u));
    }
  }
  rep(i,1,n) if(d[i]){out(-1);return;}
  int res=0;
  rep(i,1,n) res=max(res,ans[i]);
  out(res);
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
  return 0;
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/