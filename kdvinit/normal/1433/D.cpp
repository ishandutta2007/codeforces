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
    int n,cnt=0,p2=0;
    cin>>n;
    
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=a[1]) p2=i;
    }
    
    if(p2==0) { cout<<"NO"<<endl; return; }
    cout<<"YES"<<endl;
    
    cout<<1<<" "<<p2<<endl;
    for(int i=2;i<=n;i++)
    {
        if(i==p2) continue;
        if(a[i]!=a[1]) cout<<1<<" "<<i<<endl;
        else cout<<p2<<" "<<i<<endl;
    }
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}