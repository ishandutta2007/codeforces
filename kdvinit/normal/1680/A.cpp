/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int l1, r1, l2, r2;
    cin>>l1>>r1>>l2>>r2;

    int x = max(l1, l2);

    if(x<=r1 && x<=r2) cout<<x<<endl;
    else cout<<l1+l2<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}