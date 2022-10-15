/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n; cin>>n;
    string b; cin>>b;

    string s;
    s.push_back(b[0]);

    for(int i=1; i<n; i++)
    {
        if(b[i]>b[i-1]) break;
        if(b[i]<b[i-1]) { s.push_back(b[i]); continue; }
        if(b[i]==b[i-1])
        {
            if(i==1) break;
            s.push_back(b[i]);
        }

    }

    cout<<s;
    reverse(s.begin(), s.end());
    cout<<s<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}