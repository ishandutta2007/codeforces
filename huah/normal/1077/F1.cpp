#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[205];
ll dp[205][205];
int main()
{
    int n,k,x;
    scanf("%d%d%d",&n,&k,&x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=x;j++)
            for(int h=1;h<=k;h++)
            {
                if(i<h) break;
                if(dp[i-h][j-1]==-1) continue;
                dp[i][j]=max(dp[i][j],dp[i-h][j-1]+a[i]);
            }
    ll ans=-1;
    for(int i=n;i>=n-k+1;i--)
        ans=max(ans,dp[i][x]);
    printf("%lld\n",ans);
}