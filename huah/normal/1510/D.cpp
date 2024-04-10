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
const int N=5e5+5,mod=998244353;
int n,d,a[N],pre[N][10];
double dp[N][10];
bool choose[N][10];
void sol(int cas)
{
  sc(n,d);
  rep(i,1,n) sc(a[i]);
  rep(i,0,n)
    rep(j,0,9) dp[i][j]=-1e9;
  dp[0][1]=0;
  rep(i,0,n-1)
    rep(j,0,9)
    {
      if(dp[i+1][j*a[i+1]%10]<dp[i][j]+log2(a[i+1]))
      {
        dp[i+1][j*a[i+1]%10]=dp[i][j]+log2(a[i+1]);
        pre[i+1][j*a[i+1]%10]=j;
        choose[i+1][j*a[i+1]%10]=true;
      }
      if(dp[i+1][j]<dp[i][j])
      {
        dp[i+1][j]=dp[i][j];
        pre[i+1][j]=j;
        choose[i+1][j]=false;
      }
    }
  if(dp[n][d]<0){out(-1);return;}
  vector<int>ans;
  for(int i=n,j=d;i>=1;i--)
  {
    if(choose[i][j]) ans.push_back(a[i]);
    j=pre[i][j];
  }
  if(ans.size()==0){out(-1);return;}
  printf("%d\n",int(ans.size()));
  for(int i=0;i<ans.size();i++)
    printf(i==ans.size()?"%d\n":"%d ",ans[i]);
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