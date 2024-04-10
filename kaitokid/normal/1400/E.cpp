#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[5009],dp[5009][5009],n;
int go(int pr,int x)
{
    if(x==n)return 0;
    if(dp[pr][x]!=-1)return dp[pr][x];
    int ans=0;
    if(a[x]!=0)ans++;
    ans+=go(min(a[x],pr),x+1);
    if(pr>=a[x])ans=min(ans,go(a[x],x+1));
    if(pr<a[x])ans=min(ans,1+go(pr+1,x));

    return dp[pr][x]=ans;
}
int main()
{
    //ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)dp[i][j]=-1;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    cout<<go(0,0);
    return 0;
}