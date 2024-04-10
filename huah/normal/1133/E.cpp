#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[5005],dp[5005][5005];
int p[5005][6];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        for(int k=5;k>=0;k--)
    {
        int t=lower_bound(a+1,a+1+n,a[i]-k)-a;
        if(a[t]==a[i]-k) t--;
        p[i][k]=t;
    }
    for(int j=1;j<=k;j++)
        for(int i=1;i<=n;i++)
            for(int k=5;k>=0;k--)
                dp[i][j]=max(dp[i][j],max(dp[p[i][k]][j],dp[p[i][k]][j-1]+i-p[i][k]));
    printf("%d\n",dp[n][k]);
}