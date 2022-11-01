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
int n,q,a[N],dp[N][15][31];
int Max(int x,int y)
{
  if(a[x]+x>a[y]+y) return x;
  return y;
}
int t[N<<2],b[N];
void build(int l,int r,int k)
{
  if(l==r)
  {
    t[k]=l;
    return;
  }
  int m=(l+r)>>1;
  build(l,m,k<<1);build(m+1,r,k<<1|1);
  t[k]=Max(t[k<<1],t[k<<1|1]);
}
int query(int l,int r,int k,int x,int y)
{
  if(l>=x&&r<=y) return t[k];
  int m=(l+r)>>1;
  if(x<=m&&y>m) return Max(query(l,m,k<<1,x,y),query(m+1,r,k<<1|1,x,y));
  else if(x<=m) return query(l,m,k<<1,x,y);
  return query(m+1,r,k<<1|1,x,y);
}
void sol(int cas)
{
  sc(n,q);
  rep(i,1,n+1)
    rep(j,0,14)
    rep(k,0,30) dp[i][j][k]=n+1;
  rep(i,1,n) sc(a[i]);
  build(1,n,1);
  for(int i=n;i>=1;i--) b[i]=query(1,n,1,i,i+a[i]);
  for(int i=n;i>=1;i--)
  {
    for(int k=0;k<=30;k++)
    {
      dp[i][0][k]=b[i];  
      for(int j=1;j<=k;j++)
        if(i+a[i]+j<=n)
        dp[i][0][k]=Max(dp[i][0][k],i+a[i]+j);
    }
  }
  int s;
  for(s=1;1<<s<=n;s++)
    for(int j=1;j+(1<<s)-1<=n;j++)
  {
    for(int k=0;k<=30;k++) dp[j][s][k]=0;
    for(int k1=0;k1<=30;k1++)
      for(int k2=0;k1+k2<=30;k2++)
        dp[j][s][k1+k2]=Max(dp[j][s][k1+k2],dp[dp[j][s-1][k1]][s-1][k2]);
  }
  s--;
  while(q--)
  {
    int l,r,k;sc(l,r,k);
    if(l==r){out(0);continue;}
    if(l+a[l]+min(k,r-l-1)>=r){out(1);continue;}
    int f[31];
    rep(i,0,k) f[i]=l;
    int ans=0;
    for(int i=s;i>=0;i--)
    {
      bool flag=true;
      for(int k1=0;k1<=k&&flag;k1++)
      for(int k2=0;k1+k2<=k&&flag;k2++)
        if(dp[f[k1]][i][k2]+a[dp[f[k1]][i][k2]]+max(0,min(k-k1-k2,r-dp[f[k1]][i][k2]-1))>=r) flag=false;
      if(!flag) continue;
      ans|=1<<i;
      for(int k1=k;k1>=0;k1--)
        for(int k2=k-k1;k2>=0;k2--)
        f[k1+k2]=Max(f[k1+k2],dp[f[k1]][i][k2]);
    }
    out(ans+2);
  }
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