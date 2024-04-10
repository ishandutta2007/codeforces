/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, l, k;
    cin>>n>>l>>k;

    int d[n+2];
    for(int i=1; i<=n; i++) cin>>d[i];
    d[n+1]=l;

    int a[n+2];
    for(int i=1; i<=n; i++) cin>>a[i];
    a[n+1]=0;

    int dp[n+2][k+1];
    for(int i=1; i<=n+1; i++)
    {
        for(int j=0; j<=k; j++) dp[i][j]=1e10;
    }

    dp[1][0]=0;
    for(int i=2; i<=n+1; i++)
    {
        for(int i2=1; i2<i; i2++)
        {
            for(int j=0; j<=k; j++)
            {
                int k2 = j+(i-i2-1);
                if(k2>k) continue;
                int tmp = dp[i2][j]+(d[i]-d[i2])*a[i2];
                dp[i][k2] = min(dp[i][k2], tmp);
            }
        }
    }

    int ans = 1e10;
    for(int j=0; j<=k; j++) ans = min(ans, dp[n+1][j]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}