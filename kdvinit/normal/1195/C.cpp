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

    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    int dp[n+2][2];
    dp[n+1][0]=0;
    dp[n+1][1]=0;
    dp[n][0]=a[n];
    dp[n][1]=b[n];

    for(int i=n-1;i>0;i--)
    {
        int tmp=max(dp[i+2][0],dp[i+2][1]);
        dp[i][0]=max(tmp,dp[i+1][1]);
        dp[i][1]=max(tmp,dp[i+1][0]);
        dp[i][0]+=a[i];
        dp[i][1]+=b[i];
    }

    cout<<max(dp[1][0],dp[1][1])<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}