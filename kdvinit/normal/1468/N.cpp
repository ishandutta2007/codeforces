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
    int c1,c2,c3;
    cin>>c1>>c2>>c3;

    int a1,a2,a3,a4,a5;
    cin>>a1>>a2>>a3>>a4>>a5;

    if(c1<a1 || c2<a2 || c3<a3) { cout<<"NO"<<endl; return; }
    c1-=a1;
    c2-=a2;
    c3-=a3;

    if(c1>a4) a4=0;
    else a4-=c1;

    if(c2>a5) a5=0;
    else a5-=c2;

    int z=a4+a5;

    if(c3>=z) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}