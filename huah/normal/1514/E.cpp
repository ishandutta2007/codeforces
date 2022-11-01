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
const int N=1e2+5;
int n,a[N];
bool vis[N][N],g[N][N];
void SetGraph()
{
  g[0][2]=true;
  g[0][3]=true;
  g[1][0]=true;
  g[1][3]=true;
  g[2][1]=true;
  g[2][3]=true;
}
bool query(int x,int y)
{
  printf("1 %d %d\n",x,y);
  fflush(stdout);
  // return g[x][y];
  int ans;scanf("%d",&ans);
  return ans==1;
}
bool query2(int x,int y)
{
  printf("2 %d %d",a[y],x+1);
  for(int i=0;i<=x;i++) printf(" %d",a[i]);
  printf("\n");
  // for(int i=0;i<=x;i++) if(g[a[y]][a[i]]) return true;
  // return false;
  fflush(stdout);
  int ans;scanf("%d",&ans);
  return ans==1;
}
bool cmp(int x,int y)
{
  return query(x,y);
}
void sol(int cas)
{
  // SetGraph();
  sc(n);
  rep(i,0,n-1) a[i]=i;
  stable_sort(a,a+n,cmp);
  rep(i,0,n-1) rep(j,0,n-1) vis[i][j]=false;
  rep(i,0,n-1) vis[i][i]=true;
  rep(i,0,n-2) vis[a[i]][a[i+1]]=true;
  for(int i=n-1,j=i-1;i>=0;i--)
  {
    while(j>=i||j>=0&&query2(j,i)) j--;
    vis[a[i]][a[j+1]]=true;
  }
  rep(k,0,n-1)
    rep(i,0,n-1)
      rep(j,0,n-1)
      vis[i][j]|=vis[i][k]&vis[k][j];
  printf("3\n");
  rep(i,0,n-1)
    rep(j,0,n-1)
    printf(j==n-1?"%d\n":"%d",vis[i][j]);
  fflush(stdout);
  int ans;scanf("%d",&ans);
  if(ans==-1) exit(0);
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