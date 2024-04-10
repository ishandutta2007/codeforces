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
int n,q;
ll a[N],b[N];
ll mn[N<<2],mx[N<<2];
void build(int l,int r,int k)
{
  if(l==r)
  {
    mn[k]=mx[k]=a[l];
    return;
  }
  int m=(l+r)>>1;
  build(l,m,k<<1);build(m+1,r,k<<1|1);
  mn[k]=min(mn[k<<1],mn[k<<1|1]);
  mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
ll qmn(int l,int r,int k,int x,int y)
{
  if(l>=x&r<=y) return mn[k];
  int m=(l+r)>>1;
  if(x<=m&&y>m) return min(qmn(l,m,k<<1,x,y),qmn(m+1,r,k<<1|1,x,y));
  else if(x<=m) return qmn(l,m,k<<1,x,y);
  return qmn(m+1,r,k<<1|1,x,y);
}
ll qmx(int l,int r,int k,int x,int y)
{
  if(l>=x&&r<=y) return mx[k];
  int m=(l+r)>>1;
  if(x<=m&&y>m) return max(qmx(l,m,k<<1,x,y),qmx(m+1,r,k<<1|1,x,y));
  else if(x<=m) return qmx(l,m,k<<1,x,y);
  return qmx(m+1,r,k<<1|1,x,y);
}
void sol(int cas)
{
  sc(n,q);
  rep(i,1,n) sc(a[i]);
  rep(i,1,n) sc(b[i]),a[i]-=b[i];
  rep(i,1,n) a[i]+=a[i-1];
  build(1,n,1);
  while(q--)
  {
    int l,r;sc(l,r);
    ll mn=qmn(1,n,1,l,r);
    ll mx=qmx(1,n,1,l,r);
    mx-=a[l-1];
    mn-=a[l-1];
    if(mx==0&&a[r]-a[l-1]==0) printf("%lld\n",-mn);
    else printf("-1\n");
  }
}
int main()
{
  // freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
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