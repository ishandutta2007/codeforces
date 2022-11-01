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
const int N=505;
#define inf 0x3f3f3f3f
int n,m,k,a[N][N],b[N][N];
int dp[N][N][21];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int cost(int x1,int y1,int x2,int y2)
{
  if(x1==x2) return a[x1][min(y1,y2)];
  return b[min(x1,x2)][y2];
}
void update(int &x,int y){x=min(x,y);}
void sol(int cas)
{
  sc(n,m,k);
  rep(i,1,n)
    rep(j,1,m-1) sc(a[i][j]);
  rep(i,1,n-1)
    rep(j,1,m) sc(b[i][j]);
  if(k&1)
  {
    rep(i,1,n) rep(j,1,m) printf(j==n?"%d\n":"%d ",-1);
    return;
  }
  memset(dp,inf,sizeof(dp));
  rep(i,1,n) rep(j,1,m) dp[i][j][0]=0;
  k/=2;
  rep(s,1,k)
  {
    rep(i,1,n)
      rep(j,1,m)
    {
      rep(t,0,3)
      {
        int x=i+dx[t];
        int y=j+dy[t];
        if(x<0||x>n||y<0||y>m) continue;
        update(dp[i][j][s],dp[x][y][s-1]+cost(i,j,x,y));
      }
    }
  }
  rep(i,1,n)rep(j,1,m) printf(j==n?"%d\n":"%d ",dp[i][j][k]*2);
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
re Alaysis new problem
*/