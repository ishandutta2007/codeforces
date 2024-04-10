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
const int N=5e2+5,mod=1e9+7;
int n,a[N],vis[N][N];
int tot,curnum;
void dfs(int x,int y)
{
  if(!tot) return;
  vis[x][y]=curnum;
  tot--;
  if(!tot) return;
  if(x-1>=1&&y<=x-1&&!vis[x-1][y]) dfs(x-1,y);
  if(y-1>=1&&!vis[x][y-1]) dfs(x,y-1);
  if(!vis[x+1][y]) dfs(x+1,y);
  if(y+1<=x&&!vis[x][y+1]) dfs(x,y+1);
}
void sol(int cas)
{
  sc(n);
  rep(i,1,n) sc(a[i]);
  rep(i,1,n)
  {
    tot=a[i];
    curnum=a[i];
    dfs(i,i);
  }
  rep(i,1,n)rep(j,1,i)printf(j==i?"%d\n":"%d ",vis[i][j]);
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
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/