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
const int N=3e6+5,mod=1e9+7;
int n,q;
ll dp[N][3];
ll f[N],inv[N],invf[N];
ll C(int n,int m)
{
  return f[n]*invf[m]%mod*invf[n-m]%mod;
}
void sol(int cas)
{
  sc(n,q);
  dp[0][0]=dp[0][1]=dp[0][2]=n;
  rep(x,1,3*n)
  {
    dp[x][0]=(C(3*n,x+1)-2*dp[x-1][0]-dp[x-1][1])%mod*inv[3]%mod;
    dp[x][0]=(dp[x][0]+mod)%mod;
    dp[x][1]=(dp[x-1][0]+dp[x][0])%mod;
    dp[x][2]=(dp[x-1][1]+dp[x][1])%mod;
  }
  while(q--)
  {
    int x;sc(x);
    out((dp[x][0]+C(3*n,x))%mod);
  }
}
int main() 
{
  f[0]=f[1]=invf[0]=invf[1]=inv[1]=1;
  rep(i,2,N-1)
  {
    f[i]=f[i-1]*i%mod;
    inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    invf[i]=invf[i-1]*inv[i]%mod;
  }
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