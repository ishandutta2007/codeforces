/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    int ans=0;
    if(b>a) ans++;
    if(c>a) ans++;
    if(d>a) ans++;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}