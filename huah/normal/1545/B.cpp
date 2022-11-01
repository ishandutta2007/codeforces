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
using namespace std;
const int N = 5e5 + 5, mod = 998244353;
int n;
ll f[N],invf[N];
char s[N];
ll C(int n,int m)
{
  return f[n]*invf[n-m]%mod*invf[m]%mod;
}
void sol(int cas)
{
  sc(n);
  sc(s+1);
  int a=0,b=0;
  rep(i,1,n) a+=s[i]=='0';
  rep(i,1,n-1)
  if(s[i]=='1'&&s[i+1]=='1')
  {
    b++;i++;
  }
  printf("%lld\n",C(a+b,a));
}
int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);
  f[0]=f[1]=invf[0]=invf[1]=1;
  rep(i,2,N-1) f[i]=f[i-1]*i%mod,invf[i]=(mod-mod/i)*invf[mod%i]%mod;
  rep(i,2,N-1) invf[i]=invf[i-1]*invf[i]%mod;
  int t,cas=0;scanf("%d",&t);
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