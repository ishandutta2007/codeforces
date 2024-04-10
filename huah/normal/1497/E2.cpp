#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=1e7+5,mod=998244353;
#define inf 0x3f3f3f3f
int n,k,a[200005];
bitset<N>vis;
int tot,p[N],dp[200005][21];
int g[200005][21];
int sum,use[N];
int add(int x)
{
  return sum+(use[x]!=0);
}
void Add(int x)
{
  use[x]++;
  if(use[x]>=2) sum++;
}
void del(int x)
{
  use[x]--;
  if(use[x]>=1) sum--;
}
void sol()
{
  rep(i,0,n) memset(dp[i],inf,sizeof(dp[i]));
  rep(len,0,k)
  {
    sum=0;
    for(int i=1,j=0;i<=n;i++)
    {
      while(j<n&&add(a[j+1])<=len) j++,Add(a[j]);
      g[i-1][len]=j;
      del(a[i]);
    }
    rep(i,1,n) use[a[i]]=0;
  }
  dp[0][0]=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<=k;j++)
    for(int h=0;j+h<=k;h++)
    dp[g[i][h]][j+h]=min(dp[g[i][h]][j+h],dp[i][j]+1);
  int ans=dp[n][0];
  for(int i=1;i<=k;i++) ans=min(ans,dp[n][i]);
  out(ans);
}
int main()
{
  for(int i=2;i<=10000000;i++)
  {
    if(!vis[i]) p[++tot]=i;
    for(int j=1;j<=tot&&i*p[j]<=10000000;j++)
    {
      vis[i*p[j]]=true;
      if(i%p[j]==0) break;
    }
  }
  // freopen("1.in","r",stdin);
  int t;sc(t);
  while(t--)
  {
    sc(n,k);
    for(int i=1;i<=n;i++)
    {
      int x,z=1;sc(x);
      for(int j=1;j<=tot&&1ll*p[j]*p[j]<=x;j++)
        if(x%p[j]==0)
        {
          int y=0;
          while(x%p[j]==0) x/=p[j],y^=1;
          if(y) z*=p[j];
        }
      if(x>1) z*=x;
      a[i]=z;
    }
    sol();
  }
}