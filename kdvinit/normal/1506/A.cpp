/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m, x;
    cin>>n>>m>>x;

    int i = (x-1)%n+1;
    int j = (x-1)/n+1;

    //cout<<i<<" "<<j<<endl;

    int ans = (i-1)*m + j;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}