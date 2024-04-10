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

    int pos[2][n+1], cnt[2]={0};
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        pos[x][++cnt[x]]=i;
    }

    if(cnt[1]==0) { cout<<0<<endl; return; }

    int dp[n+1][n+1];
    for(int i=0; i<=cnt[1]; i++)
    {
        for(int j=i; j<=cnt[0]; j++)
        {
            if(i==0) { dp[i][j]=0; continue; }
            dp[i][j] = dp[i-1][j-1] + abs(pos[1][i]-pos[0][j]);
            if(i==j) continue;
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }
    int ans = dp[cnt[1]][cnt[0]];
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}