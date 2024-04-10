/*
K.D. Vinit  |,,|
Hello Mohit
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e8;

void solve()
{
    int n1, n2, k1, k2;
    cin>>n1>>n2>>k1>>k2;

    int n = n1 + n2;
    int k = k1 + k2;

    int dp[n+1][n+1][k1+1][k2+1];
    
    memset(dp, 1, sizeof(dp));
    memset(dp, 0, sizeof(dp));
    
    dp[0][0][0][0]=1;

    for(int i=1; i<=n; i++)
    {
        //Picking a Man -> adds 1 to n1 and k1.
        for(int j=0; j<=i-1; j++)
        {
            for(int i1=0; i1<k1; i1++)
            {
                dp[j+1][i-1-j][i1+1][0] += dp[j][i-1-j][i1][0];
                dp[j+1][i-1-j][i1+1][0]%=mod;
            }

            for(int i2=1; i2<=k2; i2++)
            {
                dp[j+1][i-1-j][1][0] += dp[j][i-1-j][0][i2];
                dp[j+1][i-1-j][1][0]%=mod;
            }
        }

        //Picking a Horse -> adds 1 to n2 and k2.
        for(int j=0; j<=i-1; j++)
        {
            for(int i1=0; i1<=k1; i1++)
            {
                dp[j][i-1-j+1][0][1] += dp[j][i-1-j][i1][0];
                dp[j][i-1-j+1][0][1]%=mod;
            }

            for(int i2=1; i2<k2; i2++)
            {
                dp[j][i-1-j+1][0][i2+1] += dp[j][i-1-j][0][i2];
                dp[j][i-1-j+1][0][i2+1]%=mod;
            }
        }
    }

    int ans=0;

    for(int i1=0; i1<=k1; i1++) ans += dp[n1][n2][i1][0], ans%=mod;

    for(int i2=0; i2<=k2; i2++) ans += dp[n1][n2][0][i2], ans%=mod;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}