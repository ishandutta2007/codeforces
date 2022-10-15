/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    string s; cin>>s;
    int n = s.size();

    if(n%2) { cout<<"NO"<<endl; return; }

    int m = n/2;
    for(int i=0; i<m; i++)
    {
        if(s[i]!=s[i+m]) { cout<<"NO"<<endl; return; }
    }

    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}