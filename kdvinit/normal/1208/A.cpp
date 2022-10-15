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
    int a,b,c,n;
    cin>>a>>b>>n;

    c=a^b;
    if(n%3==0) cout<<a<<endl;
    if(n%3==1) cout<<b<<endl;
    if(n%3==2) cout<<c<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}