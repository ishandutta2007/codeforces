/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 998244353;

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int dp[n+5][2];
    for(int i=0; i<=n+4; i++) { dp[i][0]=0; dp[i][1]=0; }

    dp[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        int x=a[i];
        if(x>n+3) continue;

        if(x!=0)
        {
            int sum = dp[x-1][0] + dp[x-1][1];
            dp[x-1][1] += sum;      dp[x-1][1]%=mod;
        }

        dp[x+1][0] += dp[x+1][0]; //x+1, 0 += x+1, 0
        dp[x+1][1] += dp[x+1][1]; //x+1, 1 += x+1, 1
        dp[x+1][0]%=mod;
        dp[x+1][1]%=mod;

        dp[x+1][0] += dp[x][0]; //x+1, 0 += x, 0
        dp[x+1][0]%=mod;
    }


    int ans = 0;
    for(int i=0; i<=n+4; i++) { ans+=(dp[i][0]+dp[i][1]); ans%=mod; }
    ans -= dp[0][0];
    
    ans%=mod;
    if(ans<0) ans+=mod;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}