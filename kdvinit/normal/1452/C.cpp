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

    int ans=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') cnt1++;
        if(s[i]==')' && cnt1>0) { cnt1--; ans++; }
        if(s[i]=='[') cnt2++;
        if(s[i]==']' && cnt2>0) { cnt2--; ans++; }
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