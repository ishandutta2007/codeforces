#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e6+10;
ll dp[mn][2],a[mn],bes[mn];
int beg[mn][2];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%lld",a+i);
    beg[1][0]=beg[1][1]=1;
    for(i=2;i<=n;i++){
        if(a[i]>=a[i-1])beg[i][0]=beg[i-1][0];
        else beg[i][0]=i;
        if(a[i]<=a[i-1])beg[i][1]=beg[i-1][1];
        else beg[i][1]=i;
    }
    memset(dp,0xc0,sizeof(dp));
    dp[0][0]=dp[0][1]=0;
    for(i=1;i<=n;i++){
        dp[i][0]=bes[beg[i][0]-1]+a[i]-a[beg[i][0]];
        if(beg[i][0]!=i)dp[i][0]=max(bes[beg[i][0]]+a[i]-a[beg[i][0]+1],dp[i][0]);
        dp[i][1]=bes[beg[i][1]-1]-a[i]+a[beg[i][1]];
        if(beg[i][1]!=i)dp[i][1]=max(bes[beg[i][1]]-a[i]+a[beg[i][1]+1],dp[i][1]);
        bes[i]=max(dp[i][0],dp[i][1]);
    }
    printf("%lld",max(dp[n][0],dp[n][1]));
}