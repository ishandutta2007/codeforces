/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    string s, t;
    cin>>s>>t;

    int n = s.size();
    sort(s.begin(), s.end());

    map<char, int> mp;
    for(char x: s) mp[x]++;

    if(mp['a'] && mp['b'] && mp['c'] && t=="abc")
    {
        for(char x='a'; x<='z'; x++)
        {
            if(x=='b') { while(mp['c']--) cout<<'c'; }
            else if(x=='c') { while(mp['b']--) cout<<'b'; }
            else { while(mp[x]--) cout<<x; }
        }
        cout<<endl;
    }
    else cout<<s<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}