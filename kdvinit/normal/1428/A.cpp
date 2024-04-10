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
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    a=abs(a-c);
    b=abs(b-d);

    if(a==0) { cout<<b<<endl; return; }
    if(b==0) { cout<<a<<endl; return; }
    cout<<a+b+2<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}