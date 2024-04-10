#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2][5001];
int a[5001],b[5001];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    memcpy(b,a+1,sizeof(b));
    sort(b,b+n);
    for(i=1;i<=n;i++){
        for(j=0;j<n;j++){
            dp[i&1][j]=dp[i&1^1][j]+abs(b[j]-a[i]);
        }
        for(j=1;j<n;j++)dp[i&1][j]=min(dp[i&1][j],dp[i&1][j-1]);
    }
    printf("%lld",dp[n&1][n-1]);
}