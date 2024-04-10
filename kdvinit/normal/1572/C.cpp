/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1], x, lst=-1, m=0;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if(x==lst) continue;
        lst=x; a[++m]=x;
    }

    vector<int> pos[n+1];
    for(int i=1; i<=m; i++) pos[a[i]].push_back(i);

    int dp[m+2][m+2];
    for(int len=0; len<=m; len++)
    {
        for(int l=1; l+len-1<=m; l++)
        {
            int r = l+len-1;
            if(len<=1) { dp[l][r]=0; continue; }

            int cur = dp[l+1][r]+1;
            for(int j: pos[a[l]])
            {
                if(j<=l) continue; if(j>r) break;
                int y = dp[l+1][j-1] + dp[j][r] + 1;
                if(j==l+1) y--;
                cur = min(cur, y);
            }
            dp[l][r]=cur;
        }
    }

    cout<<dp[1][m]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}