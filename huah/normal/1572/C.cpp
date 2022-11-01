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
const int N=5e3+5;
int n,dp[N][N],nex[N],a[N];
int Dp(int l,int r)
{
    if(l==r) return 0;
    if(dp[l][r]!=inf) return dp[l][r];
    dp[l][r]=min(dp[l][r],1+Dp(l+1,r));
    dp[l][r]=min(dp[l][r],1+Dp(l,r-1));
    int cur=l;
    while(nex[cur]<r)
        cur=nex[cur],dp[l][r]=min(dp[l][r],Dp(l,cur)+(cur==r?0:Dp(cur+1,r)+1));
    if(a[l]==a[r])
    {
        if(l+1==r) return dp[l][r]=0;
        for(int i=nex[l];i<r;i=nex[i])
            dp[l][r]=min(dp[l][r],Dp(l,i)+Dp(i,r));
        dp[l][r]=min(dp[l][r],Dp(l+1,r-1)+1);
    }
    return dp[l][r];
}
int main()
{
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,1,n)
        {
            sc(a[i]);
            if(a[i]==a[i-1])
                i--,n--;
        }
        rep(i,1,n) rep(j,1,n) dp[i][j]=inf;
        rep(i,1,n)
        {
            nex[i]=n+1;
            rep(j,i+1,n)
            if(a[j]==a[i])
            {
                nex[i]=j;
                break;
            }
        }
        out(Dp(1,n));
    }
}