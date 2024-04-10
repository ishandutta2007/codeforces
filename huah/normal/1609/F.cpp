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
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=1e6+5,mod=998244353;
int n,l1[N],r1[N],l2[N],r2[N],rk[N];
ll a[N],hs[N];
int b[N];
int top,s[N];
ll sum[N*10];
int tot,rt[N],si[N*10],ls[N*10],rs[N*10];
void ins(int l,int r,int x,ll v1,int v2,int &now,int pre)
{
  now=++tot;
  sum[now]+=v1+sum[pre];
  si[now]+=v2+si[pre];
  if(l==r) return;
  int m=(l+r)>>1;
  if(x<=m) ins(l,m,x,v1,v2,ls[now],ls[pre]),rs[now]=rs[pre];
  else ins(m+1,r,x,v1,v2,rs[now],rs[pre]),ls[now]=ls[pre];
}
ll qsum(int l,int r,int x,int now,int pre)
{
  if(!now) return 0;
  if(l==r) return sum[now]-sum[pre];
  int m=(l+r)>>1;
  if(x<=m) return qsum(l,m,x,ls[now],ls[pre]);
  return qsum(m+1,r,x,rs[now],rs[pre]);
}
ll qsi(int l,int r,int x,int now,int pre)
{
  if(!now) return 0;
  if(l==r) return si[now]-si[pre];
  int m=(l+r)>>1;
  if(x<=m) return qsi(l,m,x,ls[now],ls[pre]);
  return qsi(m+1,r,x,rs[now],rs[pre]);
}
void init()
{
  top=0;
  rep(i,1,n)
  {
    while(top&&a[s[top]]>a[i]) top--;
    if(top) l1[i]=s[top];
    else l1[i]=0;
    s[++top]=i;
  }
  top=0;
  nep(i,n,1)
  {
    while(top&&a[s[top]]>=a[i]) top--;
    if(top) r1[i]=s[top];
    else r1[i]=n+1;
    s[++top]=i;
  }
  top=0;
  rep(i,1,n)
  {
    while(top&&a[s[top]]<=a[i]) top--;
    if(top) l2[i]=s[top];
    else l2[i]=0;
    s[++top]=i;
  }
  top=0;
  nep(i,n,1)
  {
    while(top&&a[s[top]]<a[i]) top--;
    if(top) r2[i]=s[top];
    else r2[i]=n+1;
    s[++top]=i;
  }
}
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  sc(n);
  rep(i,1,n) sc(a[i]),b[i]=__builtin_popcountll(a[i]);
  init();
  ll ans=0;
  s[top=1]=n+1;
  a[n+1]=4e18;
  for(int i=n;i>=1;i--)
  {
    while(a[s[top]]<a[i]) top--;
    s[++top]=i;
    ins(0,60,b[i],1ll*l2[i]*(s[top-1]-s[top]),s[top-1]-s[top],rt[top],rt[top-1]);
    int l=2,r=top,x;
    while(l<=r)
    {
      int m=(l+r)>>1;
      if(s[m]<r1[i]) x=m,r=m-1;
      else l=m+1;
    }
    ans+=1ll*qsi(0,60,b[i],rt[top],rt[x])*i-qsum(0,60,b[i],rt[top],rt[x]);;
    if(b[i]==b[s[x]]&&l2[s[x]]<i)
      ans+=1ll*(r1[i]-s[x])*(i-l2[s[x]]);
    if(l2[s[x]]<l1[i])
    {
      l=x;r=top;
      int y;
      while(l<=r)
      {
        int m=(l+r)>>1;
        if(l2[s[m]]<l1[i]) y=m,l=m+1;
        else r=m-1;
      }
      ans-=1ll*qsi(0,60,b[i],rt[y],rt[x])*l1[i]-qsum(0,60,b[i],rt[y],rt[x]);
      if(b[i]==b[s[x]]&&l2[s[x]]<l1[i])
        ans-=1ll*(r1[i]-s[x])*(l1[i]-l2[s[x]]);
    }
  }
  s[top=1]=0;
  a[0]=4e18;
  memset(rt,0,sizeof(rt));
  memset(ls,0,sizeof(ls));
  memset(rs,0,sizeof(rt));
  memset(sum,0,sizeof(sum));
  memset(si,0,sizeof(si));
  tot=0;
  for(int i=1;i<=n;i++)
  {
    while(a[s[top]]<=a[i]) top--;
    s[++top]=i;
    ins(0,60,b[i],1ll*r2[i]*(s[top]-s[top-1]),s[top]-s[top-1],rt[top],rt[top-1]);
    int l=2,r=top,x;
    while(l<=r)
    {
      int m=(l+r)>>1;
      if(s[m]>l1[i]) x=m,r=m-1;
      else l=m+1;
    }
    ans+=qsum(0,60,b[i],rt[top],rt[x])-1ll*qsi(0,60,b[i],rt[top],rt[x])*i;
    if(b[i]==b[s[x]]&&r2[s[x]]>i)
      ans+=1ll*(s[x]-l1[i])*(r2[s[x]]-i);
    if(r2[s[x]]>r1[i])
    {
      l=x;r=top;
      int y;
      while(l<=r)
      {
        int m=(l+r)>>1;
        if(r2[s[m]]>r1[i]) y=m,l=m+1;
        else r=m-1;
      }
      ans-=qsum(0,60,b[i],rt[y],rt[x])-1ll*qsi(0,60,b[i],rt[y],rt[x])*r1[i];
      if(b[i]==b[s[x]]&&r2[s[x]]>r1[i])
        ans-=1ll*(s[x]-l1[i])*(r2[s[x]]-r1[i]);
    }
  }
  out(ans-n);
}