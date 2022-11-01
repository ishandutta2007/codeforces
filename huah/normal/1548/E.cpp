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
int n,m,x,c[N],d[N],a[N],b[N],dp1[N][20],dp2[N][20];
int lg[N];
void st(int dp[N][20],int a[N],int n)
{
  for(int i=1;i<=n;i++) dp[i][0]=a[i];
  for(int i=1;1<<i<=n;i++)
    for(int j=1;j+(1<<i)-1<=n;j++)
    dp[j][i]=max(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
}
int query(int dp[N][20],int l,int r)
{
  int k=lg[r-l+1];
  return max(dp[l][k],dp[r-(1<<k)+1][k]);
}
int l[N],r[N];
void get(int a[N],int n)
{
  stack<int>s;
  rep(i,1,n)
  {
    while(s.size()&&a[s.top()]>a[i]) s.pop();
    l[i]=s.size()?s.top():0;
    s.push(i);
  }
  while(!s.empty()) s.pop();
  nep(i,n,1)
  {
    while(s.size()&&a[s.top()]>=a[i]) s.pop();
    r[i]=s.size()?s.top():n+1;
    s.push(i);
  }
}
int tot,hs1[N],hs2[N],t[N*50],ls[N*50],rs[N*50],rt[N];
vector<int>vc[N];
void ins(int l,int r,int x,int &now,int pre)
{
  if(!now) now=++tot,t[now]=t[pre];
  t[now]++;
  if(l==r) return;
  int m=(l+r)>>1;
  if(x<=m) ins(l,m,x,ls[now],ls[pre]);
  else ins(m+1,r,x,rs[now],rs[pre]);
}
void push(int l,int r,int &now,int pre)
{
  if(!now){now=pre;return;}
  if(l==r) return;
  int m=(l+r)>>1;
  push(l,m,ls[now],ls[pre]);push(m+1,r,rs[now],rs[pre]);
}
int query(int l,int r,int x,int y,int &now,int pre)
{
  if(r<x||l>y||!now) return 0;
  if(l>=x&&r<=y) return t[now]-t[pre];
  int m=(l+r)>>1;
  return query(l,m,x,y,ls[now],ls[pre])+query(m+1,r,x,y,rs[now],rs[pre]);
}
void sol(int cas)
{
  rep(i,1,N) lg[i]=lg[i-1]+(1<<lg[i-1]==i),lg[i-1]--;
  sc(n,m,x);
  rep(i,1,n) sc(a[i]);
  rep(i,1,m) sc(b[i]);
  st(dp1,a,n);
  st(dp2,b,m);
  get(a,n);
  for(int i=1;i<=n;i++)
  {
    c[i]=1000000000;
    if(l[i]!=0) c[i]=min(c[i],query(dp1,l[i]+1,i));
    if(r[i]!=n+1) c[i]=min(c[i],query(dp1,i,r[i]-1));
  }
  get(b,m);
  for(int i=1;i<=m;i++)
  {
    d[i]=1000000000;
    if(l[i]!=0) d[i]=min(d[i],query(dp2,l[i]+1,i));
    if(r[i]!=m+1) d[i]=min(d[i],query(dp2,i,r[i]-1));
  }
  rep(i,1,m) hs1[i]=b[i],hs2[i]=d[i];
  sort(hs1+1,hs1+1+m);
  sort(hs2+1,hs2+1+m);
  rep(i,1,m)
    vc[lower_bound(hs1+1,hs1+1+m,b[i])-hs1].push_back(lower_bound(hs2+1,hs2+1+m,d[i])-hs2);
  rep(i,1,m)
  {
    for(int x:vc[i]) ins(1,m,x,rt[i],rt[i-1]);
    push(1,m,rt[i],rt[i-1]);
  }
  ll ans=0;
  rep(i,1,n)
  {
    int r=upper_bound(hs1+1,hs1+1+m,x-a[i])-hs1-1;
    int l=upper_bound(hs1+1,hs1+1+m,x-c[i])-hs1;
    if(l>r) continue;
    int rr=upper_bound(hs2+1,hs2+1+m,x-a[i])-hs2;
    ans+=query(1,m,rr,m,rt[r],rt[l-1]);
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