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

    int mx=-1;
    int mn=10000;

    int ans = a[n]-a[1];

    for(int i=1; i<=n; i++)
    {
        if(i<n)
        {
            mn = min(mn, a[i]);
            int cur = a[i]-a[i+1];
            ans = max(ans, cur);
        }
        if(i>1) mx = max(mx, a[i]);
    }

    ans = max(ans, mx-a[1]);
    ans = max(ans, a[n]-mn);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}