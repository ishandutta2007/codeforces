/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int a, b; cin>>a>>b;
    int x = min(a, b);
    int y = max(a, b);

    if(y>=3*x) { cout<<x<<endl; return; }
    int ans = (x+y)/4;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}