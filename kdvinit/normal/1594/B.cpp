/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 1e9 + 7;

void solve()
{
    int n, k;
    cin>>n>>k;

    int ans=0, mul=1;

    while(k!=0)
    {
        if(k%2==1) { ans+=mul; ans%=mod; }
        mul*=n; mul%=mod;
        k/=2;
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