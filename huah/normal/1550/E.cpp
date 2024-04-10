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
int n,k,up,t[N<<2],dp[1<<17];
char s[N];
int a[N],f[N][17],nex[17];
int cal(int cur,int c,int len)
{
  if(cur>n) return inf;
  return f[cur][c]+len-1;
}
void build(int l,int r,int k)
{
  if(l==r){t[k]=a[l];return;}
  int m=(l+r)>>1;
  build(l,m,k<<1);build(m+1,r,k<<1|1);
  t[k]=t[k<<1]|t[k<<1|1];
}
int query(int l,int r,int k,int x,int y)
{
  if(r<x||l>y) return 0;
  if(l>=x&&r<=y) return t[k];
  int m=(l+r)>>1;
  return query(l,m,k<<1,x,y)|query(m+1,r,k<<1|1,x,y);
}
bool judge(int m)
{
  if(m==0) return true;
  rep(i,0,k-1) nex[i]=n+1;
  int len=0;
  for(int i=n;i>=0;i--)
  {
    memcpy(f[i],nex,sizeof(nex));
    if(i+m-1<=n)
    {
      int sum=query(1,n,1,i,i+m-1);
      rep(j,0,k-1)
      if(sum==0||sum==(1<<(j+1))) nex[j]=i;
    }
  }
  memset(dp,inf,sizeof(dp));
  dp[0]=0;
  for(int i=0;i<up;i++)
    for(int j=0;j<k;j++)
    if(!(i>>j&1))
    dp[i^(1<<j)]=min(dp[i^(1<<j)],cal(dp[i],j,m));
  return dp[up-1]<=n;
}
void sol(int cas)
{
  sc(n,k);
  sc(s+1);
  rep(i,1,n) 
  if(s[i]=='?') a[i]=0;
  else a[i]=1<<(s[i]-'a'+1);
  build(1,n,1);
  up=1<<k;
  int l=0,r=n/k,ans;
  while(l<=r)
  {
    int m=(l+r)>>1;
    if(judge(m)) ans=m,l=m+1;
    else r=m-1;
  }
  out(ans);
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