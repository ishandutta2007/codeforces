/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int x, y;
    cin>>x>>y;

    int dif = abs(x-y);

    if(dif==0) { cout<<0<<" "<<0<<endl; return; }

    int k = x/dif;
    int a1 = x - (k*dif);
    int a2 = (k+1)*dif - x;

    int ans = min(a1, a2);
    cout<<dif<<" "<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}