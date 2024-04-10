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
const int N=2e5+5,mod=1e9+7;
int n,invf[N],a[N],f[N];
int C(int n,int m)
{
  return 1ll*f[n]*invf[m]%mod*invf[n-m]%mod;
}
void sol(int cas)
{
  sc(n);
  ll sum=0;
  rep(i,1,n) sc(a[i]),sum+=a[i];
  if(sum%n)
  {
    out(0);return;
  }
  sum/=n;
  rep(i,1,n) a[i]-=sum;
  int x=0,y=0;
  rep(i,1,n)
    if(a[i]<0) x++;
    else if(a[i]>0) y++;
  ll ans;
  if(x<=1||y<=1) ans=f[n];
  else ans=1ll*f[x]*f[y]%mod*2%mod*C(n,x+y)%mod*f[n-x-y]%mod;
  sort(a+1,a+1+n);
  int t=1;
  rep(i,2,n)
  {
    if(a[i]!=a[i-1]) ans=ans*invf[t]%mod,t=1;
    else t++;
  }
  ans=ans*invf[t]%mod;
  out(ans);
}
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  f[0]=f[1]=invf[0]=invf[1]=1;
  rep(i,2,N-1) f[i]=1ll*f[i-1]*i%mod,invf[i]=1ll*(mod-mod/i)*invf[mod%i]%mod;
  rep(i,2,N-1) invf[i]=1ll*invf[i-1]*invf[i]%mod;
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