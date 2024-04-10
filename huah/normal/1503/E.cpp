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
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=10005,mod=998244353;
int n,m;
ll f[N],inv[N],invf[N];
ll sum[3005][3005],g[3005][3005];
ll C(int n,int m){return f[n]*invf[m]%mod*invf[n-m]%mod;}
ll pre[N];
ll cal(int n,int m,int op)
{
  rep(l,1,m-1)
    rep(d,1,n)
      g[l][d]=sum[l][d-1]*C(n-d+l-1,l-1)%mod;
  ll ans=0;
  rep(l,1,m-1)
  {
    rep(i,1,n) pre[i]=(pre[i-1]+g[m-l][i])%mod;
    rep(i,1,n-1-op)
      ans=(ans+g[l][i]*pre[n-op-i]%mod)%mod;
  }
  ans=(ans<<1)%mod;
  return ans;
}
void sol(int cas)
{
  f[0]=f[1]=inv[1]=invf[0]=invf[1]=1;
  rep(i,2,N-1)
  {
    f[i]=f[i-1]*i%mod;
    inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    invf[i]=invf[i-1]*inv[i]%mod;
  }
  sc(n,m);
  for(int k=1;k<=max(n,m);k++)
  {
    sum[k][0]=1;
    rep(d,1,max(n,m))
      sum[k][d]=(sum[k][d-1]+C(d+k-1,k-1))%mod;
  }
  ll ans=(cal(n,m,0)+cal(m,n,1))%mod;
  out(ans);
}
int main()
{
//   freopen("1.in", "r",stdin);
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