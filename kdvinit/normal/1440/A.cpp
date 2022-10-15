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
    int n,c0,c1,h,ans=0;
    cin>>n>>c0>>c1>>h;
    c0=min(c0,c1+h);
    c1=min(c1,c0+h);

    char x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x=='0') ans+=c0;
        else ans+=c1;
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