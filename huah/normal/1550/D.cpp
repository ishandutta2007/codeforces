#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f3f3f3f3fll
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
const int N=5e5+5,mod=1e9+7;
ll n,l,r;
ll f[N],invf[N];
ll C(int n,int m){return f[n]*invf[m]%mod*invf[n-m]%mod;}
ll Cal(int n,int c)
{
  if(n<c) return 0;
  return C(n+1,c+1);
}
//C(n,m)=C(n-1,m-1)+C(n-1,m)=C(n-1,m-1)+C(n-2,m-1)+C(n-2,m)=C(n-1,m-1)+C(n-2,m-1)+....+C(m-1,m-1)
ll sol(int a,int b)
{
  ll ans=0;
  for(int i=1;i<=b+1;i++)
  {
    if(i<b+1)
    {
      ans=(ans+min(i-l,r-n)*C(n-i,b-i+1)%mod)%mod;
      if(i-l>r-n)
      {
        int t=(i-l)-(r-n),c=b-i+1;
        ans=(ans+Cal(n-i-1,c)+mod-Cal(n-i-t-1,c))%mod;
      }
    }
    else
      ans=(ans+min(i-l,r-(i-1)))%mod;
    //C(n-i-1,c)+C(n-i-2,c)+...+C(n-i-t,c)
  }
  return ans;
}
/*
[+,-,-]
[2,1,2]
[-,+,-]
[0,3,2]
[+,+,-]
[2,3,2]
[+,-,-]
[3,0,1]
*/
void sol(int cas)
{
  sc(n,l,r);
  ll ans=sol(n/2,n-n/2);
  if(n&1) ans=(ans+sol(n/2+1,n-(n/2+1)))%mod;
  out(ans); 
}
int main() {
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  f[0]=f[1]=invf[0]=invf[1]=1;
  rep(i,2,N-1) f[i]=f[i-1]*i%mod,invf[i]=(mod-mod/i)*invf[mod%i]%mod;
  rep(i,2,N-1) invf[i]=invf[i-1]*invf[i]%mod;
  srand(time(0));
  int t=1,cas=0;
  scanf("%d",&t);
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
what is the equal problem?
*/