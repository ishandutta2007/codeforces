/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int mx = 1<<24;
    int dp[mx]={0};


    for(int i=1; i<=n; i++)
    {
        string s; cin>>s;
        int mask = 0;
        for(auto x: s) mask |= ( 1 << (x-'a') );
        dp[mask]++;
    }

    int p2=1;
    for(int i=0; i<24; i++)
    {
        for(int mask=0; mask<mx; mask++)
        {
            if(mask & p2) dp[mask] += dp[mask ^ p2];
        }
        p2*=2;
    }

    int ans=0;
    for(int bm=0; bm<mx; bm++) ans ^= (n-dp[bm])*(n-dp[bm]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}