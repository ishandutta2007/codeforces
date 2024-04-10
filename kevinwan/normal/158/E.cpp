#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int mn=4010;
pii c[mn*2];
int dp[mn][mn];
int main()
{
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d%d",&c[i].first,&c[i].second);
    for(i=n+1;i<mn*2;i++)c[i]={86401,86400};
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    int ans=0;
    for(i=1;i<=n;i++){
            dp[i][0]=0;
        for(j=1;j<=i;j++){
            dp[i][j]=min(dp[i-1][j],max(dp[i-1][j-1],c[i].first-1)+c[i].second);
            ans=max(ans,c[j+k+1].first-dp[i][j]-1);
        }
    }
    printf("%d",max(ans,c[k+1].first-1));
}