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

    map<int, int> mp;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        mp[x]++;
    }

    for(auto x: mp)
    {
        cout<<x.first<<" ";
        mp[x.first]--;
    }

    for(auto x: mp)
    {
        int y = x.second;
        while(y--) cout<<x.first<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}