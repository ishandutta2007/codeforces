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

    string s; cin>>s;

    int dp[n+1][k+1];
    int par[n+1][k+1];

    int mn[n+1];
    mn[0]=1;

    for(int j=1; j<=k; j++) dp[0][j]=0;

    for(int i=1; i<=n; i++)
    {
        //cout<<i<<endl;
        char x = s[i-1];
        int y = x-'A'+1;

        int z = mn[i-1];
        int z_min=n+1;
        int ind;
        for(int j=1; j<=k; j++)
        {
            if(j==z) continue;
            dp[i][j] = dp[i-1][z]+1;
            par[i][j] = z;
            if(dp[i-1][j]<z_min)
            {
                z_min = dp[i-1][j];
                ind = j;
            }
        }
        dp[i][z] = z_min + 1;
        par[i][z] = ind;

        dp[i][y]--;

        int cur_val = n+1;
        for(int j=1; j<=k; j++)
        {
            if(dp[i][j]<cur_val)
            {
                cur_val = dp[i][j];
                mn[i] = j;
            }
        }
    }

    string ans;
    int z=mn[n];
    int val = dp[n][z];

    for(int i=n; i>=1; i--)
    {
        char x = 'A' + z -1;
        ans+=x;
        z = par[i][z];
    }
    reverse(ans.begin(), ans.end());

    cout<<val<<endl;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}