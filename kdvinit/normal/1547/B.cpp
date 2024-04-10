/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s; cin>>s;
    int n = s.size();

    int strt=0, nd=n-1;
    for(int i=n; i>=1; i--)
    {
        char x = 'a'+i-1;
        if(s[strt]==x) { strt++; continue; }
        if(s[nd]==x) { nd--; continue; }
        cout<<"NO"<<endl;
        return;
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