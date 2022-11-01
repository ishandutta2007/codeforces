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
int n,p,b[N],a[N],f[N];
bool cmp(int &x,int &y){return a[x]<a[y];}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
void sol(int cas)
{
  sc(n,p);
  rep(i,1,n) sc(a[i]),b[i]=i,f[i]=i;
  sort(b+1,b+1+n,cmp);
  ll ans=0;
  rep(i,1,n)
  {
    int x=b[i];
    if(a[x]>=p) break;
    int l=x,r=x;
    while(l-1>=1&&a[l-1]%a[x]==0&&getf(l-1)!=getf(x))
    {
      l--;
      ans+=a[x];
      f[getf(l)]=getf(x);
    }
    while(r+1<=n&&a[r+1]%a[x]==0&&getf(r+1)!=getf(x))
    {
      r++;
      ans+=a[x];
      f[getf(r)]=getf(x);
    }
  }
  int sum=0;
  rep(i,1,n) if(f[i]==i) sum++;
  out(ans+1ll*(sum-1)*p);
}
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
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
*/