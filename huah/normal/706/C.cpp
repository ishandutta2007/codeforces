#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s[100005],ss[100005];
ll a[100005],dp[100005][2];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) cin>>s[i],ss[i]=s[i],reverse(ss[i].begin(),ss[i].end());
    memset(dp,125,sizeof(dp));
    dp[1][0]=0;dp[1][1]=a[1];
    ll inf=dp[0][0];
    for(int i=2;i<=n;i++)
    {
        if(s[i]>=s[i-1]) dp[i][0]=dp[i-1][0];
        if(s[i]>=ss[i-1]) dp[i][0]=min(dp[i][0],dp[i-1][1]);
        if(ss[i]>=s[i-1]) dp[i][1]=dp[i-1][0]+a[i];
        if(ss[i]>=ss[i-1]) dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
    }
    ll ans=min(dp[n][0],dp[n][1]);
    if(ans==inf) printf("-1\n");
    else printf("%lld\n",ans);
}