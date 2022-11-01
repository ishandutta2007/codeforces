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
const int N=2e5+5,mod=998244353;
int n,a[N],f[N];
int t[N<<2],lz[N<<2];
void build(int l,int r,int k)
{
    t[k]=-inf;lz[k]=0;
    if(l==r) return;
    int m=(l+r)>>1;
    build(l,m,k<<1);build(m+1,r,k<<1|1);
}
void update(int l,int r,int k)
{
    if(l!=r)
    {
        t[k<<1]+=lz[k],t[k<<1|1]+=lz[k];
        lz[k<<1]+=lz[k],lz[k<<1|1]+=lz[k];
    }
    lz[k]=0;
}
void ins(int l,int r,int k,int x,int v)
{
    if(lz[k]) update(l,r,k);
    if(l==r){t[k]=v;return;}
    int m=(l+r)>>1;
    if(x<=m) ins(l,m,k<<1,x,v);
    else ins(m+1,r,k<<1|1,x,v);
    t[k]=max(t[k<<1],t[k<<1|1]);
}
void fix(int l,int r,int k,int x,int y,int v)
{
    if(lz[k]) update(l,r,k);
    if(r<x||l>y) return;
    if(l>=x&&r<=y)
    {
        t[k]+=v;
        lz[k]=v;
        update(l,r,k);
        return;
    }
    int m=(l+r)>>1;
    fix(l,m,k<<1,x,y,v);fix(m+1,r,k<<1|1,x,y,v);
    t[k]=max(t[k<<1],t[k<<1|1]);
}
int bit[N];
void add(int x,int v)
{
    while(x<=n) bit[x]+=v,x+=x&-x;
}
int query(int x)
{
    int ans=0;
    while(x) ans+=bit[x],x-=x&-x;
    return ans;
}
bool vis[N];
void sol(int cas)
{
    sc(n);
    rep(i,1,n) sc(a[i]),f[a[i]]=i,bit[i]=i&-i,vis[i]=false;
    build(1,n,1);
    int ans=0,zeros=0,pre=0;
    rep(i,1,n)
    {
        vis[f[i]]=true;
        zeros++;
        if(f[i]<n) fix(1,n,1,f[i]+1,n,-2);
        int ones=query(f[i]-1);
        ins(1,n,1,f[i],(f[i]&1)+ones-(f[i]-ones));
        add(f[i],-1);
        while(pre<n&&vis[pre+1])
        {
            pre++;
            ins(1,n,1,pre,-inf);
        }
        ans=max(ans,t[1]+zeros);
    }
    out(ans);
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
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