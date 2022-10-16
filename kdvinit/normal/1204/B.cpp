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
    int n,l,r;
    cin>>n>>l>>r;

    int mn=1,mx=1,tmp;
    for(int i=1;i<=l;i++) mn*=2;
    for(int i=1;i<=r;i++) mx*=2;
    mn--;
    tmp=mx/2;
    mn+=(n-l)*1;
    mx+=(n-r)*tmp;
    mx--;
    cout<<mn<<" "<<mx<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}