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
    int n,k;
    cin>>n>>k;

    int a[n+1],sum=0;
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+n+1);
    for(int i=1;i<=k+1;i++) sum+=a[n+1-i];

    cout<<sum<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}