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
const int N=5e3+5,mod=1e9+7;
int n,k,a[N],cntA[N],cntB[N],sa[N],rk[N],tsa[N],A[N],B[N],h[N];
int f[N],dp[N][20],lg[N];
void solve()
{
    memset(cntA,0,sizeof(cntA));
    for(int i=1;i<=n;i++) cntA[a[i]]++;
    for(int i=1;i<=100;i++) cntA[i]+=cntA[i-1];
    for(int i=n;i>=1;i--) sa[cntA[a[i]]--]=i;
    rk[sa[1]]=1;
    for(int i=2;i<=n;i++)
    {
        rk[sa[i]]=rk[sa[i-1]];
        if(a[sa[i]]!=a[sa[i-1]]) rk[sa[i]]++;
    }
    for(int l=1;rk[sa[n]]<n;l<<=1)
    {
        for(int i=0;i<=n;i++) cntA[i]=cntB[i]=0;
        for(int i=1;i<=n;i++)
        {
            cntA[A[i]=rk[i]]++;
            cntB[B[i]=i+l<=n?rk[i+l]:0]++;
        }
        for(int i=1;i<=n;i++)
            cntB[i]+=cntB[i-1],cntA[i]+=cntA[i-1];
        for(int i=n;i>=1;i--) tsa[cntB[B[i]]--]=i;
        for(int i=n;i>=1;i--) sa[cntA[A[tsa[i]]]--]=tsa[i];
        rk[sa[1]]=1;
        for(int i=2;i<=n;i++)
        {
            rk[sa[i]]=rk[sa[i-1]];
            if(A[sa[i]]!=A[sa[i-1]]||B[sa[i]]!=B[sa[i-1]]) rk[sa[i]]++;
        }
    }
    for(int i=1,j=0;i<=n;i++)
    {
        if(j)j--;
        while(a[i+j]==a[sa[rk[i]-1]+j]) j++;
        h[rk[i]]=j;
    }
}
char s[N];
void st()
{
  for(int i=1;1<<i<=n;i++)
    for(int j=1;j+(1<<i)-1<=n;j++)
    dp[j][i]=min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
}
int query(int l,int r)
{
  int k=lg[r-l+1];
  return min(dp[l][k],dp[r-(1<<k)+1][k]);
}
void sol(int cas)
{
  sc(n);sc(s+1);
  rep(i,1,n) a[i]=s[i]-'a'+1;
  a[n+1]=0;
  solve();
  rep(i,1,n) f[i]=n-sa[i]+1,dp[i][0]=h[i];
  st();
  rep(i,2,n)
    rep(j,1,i-1)
    if(sa[j]<sa[i])
    f[i]=max(f[i],f[j]+(n-sa[i]+1)-query(j+1,i));
  int ans=0;
  rep(i,1,n) ans=max(ans,f[i]);
  out(ans);
}
int main()
{
  rep(i,1,N-1) lg[i]=lg[i-1]+(1<<lg[i-1]==i),lg[i-1]--;
  // freopen("1.in", "r",stdin);
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