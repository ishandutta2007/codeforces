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
    int n,m;
    cin>>n>>m;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int nd=n;
    while(nd!=0 && a[nd]==nd) nd--;

    int r[m+1];
    double p[m+1];

    for(int i=1;i<=m;i++) cin>>r[i]>>p[i];

    if(nd==0) { cout<<1<<endl; return; }

    double ans=1;
    for(int i=1;i<=m;i++)
    {
        if(r[i]<nd) continue;
        ans*=((double)1-p[i]);
    }
    ans=1-ans;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    std::cout << std::setprecision(15); std::cout << std::fixed;
    int t;cin>>t;
    while(t--) solve();
    return 0;
}