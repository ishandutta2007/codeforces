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
    int n = s.size();

    map<char, int> mp;
    for(char x: s) mp[x]++;

    for(int i=0; i<n; i++)
    {
        if(mp[s[i]]==1)
        {
            for(int j=i; j<n; j++) cout<<s[j];
            cout<<endl;
            return;
        }
        mp[s[i]]--;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}