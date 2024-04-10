#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=998244353;
ll n,k,dp[1004][2001][2][2];
int main()
{
ios::sync_with_stdio(0);
cin>>n>>k;
dp[0][1][0][0]=1;
dp[0][1][1][1]=1;
dp[0][2][0][1]=1;
dp[0][2][1][0]=1;
for(int i=1;i<n;i++)
{
    for(int j=1;j<=k;j++)
    {
        dp[i][j][0][0]=(dp[i-1][j][0][0]+dp[i-1][j-1][1][1]+dp[i-1][j][1][0]+dp[i-1][j][0][1])%mod;
       dp[i][j][1][1]=(dp[i-1][j][1][1]+dp[i-1][j-1][0][0]+dp[i-1][j][1][0]+dp[i-1][j][0][1])%mod;
       if(j==1)continue;
       dp[i][j][0][1]=(dp[i-1][j][0][1]+dp[i-1][j-2][1][0]+dp[i-1][j-1][0][0]+dp[i-1][j-1][1][1])%mod;
       dp[i][j][1][0]=(dp[i-1][j][1][0]+dp[i-1][j-2][0][1]+dp[i-1][j-1][0][0]+dp[i-1][j-1][1][1])%mod;
    }


}
cout<<(dp[n-1][k][0][0]+dp[n-1][k][0][1]+dp[n-1][k][1][0]+dp[n-1][k][1][1])%mod;
 return 0;
}