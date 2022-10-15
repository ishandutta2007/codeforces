/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int nc2(int n)
{
    int ans = (n*(n-1))/2;
    return ans;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int ans = m*nc2(n+1) + nc2(m);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}