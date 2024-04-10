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

    int done = 0;
    for(int i=n-1; i>0; i--)
    {
        int x = (s[i]-'0') + (s[i-1]-'0');
        if(x<10) continue;
        s[i-1] = ((x/10) + '0');
        s[i] = ((x%10) + '0');
        done = 1;
        break;
    }

    if(done==1) { cout<<s<<endl; return; }

    int x = (s[0]-'0') + (s[1]-'0');
    cout<<x;
    for(int i=2; i<n; i++) cout<<s[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}