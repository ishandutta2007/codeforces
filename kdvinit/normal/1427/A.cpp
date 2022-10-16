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
    int n;
    cin>>n;

    int a[n+1],sum=0;
    for(int i=1;i<=n;i++) { cin>>a[i]; sum+=a[i]; }
    sort(a+1,a+n+1);

    if(sum==0) { cout<<"NO"<<endl; return; }

    cout<<"YES"<<endl;
    if(sum<0)
    {
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int i=n;i>0;i--) cout<<a[i]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}