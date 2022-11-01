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
const int N=4e5+5,mod=1e9+7;
int n,a[N];
ll sum[N],bit[N],b2[N];
void add(int x,int v)
{
  while(x<=300000) bit[x]+=v,x+=x&-x;
}
void add2(int x)
{
  x=300000-x+1;
  while(x<=300000) b2[x]++,x+=x&-x;
}
ll query2(int x)
{
  x=300000-x+1;
  ll ans=0;
  while(x) ans+=b2[x],x-=x&-x;
  return ans;
}
ll query(int x)
{
  ll ans=0;
  while(x) ans+=bit[x],x-=x&-x;
  return ans;
}
void sol(int cas)
{
  sc(n);
  rep(i,1,n) sc(a[i]),sum[i]=sum[i-1]+a[i];
  ll pre=0;
  rep(i,1,n)
  {
    ll ans=sum[i-1]+1ll*a[i]*(i-1);
    ans-=query(a[i]);
    for(int j=a[i];j<=300000;j+=a[i])
    {
      add(j,a[i]);
      ans-=query2(j)*a[i];
    }
    add2(a[i]);
    ans+=pre;
    pre=ans;
    printf(i==n?"%lld\n":"%lld ",ans);
  }
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