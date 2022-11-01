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
void iary(int *a,int l,int r){rep(i,l,r)sc(a[i]);}
void iary(ll *a,int l,int r){rep(i,l,r)sc(a[i]);}
void oary(int *a,int l,int r){rep(i,l,r)printf(i==r?"%d\n":"%d ",a[i]);}
void oary(ll *a,int l,int r){rep(i,l,r)printf(i==r?"%lld\n":"%lld ",a[i]);}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
#define inf 0x3f3f3f3f
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=2e5+5,mod=998244353;
int n,k,a[N],ans[N];
vector<int>e[N];
int dp[N][20][2];
void update(int u,int v)
{
  for(int i=0;i<k;i++)
    for(int j=0;j<=1;j++)
    {
      if(i<k-1) dp[u][i+1][j]^=dp[v][i][j];
      else dp[u][0][j^1]^=dp[v][i][j];
    }
}
void dfs1(int u,int p)
{
  dp[u][0][0]=a[u];
  for(int v:e[u])
    if(v!=p)
    {
      dfs1(v,u);
      update(u,v);
    }
}
void dfs2(int u,int p)
{
  for(int i=0;i<k;i++)
    ans[u]^=dp[u][i][1];
  ans[u]=ans[u]!=0;
  for(int v:e[u])
  if(v!=p)
  {
    update(u,v);
    update(v,u);
    dfs2(v,u);
    update(v,u);
    update(u,v);
  }
}
void sol(int cas)
{
  sc(n,k);
  rep(i,1,n-1)
  {
    int u,v;sc(u,v);e[u].push_back(v);e[v].push_back(u);
  }
  rep(i,1,n) sc(a[i]);
  dfs1(1,0);
  dfs2(1,0);
  oary(ans,1,n);
}
int main()
{
  // freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
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