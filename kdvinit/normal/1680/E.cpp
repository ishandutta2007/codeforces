/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int l=n+1;
    int r=0;

    int a[3][n+1];
    for(int j=1; j<=2; j++)
    {
        for(int i=1; i<=n; i++)
        {
            a[j][i]=0;
            char x; cin>>x;
            if(x=='*')
            {
                a[j][i]=1;
                l=min(l, i);
                r=max(r, i);
            }
        }
    }

    int dp[2][n+1];
    memset(dp, 0, sizeof(dp));

    if(a[1][l]==1)
    {
        if(a[2][l]==1) { dp[1][l]=1; dp[2][l]=1; }
        else { dp[1][l]=0; dp[2][l]=1; }
    }
    else { dp[1][l]=1; dp[2][l]=0; }

    for(int i=l+1; i<=r; i++)
    {
        int x=a[1][i];
        int y=a[2][i];

        if(x==0 && y==0)
        {
            dp[1][i]=min(dp[2][i-1]+2, dp[1][i-1]+1);
            dp[2][i]=min(dp[1][i-1]+2, dp[2][i-1]+1);
        }
        if(x==0 && y==1)
        {
            dp[1][i]=min(dp[2][i-1]+2, dp[1][i-1]+2);
            dp[2][i]=min(dp[1][i-1]+2, dp[2][i-1]+1);
        }
        if(x==1 && y==0)
        {
            dp[1][i]=min(dp[2][i-1]+2, dp[1][i-1]+1);
            dp[2][i]=min(dp[1][i-1]+2, dp[2][i-1]+2);
        }
        if(x==1 && y==1)
        {
            dp[1][i]=min(dp[2][i-1]+2, dp[1][i-1]+2);
            dp[2][i]=min(dp[1][i-1]+2, dp[2][i-1]+2);
        }
    }

    int ans = min(dp[1][r], dp[2][r]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}