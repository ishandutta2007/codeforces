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
    int n,m,ans=0;
    cin>>n;

    m=n%10;
    m--;
    while(n!=0) { ans++; n/=10; }
    ans=(ans*(ans+1))/2;
    ans+=(m*10);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}