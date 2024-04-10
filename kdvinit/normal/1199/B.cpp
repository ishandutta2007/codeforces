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
    double h,l,ans=0;
    cin>>h>>l;

    ans+=l*l;
    ans+=h*h;
    ans/=(2*h);
    ans-=h;

    cout<<ans<<endl;
}

int32_t main()
{
    std::cout << std::setprecision(15); std::cout << std::fixed;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}