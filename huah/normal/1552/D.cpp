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
const int N=205,mod=998244353;
int n,a[N],b[N];
bool gg;
void dfs(int u,int sum,int e)
{
  if(gg||sum==e)
  {
    gg=true;return;
  }
  if(u==n) return;
  dfs(u+1,sum,e);
  dfs(u+1,sum+b[u],e);
  dfs(u+1,sum-b[u],e);
}
void sol(int cas)
{
  sc(n);
  rep(i,1,n) sc(a[i]),a[i]=abs(a[i]);
  sort(a+1,a+1+n);
  if(a[1]==0)
  {
    printf("YES\n");
    return;
  }
  rep(i,1,n-1)
  if(a[i]==a[i+1])
  {
    printf("YES\n");
    return;
  }
  for(int i=1;i<=n;i++)
  {
    int tot=0;
    for(int j=1;j<=n;j++)
      if(j!=i) b[++tot]=a[j];
    gg=false;
    dfs(1,0,a[i]);
    if(gg)
    {
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
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