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
const int N=25,mod=31607;
int n,a[N][N],inv[mod+1];
short p[N][1<<23];
int lg[1<<23];
int qpow(int a,int n)
{
  int ans=1;
  for(;n;n>>=1,a=a*a%mod)
  if(n&1) ans=ans*a%mod;
  return ans;
}
void fwt_and(short *f,int opt,int n)
{
    for(int l=2,k=1;l<=n;l<<=1,k<<=1)
        for(int i=0;i<n;i+=l)
        for(int j=0;j<k;j++)
        f[i+j]=(f[i+j]+f[i+j+k]*opt)%mod;
}
void sol(int cas)
{
  sc(n);
  rep(i,1,n)
    rep(j,1,n)
    sc(a[i][j]),a[i][j]=a[i][j]*inv[10000]%mod;
  int up=1<<(n+2);
  for(int i=1;i<up;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
  rep(i,1,n)
  {
    int s=1<<n;
    p[i][0]=1;
    for(int j=1;j<=n;j++)
      p[i][0]=p[i][0]*(mod+1-a[i][j])%mod;
    for(int j=1;j<s-1;j++)
      p[i][j]=p[i][j^(j&-j)]*inv[(mod+1-a[i][lg[j&-j]])%mod]%mod*a[i][lg[j&-j]]%mod;
    for(int j=1;j<s;j++)
    {
      int t=j;
      if(j>>(i-1)&1)
        t|=1<<n;
      if(j>>(n-i)&1)
        t|=1<<(n+1);
      if(t!=j) swap(p[i][j],p[i][t]);
    }
    fwt_and(p[i],1,up);
    if(i>=2)
       rep(j,0,up-1) p[i][j]=1ll*p[i][j]*p[i-1][j]%mod;
  }
  fwt_and(p[n],mod-1,up);
  printf("%d\n",(mod+1-p[n][0])%mod);
}
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  inv[1]=1;
  rep(i,2,mod-1) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
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