/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    map<int, int> mp;
    int ans = -1;

    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        if(mp[x]!=0)
        {
            ans = max(ans, mp[x]);
            ans = max(ans, n-i+mp[x]);
        }
        mp[x]=i;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}