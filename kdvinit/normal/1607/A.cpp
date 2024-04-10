/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    string a, s;
    cin>>a>>s;

    map<int, int> pos;
    for(int i=0; i<26; i++) pos[a[i]]=i;

    int n = s.size();

    int ans = 0;
    for(int i=1; i<n; i++)
    {
        int tmp = abs(pos[s[i]] - pos[s[i-1]]);
        ans+=tmp;
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