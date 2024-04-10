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
    int x, ans=0;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        ans += (n-i+1)*mp[x];
        mp[x]+=i;
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