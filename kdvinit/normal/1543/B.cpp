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

    int a[n+1], sum=0;
    for(int i=1; i<=n; i++) cin>>a[i], sum+=a[i];

    int d1 = sum%n;
    int d2 = n-d1;

    int ans = d1*d2;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}