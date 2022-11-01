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
int n,k,s,d,a[N],dis[N];
set<int>st[N<<2];
int t[N<<2],lz1[N<<2],lz2[N<<2],lz3[N<<2];
void build(int l,int r,int k)
{
  t[k]=lz1[k]=lz2[k]=lz3[k]=inf;
  for(int i=l;i<=r;i++) st[k].insert(a[i]);
  if(l==r) return;
  int m=(l+r)>>1;
  build(l,m,k<<1);build(m+1,r,k<<1|1);
}
void update(int l,int r,int k)
{
  if(st[k].empty())
  {
    lz1[k]=lz2[k]=lz3[k]=t[k]=inf;
    return;
  }
  t[k]=min(min(lz3[k],t[k]),min(lz1[k]-(*(--st[k].end())),lz2[k]+(*st[k].begin())));
  if(l!=r)
  {
    lz1[k<<1]=min(lz1[k<<1],lz1[k]),lz1[k<<1|1]=min(lz1[k<<1|1],lz1[k]);
    lz2[k<<1]=min(lz2[k<<1],lz2[k]),lz2[k<<1|1]=min(lz2[k<<1|1],lz2[k]);
    lz3[k<<1]=min(lz3[k<<1],lz3[k]),lz3[k<<1|1]=min(lz3[k<<1|1],lz3[k]);
  }
}
void ins1(int l,int r,int k,int x,int y,int s1,int s2)
{
  update(l,r,k);
  if(r<x||l>y) return;
  if(l>=x&&r<=y&&s1-a[r]>=s2)
  {
    lz1[k]=min(lz1[k],s1);
    update(l,r,k);
    return;
  }
  if(l>=x&&r<=y&&s1-a[l]<=s2)
  {
    lz3[k]=min(lz3[k],s2);
    update(l,r,k);
    return;
  }
  int m=(l+r)>>1;
  ins1(l,m,k<<1,x,y,s1,s2);
  ins1(m+1,r,k<<1|1,x,y,s1,s2);
  t[k]=min(t[k<<1],t[k<<1|1]);
}
void ins2(int l,int r,int k,int x,int y,int s1,int s2)
{
  update(l,r,k);
  if(r<x||l>y) return;
  if(l>=x&&r<=y&&s2+a[l]>=s1)
  {
    lz2[k]=min(lz2[k],s2);
    update(l,r,k);
    return;
  }
  if(l>=x&&r<=y&&s2+a[r]<=s1)
  {
    lz3[k]=min(lz3[k],s1);
    update(l,r,k);
    return;
  }
  int m=(l+r)>>1;
  ins2(l,m,k<<1,x,y,s1,s2);
  ins2(m+1,r,k<<1|1,x,y,s1,s2);
  t[k]=min(t[k<<1],t[k<<1|1]);
}
void del(int l,int r,int k,int x)
{
  if(l==r)
  {
    st[k].clear();
    update(l,r,k);
    return;
  }
  int m=(l+r)>>1;
  if(x<=m) del(l,m,k<<1,x);
  else del(m+1,r,k<<1|1,x);
  st[k].erase(a[x]);
  t[k]=min(t[k<<1],t[k<<1|1]);
  update(l,r,k);
}
int query(int l,int r,int k)
{
  if(l==r)
  {
    dis[l]=t[k];
    return l;
  }
  int m=(l+r)>>1;
  update(l,m,k<<1);update(m+1,r,k<<1|1);
  t[k]=min(t[k<<1],t[k<<1|1]);
  if(t[k<<1]<=t[k<<1|1]) return query(l,m,k<<1);
  return query(m+1,r,k<<1|1);
}
int query(int l,int r,int k,int x)
{
  if(l==r) return t[k];
  int m=(l+r)>>1;
  update(l,m,k<<1);update(m+1,r,k<<1|1);
  t[k]=min(t[k<<1],t[k<<1|1]);
  if(x<=m) return query(l,m,k<<1,x);
  return query(m+1,r,k<<1|1,x);
}
/*
dp[j]=max(dp[i],abs(abs(a[i]-a[j])-d))
1.a[j]<=a[i]
abs(a[i]-a[j]-d):
  1.1 d<=a[i]-a[j]: a[i]-a[j]-d    xxx-a[j]  lz1
  1.2 d>a[i]-a[j]: d-a[i]+a[j]     xxx+a[j]  lz2
2.a[j]>a[i]
abs(a[j]-a[i]-d)
  2.1 d<=a[j]-a[i]: a[j]-a[i]-d    xxx+a[j]  lz2
  2.2 d>a[j]-a[i]: d-a[j]+a[i]     xxx-a[j]  lz1
*/
void update(int u)
{
  del(1,n,1,u);
  int pos=upper_bound(a+1,a+1+n,a[u]-d)-a;
  if(pos<u)
    ins2(1,n,1,pos,u-1,dis[u],d-a[u]);
  if(pos>1)
    ins1(1,n,1,1,pos-1,a[u]-d,dis[u]);
  pos=lower_bound(a+1,a+1+n,a[u]+d)-a;
  if(pos<=n)
    ins2(1,n,1,pos,n,dis[u],-a[u]-d);
  if(pos-1>u)
    ins1(1,n,1,u+1,pos-1,d+a[u],dis[u]);
}
void sol(int cas)
{
  sc(n,k);sc(s,d);
  rep(i,1,n) sc(a[i]);
  build(1,n,1);
  dis[s]=0;
  update(s);
  rep(i,2,n)
  {
    update(1,n,1);
    int u=query(1,n,1);
    update(u);
  }
  while(k--)
  {
    int i,s;sc(i,s);
    if(s>=dis[i]) printf("Yes\n");
    else printf("No\n");
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
re Alaysis new problem
what is the equal problem?
*/