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

    int a[n+1],b[n+1],c[n+1],p[n+1];

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];

    p[1]=a[1];
    for(int i=2;i<n;i++)
    {
        if(a[i]!=p[i-1]) p[i]=a[i];
        else p[i]=b[i];
    }

    if(p[n-1]!=a[n] && p[1]!=a[n]) p[n]=a[n];
    else if(p[n-1]!=b[n] && p[1]!=b[n]) p[n]=b[n];
    else p[n]=c[n];

    for(int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}