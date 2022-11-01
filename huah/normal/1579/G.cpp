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
void iary(int *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void iary(ll *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void oary(int *a,int n){rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);}
void oary(ll *a,int n){rep(i,1,n) printf(i==n?"%lld\n":"%lld ",a[i]);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const int N=1e4+5,mod1=998244353,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,a[N],dp[N][2005];
int main()
{
    // freopen("1.in","r",stdin);
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,0,n-1) sc(a[i]);
        rep(i,0,n) memset(dp[i],inf,sizeof(dp[i]));
        dp[0][0]=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=2000;j++)
                if(dp[i][j]!=inf)
                {
                    assert(dp[i][j]>=j);
                    int k=j-a[i];
                    if(k>=0)
                        dp[i+1][k]=min(dp[i+1][k],dp[i][j]);
                    else
                    {
                        k*=-1;
                        dp[i+1][0]=min(dp[i+1][0],dp[i][j]+k);
                    }
                    if(j+a[i]<=2000)
                        dp[i+1][j+a[i]]=min(dp[i+1][j+a[i]],max(dp[i][j],j+a[i]));
                }
        int ans=inf;
        for(int j=0;j<=2000;j++) ans=min(ans,dp[n][j]);
        out(ans);
    }
}