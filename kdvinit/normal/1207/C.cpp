/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, a, b;
    cin>>n>>a>>b;

    string s;
    cin>>s;

    int strt=0;
    while(strt<n && s[strt]=='0') strt++;

    int nd=n-1;
    while(nd>=0 && s[nd]=='0') nd--;

    int ans=a*n + b*(n+1);

    if(strt==n)
    {
        cout<<ans<<endl;
        return;
    }

    ans += (a+a+b);


    for(int i=strt; i<=nd; i++)
    {
        if(s[i]=='1') { ans+=b; continue; }

        int j=i;
        while(s[j]=='0') j++;

        int len = j-i;

        ans += min(2*a+b, len*b);
        i=j-1;
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