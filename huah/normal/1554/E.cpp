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
const int N=2e5+5,mod=998244353;
int n,ans[N],a[N];
vector<int>e[N];
bool dfs(int u,int p,int g)
{
  a[u]=0;
  for(int v:e[u])
  if(v!=p)
  {
    if(!dfs(v,u,g)) return false;
  }
  if(a[u]%g==0) a[p]++;
  else if((a[u]+1)%g==0) a[u]++;
  else return false;
  return true;
}
void sol(int cas)
{
  sc(n);
  rep(i,1,n) e[i].clear();
  rep(i,1,n-1)
  {
    int u,v;sc(u,v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  ans[1]=1;
  rep(i,1,n-1) ans[1]=(ans[1]<<1)%mod;
  ans[n]=0;
  rep(i,2,n-1)
  if((n-1)%i==0) ans[i]=dfs(1,0,i);
  else ans[i]=0;
  for(int i=n;i>=1;i--)
    for(int j=i+i;j<=n-1;j+=i)
    ans[i]=(ans[i]-ans[j]+mod)%mod;
  rep(i,1,n) printf(i==n?"%d\n":"%d ",ans[i]);
}
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("2.out", "w", stdout);
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