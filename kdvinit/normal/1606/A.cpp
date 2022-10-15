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

    int cnta=0, cntb=0;
    for(int i=1; i<n; i++)
    {
        if(s[i]==s[i-1]) continue;
        if(s[i]=='b') cntb++;
        else cnta++;
    }

    if(cnta<cntb) s[n-1]='a';
    if(cnta>cntb) s[n-1]='b';
    cout<<s<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}