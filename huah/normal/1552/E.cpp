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
const int N=2e4+5,mod=998244353;
int n,k,a[N],pre[N],t[N<<2],lz[N<<2];
void update(int l,int r,int k)
{
  t[k]+=lz[k];
  if(l!=r)
    lz[k<<1]+=lz[k],lz[k<<1|1]+=lz[k];
  lz[k]=0;
}
void ins(int l,int r,int k,int x,int y)
{
  if(lz[k]) update(l,r,k);
  if(r<x||l>y) return;
  if(l>=x&&r<=y)
  {
    lz[k]++;update(l,r,k);return;
  }
  int m=(l+r)>>1;
  ins(l,m,k<<1,x,y);
  ins(m+1,r,k<<1|1,x,y);
  t[k]=max(t[k<<1],t[k<<1|1]);
}
int query(int l,int r,int k,int x,int y)
{
  if(lz[k]) update(l,r,k);
  if(r<x||l>y) return 0;
  if(l>=x&&r<=y) return t[k];
  int m=(l+r)>>1;
  return max(query(l,m,k<<1,x,y),query(m+1,r,k<<1|1,x,y));
}
pair<int,int>ans[N];
bool vis[N];
void sol(int cas)
{
  sc(n,k);
  rep(i,1,n*k) sc(a[i]);
  int up=n/(k-1)+(n%(k-1)!=0);
  for(int i=1;i<=n*k;i++)
  {
    if(pre[a[i]]&&query(1,n*k,1,pre[a[i]],i)<up&&!vis[a[i]])
    {
      vis[a[i]]=true;
      ans[a[i]]={pre[a[i]],i};
      ins(1,n*k,1,pre[a[i]],i);
    }
    pre[a[i]]=i;
  }
  rep(i,1,n) assert(vis[i]);
  rep(i,1,n) printf("%d %d\n",ans[i].first,ans[i].second);
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