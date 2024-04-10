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
const int N=3e6+5,mod=998244353;
int n,m;
struct node
{
  int l,r,w;
  bool operator<(const node&o)const
  {
    return w<o.w;
  }
}a[N];
int t[N<<2],g[N<<2];
void Insert(int l,int r,int k,int x,int y,int v)
{
  if(r<x||l>y) return;
  if(l>=x&&r<=y)
  {
    g[k]+=v;
    if(g[k]) t[k]=1;
    else t[k]=t[k<<1]&t[k<<1|1];
    return;
  }
  int m=(l+r)>>1;
  Insert(l,m,k<<1,x,y,v);Insert(m+1,r,k<<1|1,x,y,v);
  if(g[k]) t[k]=1;
  else t[k]=t[k<<1]&t[k<<1|1];
}
void sol(int cas)
{
  sc(n,m);
  rep(i,1,n) sc(a[i].l,a[i].r,a[i].w),a[i].r--;
  sort(a+1,a+1+n);
  int ans=998244353;
  for(int i=1,j=1;i<=n;i++)
  {
    while(j<=n&&!t[1])
    {
      Insert(1,m-1,1,a[j].l,a[j].r,1);
      j++;
    }
    if(t[1]) ans=min(ans,a[j-1].w-a[i].w);
    Insert(1,m-1,1,a[i].l,a[i].r,-1);
  }
  out(ans);
}
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("2.out", "w", stdout);
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