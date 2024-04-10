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
const int N=1e3+5,mod=1e9+7;
int n,k,dp[2][N][2];
void add(int &x,int y)
{
    x=(x+y)%mod;
}
int main()
{
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n,k);
        int u=0;
        memset(dp,0,sizeof(dp));
        dp[u][1][0]=1;
        k--;
        int ans=0;
        while(k--)
        {
            rep(i,1,n)
                add(ans,(dp[u][i][0]+dp[u][i][1])%mod);
            rep(i,1,n)
            {
                if(i+1<=n)
                    add(dp[u][i+1][0],dp[u][i][0]);
                if(i-1>=1) add(dp[u^1][i-1][1],dp[u][i][0]);
                else add(ans,dp[u][i][0]);
            }
            nep(i,n,1)
            {
                if(i-1>=1)
                    add(dp[u][i-1][1],dp[u][i][1]);
                if(i+1<=n) add(dp[u^1][i+1][0],dp[u][i][1]);
                else add(ans,dp[u][i][1]);
            }
            rep(i,1,n) dp[u][i][0]=dp[u][i][1]=0;
            u^=1;
        }
        rep(i,1,n) add(ans,(dp[u][i][0]+dp[u][i][1])%mod);
        out(ans);
    }
}