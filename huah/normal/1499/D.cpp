#pragma GCC optimize(2)
#include<bits/stdc++.h>
typedef unsigned long long ull;
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
void ary(int *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void ary(ll *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void oary(int *a,int n){rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);}
void oary(ll *a,int n){rep(i,1,n) printf(i==n?"%lld\n":"%lld ",a[i]);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const int N=2e7+5;
int c,d,x;
ll dp[N];
ll cal(int c,int s)
{
  if(s%c) return 0;
  return dp[s/c];
}
bool vis[N];
int tot,p[N];
int main()
{
  dp[1]=1;
  for(int i=2;i<=20000000;i++)
  {
    if(!vis[i]) p[++tot]=i,dp[i]=2;
    for(int j=1;j<=tot&&i*p[j]<=20000000;j++)
    {
      vis[i*p[j]]=true;
      if(i%p[j]==0)
      {
        dp[i*p[j]]=dp[i];
        break;
      }
      dp[i*p[j]]=dp[i]*2;
    }
  }
  int t;sc(t);
  while(t--)
  {
    sc(c,d,x);
    ll ans=0;
    for(int i=1;i*i<=x;i++)
      if(x%i==0)
      {
        ans+=cal(c,x/i+d);
        if(x/i!=i) ans+=cal(c,i+d);
      }
    out(ans);
  }
}