/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, t, x;
    cin>>n>>x>>t;

    if(t<x || n==1) { cout<<0<<endl; return; }

    int k = (t/x);
    int ans = (k*n);

    int l = max( (int) 1, (k - (n-1)) );

    int tmp = (k*(k+1))/2 - (l*(l-1))/2;
    ans-=tmp;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}