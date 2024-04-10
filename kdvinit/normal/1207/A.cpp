/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int b, p, f;
    cin>>b>>p>>f;

    int h, c;
    cin>>h>>c;

    if(h<c) { swap(h, c); swap(p, f); }

    int m1 =  min((b/2), p);
    int ans = m1*h;

    b-=(2*m1);

    int m2 = min((b/2), f);
    ans += m2*c;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}