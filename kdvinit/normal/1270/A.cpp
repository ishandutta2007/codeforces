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
    int n,k1,k2;
    cin>>n>>k1>>k2;

    int p1=0,x;
    for(int i=1;i<=k1;i++)
    {
        cin>>x;
        if(x==n) p1=1;
    }

    for(int i=1;i<=k2;i++) cin>>x;

    if(p1==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}