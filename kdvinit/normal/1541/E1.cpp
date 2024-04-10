/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
const int W = 1e4 + 1;

void solve()
{
    int n;
    cin>>n;

    int c[n+1], b[n+1];

    c[0]=0;
    for(int i=1; i<=n; i++) cin>>c[i];

    b[1]=0;
    for(int i=2; i<=n; i++) cin>>b[i];
    for(int i=2; i<=n; i++) b[i]+=b[i-1];       //Prefix Sum of b[i];
    for(int i=2; i<=n; i++) b[i]+=b[i-1];       //Prefix sum of Pb[i];

    int q, x;
    cin>>q>>x;

    int dp[W][n+1];
    memset(dp, 0, sizeof(dp));

    dp[0][0]=1;

    for(int i=1; i<=n; i++)
    {
        int l = (i*x + b[i]);
        for(int j=W-1; j>=0; j--)
        {
            if(dp[j][i-1]==0) continue;
            int low = max((int)0, l-j);
            for(int w=c[i]; w>=low; w--) dp[j+w][i]+=dp[j][i-1], dp[j+w][i]%=mod;
        }
    }

    int ans=0;
    for(int i=0; i<W; i++) ans+=dp[i][n], ans%=mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}