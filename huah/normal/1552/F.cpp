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
const int N=4e5+5,mod=998244353;
int n,x[N],y[N],a[N],s[N];
ll bit[N],b[N];
void add(int x,ll v)
{
  while(x<=n)
    bit[x]=(bit[x]+v)%mod,x+=x&-x;
}
ll query(int x)
{
  ll ans=0;
  while(x) ans=(ans+bit[x])%mod,x-=x&-x;
  return ans;
}
void sol(int cas)
{
  sc(n);
  rep(i,1,n) sc(x[i],y[i],s[i]);
  rep(i,1,n)
  {
    int pos=lower_bound(x+1,x+1+n,y[i])-x;
    a[i]=pos;
  }
  ll ans=0;
  nep(i,n,1)
  {
    if(s[i]) b[i]=(b[i]+1)%mod;
    b[i]=(b[i]+query(i))%mod;
    add(a[i],b[i]);
    ans=(ans+b[i]*(x[i]-y[i])%mod)%mod;
  }
  ans=(ans+x[n]+1)%mod;
  out(ans);
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