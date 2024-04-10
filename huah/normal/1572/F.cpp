#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
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
#define inf 0x3f3f3f3f
const int N=3e5+5,mod=998244353;
int n,q;
ll b[N<<2],lz[N<<2];
void up(int l,int r,int k)
{
  b[k]+=1ll*lz[k]*(r-l+1);
  if(l!=r) lz[k<<1]+=lz[k],lz[k<<1|1]+=lz[k];
  lz[k]=0;
}
void ins(int l,int r,int k,int x,int y,int v)
{
  if(lz[k]) up(l,r,k);
  if(r<x||l>y) return;
  if(l>=x&&r<=y)
  {
    lz[k]+=v;
    up(l,r,k);
    return;
  }
  int m=(l+r)>>1;
  ins(l,m,k<<1,x,y,v);ins(m+1,r,k<<1|1,x,y,v);
  b[k]=b[k<<1]+b[k<<1|1];
}
ll query(int l,int r,int k,int x,int y)
{
  if(lz[k]) up(l,r,k);
  if(r<x||l>y) return 0;
  if(l>=x&&r<=y) return b[k];
  int m=(l+r)>>1;
  return query(l,m,k<<1,x,y)+query(m+1,r,k<<1|1,x,y);
}
struct node
{
  int mx,se,mxnum,lz;
  node operator+(const node&o)const
  {
    node ans;
    ans.se=max(se,o.se);
    if(mx==o.mx) ans.mx=mx,ans.mxnum=mxnum+o.mxnum;
    else if(mx>o.mx) ans.mx=mx,ans.mxnum=mxnum,ans.se=max(ans.se,o.mx);
    else ans.mx=o.mx,ans.mxnum=o.mxnum,ans.se=max(ans.se,mx);
    ans.lz=mod;
    return ans;
  }
}t[N<<2];
bool debug=false;
void build(int l,int r,int k)
{
  if(l==r)
  {
    t[k].mx=l;
    t[k].mxnum=1;
    t[k].se=-1;
    t[k].lz=mod;
    return;
  }
  int m=(l+r)>>1;
  build(l,m,k<<1);build(m+1,r,k<<1|1);
  t[k]=t[k<<1]+t[k<<1|1];
}
void update(int l,int r,int k)
{
  if(t[k].lz>=t[k].mx){t[k].lz=mod;return;}
  t[k].mx=t[k].lz;
  if(l!=r) t[k<<1].lz=min(t[k<<1].lz,t[k].lz),t[k<<1|1].lz=min(t[k<<1|1].lz,t[k].lz);
  t[k].lz=mod;
}
void setv(int l,int r,int k,int x,int v)
{
  if(t[k].lz!=mod) update(l,r,k);
  if(l==r)
  {
    if(v>t[k].mx)
    {
      if(debug) cout<<"ins: "<<t[k].mx+1<<' '<<v<<' '<<1<<'\n';
      ins(1,n,1,t[k].mx+1,v,1);
    }
    else if(v<t[k].mx)
    { 
      if(debug) cout<<"ins: "<<v+1<<' '<<t[k].mx<<' '<<-1<<'\n';
      ins(1,n,1,v+1,t[k].mx,-1);
    }
    t[k].mx=v;
    return;
  }
  int m=(l+r)>>1;
  if(x<=m) setv(l,m,k<<1,x,v),update(m+1,r,k<<1|1);
  else setv(m+1,r,k<<1|1,x,v),update(l,m,k<<1);
  t[k]=t[k<<1]+t[k<<1|1];
}
void setmn(int l,int r,int k,int x,int y,int v)
{
  if(t[k].lz!=mod) update(l,r,k);
  if(r<x||l>y) return;
  if(l>=x&&r<=y&&v>t[k].se)
  {
    if(debug) cout<<"ok "<<l<<' '<<r<<' '<<t[k].mx<<'\n';
    if(v<t[k].mx)
    { 
      if(debug) cout<<"ins: "<<v+1<<' '<<t[k].mx<<' '<<-t[k].mxnum<<'\n';
      ins(1,n,1,v+1,t[k].mx,-t[k].mxnum);
    }
    t[k].lz=v;
    update(l,r,k);
    return;
  }
  int m=(l+r)>>1;
  setmn(l,m,k<<1,x,y,v);setmn(m+1,r,k<<1|1,x,y,v);
  t[k]=t[k<<1]+t[k<<1|1];
}
void sol(int cas)
{
  // debug=true;
  sc(n,q);
  build(1,n,1);
  while(q--)
  {
    int op,x,y;sc(op,x,y);
    if(op==2) printf("%lld\n",query(1,n,1,x,y)+y-x+1);
    else
    {
      setv(1,n,1,x,y);
      if(x>1) setmn(1,n,1,1,x-1,x-1);
    }
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
  return 0;
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/