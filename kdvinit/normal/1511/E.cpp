/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;

void solve()
{
    int n, m;
    cin>>n>>m;

    int cntw=0;
    int a[n+1][m+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char x; cin>>x;

            if(x=='*') a[i][j]=0;
            else a[i][j]=1;

            cntw+=a[i][j];
        }
    }

    if(cntw<=1)
    {
        cout<<0<<endl;
        return;
    }

    int dp[cntw+1];
    int pow2[cntw+1];

    dp[0]=0; dp[1]=0; dp[2]=1;
    pow2[0]=1; pow2[1]=2; pow2[2]=4;

    for(int i=3; i<=cntw; i++)
    {
        pow2[i] = (pow2[i-1]*2)%mod;
        dp[i] = (2*dp[i-2] + dp[i-1] + pow2[i-2])%mod;
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]==0) continue;

            int k = j;
            while(k<=m && a[i][k]==1) k++;
            int cnt = k-j;

            ans += (dp[cnt]*pow2[cntw-cnt])%mod;
            ans%=mod;

            j = k-1;
        }
    }

    for(int j=1; j<=m; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(a[i][j]==0) continue;

            int k = i;
            while(k<=n && a[k][j]==1) k++;
            int cnt = k-i;

            ans += (dp[cnt]*pow2[cntw-cnt])%mod;
            ans%=mod;

            i = k-1;
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}