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

    string s;
    cin>>s;

    int ans=0;
    for(int i=0; i+1<n; i++)
    {
        if(s[i]=='1') continue;
        if(s[i+1]=='0') { ans+=2; continue; }
        if(i+2<n && s[i+2]=='0') ans++;
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