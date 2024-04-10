#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e7+2,base = 1e9+7;
    int dp[maxn][4];
int main()
{
    memset(dp,0,sizeof(dp));
    int n;
    scanf("%d",&n);
    dp[0][0] = 1;
    for (int k=1;k<=n;k++)
    for (int v=0;v<4;v++)
    {
        int sum = 0;

        if (v!=0)
            sum += dp[k-1][0] % base;
        sum%=base;
        if (v!=1)
            sum += dp[k-1][1] % base;
        sum%=base;

        if (v!=2)
            sum += dp[k-1][2] % base;
        sum%=base;

        if (v!=3)
            sum += dp[k-1][3] % base;
    sum%=base;

        dp[k][v] = sum;
    }

    cout<<dp[n][0];
    return 0;
}