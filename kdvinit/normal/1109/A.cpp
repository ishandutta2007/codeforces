/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    map<int, int> mp[2];
    int x=0, y=0, ans=0, z;

    mp[0][0]++;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        y^=x;
        z=i%2;
        ans+=mp[z][y];
        mp[z][y]++;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}