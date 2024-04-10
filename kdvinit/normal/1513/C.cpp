/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int M = 2e5 + 1;
int dp[M][10];
int mod = 1e9 + 7;

int Get_DP()
{
    for(int i=0; i<=9; i++) dp[0][i]=1;

    for(int i=1; i<M; i++)
    {
        for(int j=0; j<9; j++) dp[i][j] = dp[i-1][j+1];
        dp[i][9] = dp[i-1][0]+dp[i-1][1];
        dp[i][9]%=mod;
    }
}

void solve()
{
    string s;
    cin>>s;

    int n = s.size();
    int m; cin>>m;

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        int x = s[i]-'0';
        ans+=dp[m][x];
        ans%=mod;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    Get_DP();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}