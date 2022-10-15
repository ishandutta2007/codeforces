#include<bits/stdc++.h>
using namespace std;

#define int long long

int mod=1e9+7;

void solve()
{
    int n,m;
    cin>>n>>m;

    int dp[(2*m+1)][n+1];

    for(int j=1;j<=n;j++)
    {
        dp[1][j]=1;
    }

    for(int i=2;i<=2*m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int tmp=0;
            for(int k=1;k<=j;k++)
            {
                tmp+=dp[i-1][k];
                tmp%=mod;
            }
            dp[i][j]=tmp;
        }
    }

    int ans=0;
    for(int j=1;j<=n;j++) { ans+=dp[2*m][j]; ans%=mod; }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}