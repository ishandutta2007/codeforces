/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int l, r;
    cin>>l>>r;

    int ans = r%l;

    if(2*l-1 <= r) ans = max(ans, l-1);

    int x = (r+1)/2;
    if(x>=l) ans = max(ans, x-1);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}