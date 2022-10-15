/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    string s;
    cin>>s;

    map<char, int> mp;
    int ans=0;
    for(char x: s)
    {
        if(mp[x]==0) { mp[x]=1; ans++; }
        else
        {
            ans--;
            mp.clear();
        }
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