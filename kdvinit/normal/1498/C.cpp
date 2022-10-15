/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

int mod=1000000007;

int dp[1005][1005][2];
int sum_dp[1005][1005][2];

void solve()
{
    int n, k;
    cin>>n>>k;

    for(int j=0; j<=k+3; j++)
    {
        dp[0][j][0]=1;
        dp[0][j][1]=1;
        sum_dp[0][j][0]=1;
        sum_dp[0][j][1]=1;
    }

    for(int j=1; j<=k; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(j==1) dp[i][j][1] = 1;
            else if(i==1) dp[i][j][1] = (1 + sum_dp[n-1][j-1][0])%mod;
            else dp[i][j][1] = (1 + sum_dp[n-1][j-1][0] - sum_dp[i-2][j-1][0] + mod)%mod;

            sum_dp[i][j][1] = (sum_dp[i-1][j][1] + dp[i][j][1])%mod;

            if(j==1) dp[i][j][0]=1;
            else dp[i][j][0] = (1 + sum_dp[i+1][j-1][1] - sum_dp[1][j-1][1] + mod)%mod;

            sum_dp[i][j][0] = (sum_dp[i-1][j][0] + dp[i][j][0])%mod;
        }
    }


    int ans = dp[1][k][1];
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}