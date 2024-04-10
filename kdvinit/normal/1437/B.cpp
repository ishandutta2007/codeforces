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
    int n;
    cin>>n;

    string s;
    cin>>s;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1]) ans++;
    }
    ans++;
    ans/=2;
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}