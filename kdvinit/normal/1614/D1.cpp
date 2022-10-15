/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 5e6 + 100;
int freq[N]={0}, cnt[N]={0}, dp[N];

void solve()
{
    int n, mx=0;
    cin>>n;
    
    for(int i=1; i<=n; i++) { int x; cin>>x; freq[x]++; mx=max(mx, x); }

    for(int i=1; i<=mx; i++)
    {
        for(int j=i; j<=mx; j+=i) cnt[i]+=freq[j];
    }

    for(int i=mx; i>=1; i--)
    {
        dp[i]=(cnt[i]*i);
        for(int j=i; j<=mx; j+=i)
        {
            dp[i] = max(dp[i], dp[j]+(cnt[i]-cnt[j])*i);
        }
    }

    int ans = dp[1];
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}