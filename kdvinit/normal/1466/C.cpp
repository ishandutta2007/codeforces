/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    string s;
    cin>>s;

    int n=s.size();

    int ans=0;
    if(s[1]==s[0]) { s[1]='?'; ans++; }

    for(int i=2;i<n;i++)
    {
        if(s[i]==s[i-1] || s[i]==s[i-2]) { s[i]='?'; ans++; }
    }
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}