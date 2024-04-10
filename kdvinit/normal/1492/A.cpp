/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int p,a,b,c;
    cin>>p>>a>>b>>c;

    int x=((p-1)/a + 1)*a;
    int y=((p-1)/b + 1)*b;
    int z=((p-1)/c + 1)*c;

    int ans=min(x-p,y-p);
    ans=min(ans,z-p);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}