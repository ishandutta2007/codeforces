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
const int N=1e5+5,mod=1e9+7;
int n;
ll a[N],dp[N][450];
void update(ll &x,ll y){if(y>x)x=y;}
ll Sum(ll l,ll r){return a[r]-a[l-1];}
int main()
{
  // freopen("1.in","r",stdin);
  int t;sc(t);
  while(t--)
  {
    sc(n);
    rep(i,1,n) sc(a[i]),a[i]+=a[i-1];
    int up=0,sum=0;
    while(sum+up+1<=n) up++,sum+=up;
    rep(i,1,n)
      rep(j,0,up) dp[i][j]=0;
    rep(i,1,n) dp[i][1]=a[i]-a[i-1];
    int ans=1;
    nep(i,n,1)
      rep(j,0,up)
      if(dp[i][j])
    {
      ans=max(ans,j);
      update(dp[i-1][j],dp[i][j]);
      if(i-j-1>=1&&Sum(i-j-1,i-1)<dp[i][j])
        update(dp[i-j-1][j+1],Sum(i-j-1,i-1));
    }
    out(ans);
  }
}
/*
dp[i][k]=dp[i+k][k-1]<=sum[i+k-1]-sum[i-1]
*/
/*
befor submit code check:
freopen
size of N
mod
debug output
*/