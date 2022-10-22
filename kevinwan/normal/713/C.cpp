#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3e3+10;
ll dp[2][mn];
int a[mn],b[mn];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i),a[i]-=i;
    memcpy(b,a,sizeof(b));
    sort(b,b+n);
    for(i=0;i<n;i++){
        dp[0][i]=abs(a[0]-b[i]);
        if(i)dp[0][i]=min(dp[0][i],dp[0][i-1]);
    }
    for(i=1;i<n;i++){
        for(j=0;j<n;j++){
            dp[i&1][j]=dp[i&1^1][j]+abs(a[i]-b[j]);
            if(j)dp[i&1][j]=min(dp[i&1][j],dp[i&1][j-1]);
        }
    }
    printf("%lld",dp[n&1^1][n-1]);
}