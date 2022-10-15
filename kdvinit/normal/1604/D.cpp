/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int x, y;
    cin>>x>>y;

    if(y<x) { cout<<(x*y + y)<<endl; return; }
    if(y%x==0) { cout<<y<<endl; return; }

    int k = y/x;
    k*=x;

    int ans = (y+k)/2;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}