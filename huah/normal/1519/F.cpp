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
const int N=7;
int n,m,a[N],b[N],cost[N][N];
int dp[7][5][5][5][5][5][5][5];
void update(int &x,int y)
{
  x=min(x,y);
}
void sol(int cas)
{
  sc(n,m);
  rep(i,1,n) sc(a[i]);
  rep(i,1,m) sc(b[i]);
  rep(i,1,n) rep(j,1,m) sc(cost[i][j]);
  memset(dp,inf,sizeof(dp));
  dp[1][a[1]][b[1]][b[2]][b[3]][b[4]][b[5]][b[6]]=0;
  for(int i=1;i<=n;i++)
    for(int j=a[i];j>=0;j--)
    {
      for(int t1=0;t1<=b[1];t1++)
        for(int t2=0;t2<=b[2];t2++)
          for(int t3=0;t3<=b[3];t3++)
            for(int t4=0;t4<=b[4];t4++)
            for(int t5=0;t5<=b[5];t5++)
            for(int t6=0;t6<=b[6];t6++)
            {
              if(j==0&&i<n)
                update(dp[i+1][a[i+1]][t1][t2][t3][t4][t5][t6],dp[i][j][t1][t2][t3][t4][t5][t6]);
              for(int k=1;k<=j;k++)
              {
                if(t1>=k)
                  update(dp[i][j-k][t1-k][t2][t3][t4][t5][t6],dp[i][j][t1][t2][t3][t4][t5][t6]+cost[i][1]);
                if(t2>=k)
                  update(dp[i][j-k][t1][t2-k][t3][t4][t5][t6],dp[i][j][t1][t2][t3][t4][t5][t6]+cost[i][2]);
                if(t3>=k)
                  update(dp[i][j-k][t1][t2][t3-k][t4][t5][t6],dp[i][j][t1][t2][t3][t4][t5][t6]+cost[i][3]);
                if(t4>=k)
                  update(dp[i][j-k][t1][t2][t3][t4-k][t5][t6],dp[i][j][t1][t2][t3][t4][t5][t6]+cost[i][4]);
                if(t5>=k)
                  update(dp[i][j-k][t1][t2][t3][t4][t5-k][t6],dp[i][j][t1][t2][t3][t4][t5][t6]+cost[i][5]);
                if(t6>=k)
                  update(dp[i][j-k][t1][t2][t3][t4][t5][t6-k],dp[i][j][t1][t2][t3][t4][t5][t6]+cost[i][6]);
              }
            }
    }
  int ans=inf;
  for(int t1=0;t1<=b[1];t1++)
    for(int t2=0;t2<=b[2];t2++)
      for(int t3=0;t3<=b[3];t3++)
        for(int t4=0;t4<=b[4];t4++)
          for(int t5=0;t5<=b[5];t5++)
            for(int t6=0;t6<=b[6];t6++)
            ans=min(ans,dp[n][0][t1][t2][t3][t4][t5][t6]);
  if(ans==inf) ans=-1;
  out(ans);
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