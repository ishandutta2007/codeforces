/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, q;
    cin>>n>>q;

    int a[n+2], ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];

    int dp_odd[n+1]; //my len is odd
    int dp_even[n+1];   //my length is even

    dp_odd[1]=a[1];
    dp_even[1]=0;

    for(int i=2;i<=n;i++)
    {
        dp_odd[i] = max(dp_odd[i-1],dp_even[i-1]+a[i]);
        dp_even[i] = max(dp_even[i-1],dp_odd[i-1]-a[i]);
    }

    ans=max(dp_odd[n],dp_even[n]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}