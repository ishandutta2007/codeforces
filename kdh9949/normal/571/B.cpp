#include<stdio.h>
#include<algorithm>
int a[300100],inv[300100],n,k;
long long dp[5010][5010];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    std::sort(a+1,a+n+1);
    for(int i=1;i<n;i++)inv[i]=a[i+1]-a[i];
    for(int i=0;i<=n%k;i++)
    {
        for(int j=0;j<=k-n%k;j++)
        {
            dp[i+1][j]=std::max(dp[i+1][j],dp[i][j]+inv[(n/k+1)*(i+1)+(n/k)*j]);
            dp[i][j+1]=std::max(dp[i][j+1],dp[i][j]+inv[(n/k+1)*i+(n/k)*(j+1)]);
        }
    }
    printf("%I64d",a[n]-a[1]-(dp[n%k][k-n%k]-inv[n]));
}