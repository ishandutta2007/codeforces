/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++)
    {
        int l = i-1;
        for(int j=0; j<i; j++)
        {
            int pos = l-j+1;
            dp[i][j+1] = max(dp[i][j+1], dp[i-1][j]);
            int tmp = (a[i]==pos);
            dp[i][j] = max(dp[i][j], dp[i-1][j]+tmp);
        }
    }

    int ans=-1;
    for(int i=0; i<=n; i++)
    {
        if(dp[n][i]>=k)
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}