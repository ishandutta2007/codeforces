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
    int n,x;
    cin>>n>>x;

    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    for(int i=1;i<=n;i++)
    {
        if(a[i]+b[n+1-i]>x) { cout<<"NO"<<endl; return; }
    }
    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}