/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int r, b, d;
    cin>>r>>b>>d;

    int x, y;
    x = min(r, b);
    y = max(r, b);

    if(y>x*(d+1)) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}