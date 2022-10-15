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

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int dp[n+1]={0};
    dp[1]=1;

    int ans = 1;
    for(int i=2; i<=n; i++)
    {
        int s=i-300;
        s=max(s, (int)1);
        dp[i]=1;

        for(int j=s; j<i; j++)
        {
            int x1 = a[j]^(i-1);
            int x2 = a[i]^(j-1);

            if(x1<x2)
            {
                dp[i]=max(dp[i], dp[j]+1);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}