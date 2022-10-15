/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s, t;
    cin>>s>>t;

    int ls = s.size();
    int lt = t.size();

    int ps=0;
    int pt=0;

    int dif = abs(ls-lt);
    if(dif%2==1) ps=1;

    int last=ps-1;
    for(int i=ps; i<ls; i++)
    {
        if(pt==lt) break;
        if(s[i]!=t[pt]) continue;
        dif = i-last-1;
        if(dif%2!=0) continue;
        pt++;
        last=i;
    }

    if(pt==lt) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}