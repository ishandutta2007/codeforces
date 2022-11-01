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
const int N=8e5+5,mod=998244353,low=400000;
int n,dp[1<<20],sum[1<<20];
bool ok[1<<20];
char s[21][N];
int vis[21][N],vd[21][N],ss[21];
void cal(char s[N],int vis[N],int vd[N],int &ss)
{
  int sum=0;
  for(int i=1;s[i];i++)
  {
    if(s[i]=='(') sum++;
    else sum--;
    if(!vis[low+sum])
      vd[low+sum]=vis[low+sum+1];
    vis[low+sum]++;
  }
  ss=sum;
}
void sol(int cas)
{
    sc(n);
    rep(i,1,n) sc(s[i]+1);
    rep(i,1,n) cal(s[i],vis[i-1],vd[i-1],ss[i-1]);
    int up=(1<<n)-1;
    memset(dp,-0x3f3f3f3f,sizeof(dp));
    dp[0]=0;
    ok[0]=true;
    int ans=0;
    for(int i=0;i<up;i++)
    {
      ans=max(ans,dp[i]);
      if(ok[i])
      {
        for(int j=0;j<n;j++)
        if(!(i>>j&1))
        {
          sum[i^(1<<j)]=sum[i]+ss[j];
          if(sum[i]>=0)
          {
            if(vis[j][low-sum[i]-1])
              ans=max(ans,dp[i]+vd[j][low-sum[i]-1]);
            else dp[i^(1<<j)]=max(dp[i^(1<<j)],dp[i]+vis[j][low-sum[i]]),ok[i^(1<<j)]=true;
          }
        }
      }
    }
    ans=max(ans,dp[up]);
    out(ans);
}
int main()
{
  // freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
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