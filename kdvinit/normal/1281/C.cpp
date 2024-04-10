/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int mod = 1e9 + 7;

void solve()
{
    int x; cin>>x;

    string s; cin>>s;
    int n=s.size();

    int len=n;
    int i=-1;
    while(len<x)
    {
        i++;
        if(s[i]=='1') continue;
        string suf = s.substr(i+1, len-i-1);
        int xtra = len-i-1;
        if(s[i]=='2') { s+=suf; len+=xtra;}
        if(s[i]=='3') { s+=suf; s+=suf; len+=xtra; len+=xtra;}
    }

    while(1)
    {
        i++;
        len+=((len-i-1)*(s[i]-'1'));
        while(len<0) len+=mod;
        len%=mod;
        if(i+1==x) break;
    }

    cout<<len<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}