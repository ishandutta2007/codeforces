/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, ans=0;
    cin>>n;

    map<int, int> mp;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        x = abs(x);
        mp[x]++;
        if(x==0 && mp[x]<=1) ans++;
        if(x!=0 && mp[x]<=2) ans++;
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