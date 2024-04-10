/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int x,y,k,z;
    cin>>x>>y>>k;
    z=(k*y);
    z+=k;
    z-=1;
    z+=(x-2);
    z/=(x-1);
    z+=k;

    cout<<z<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}