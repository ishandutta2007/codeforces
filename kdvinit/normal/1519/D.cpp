/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int dp[n+1][n+1];

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    int tot = 0;
    for(int i=1; i<=n; i++) tot+=(a[i]*b[i]);

    for(int i=1; i<=n; i++) dp[i][i]=tot;
    for(int i=1; i<n; i++)
    {
        dp[i][i+1] = tot - (a[i]*b[i]) - (a[i+1]*b[i+1]) + (a[i]*b[i+1]) + (a[i+1]*b[i]);
    }

    for(int k=2; k<n; k++)
    {
        for(int i=1; i+k<=n; i++)
        {
            int j = i+k;
            dp[i][j] = dp[i+1][j-1] - (a[i]*b[i]) - (a[j]*b[j]) + (a[i]*b[j]) + (a[j]*b[i]);
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++) ans = max(ans, dp[i][j]);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}