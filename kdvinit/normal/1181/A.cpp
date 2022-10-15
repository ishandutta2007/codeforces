/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int x, y, z;
    cin>>x>>y>>z;

    int mx = (x+y)/z;
    cout<<mx<<" ";

    int r = 0;
    int r1 = x%z;
    int r2 = y%z;

    if(r1+r2>=z)
    {
        r = min(z-r1, z-r2);
    }

    cout<<r<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}