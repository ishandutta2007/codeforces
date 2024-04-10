#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
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
using namespace std;
const int N=5e3+5,mod=998244353;
int n,a[N];
int dp[2][N<<1];
int main()
{
    sc(n);
    rep(i,1,n) sc(a[i]);
    memset(dp,inf,sizeof(dp));
    int u=0;
    dp[u][5000]=0;
    rep(i,1,n)
    {
        rep(j,-(i-1),i-1)
        if(dp[u][j+5000]!=inf)
        {
            if(a[i])
            {
                if(j<0)
                    dp[u^1][j+1+5000]=dp[u][j+5000]+i;
                else dp[u^1][j+1+5000]=dp[u][j+5000]-i;
            }
            else
            {
                dp[u^1][j+5000]=min(dp[u^1][j+5000],dp[u][j+5000]);
                if(j>0)
                    dp[u^1][j-1+5000]=min(dp[u^1][j-1+5000],dp[u][j+5000]+i);
                else
                    dp[u^1][j-1+5000]=min(dp[u^1][j-1+5000],dp[u][j+5000]-i);
            }
        }
        memset(dp[u],inf,sizeof(dp[u]));
        u^=1;
    }
    out(dp[u][5000]);
}