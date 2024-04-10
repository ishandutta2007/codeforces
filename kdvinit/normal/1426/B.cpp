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

    int a1[n+1],a2[n+1],a3[n+1],a4[n+1];
    for(int i=1;i<=n;i++) cin>>a1[i]>>a2[i]>>a3[i]>>a4[i];

    if(m%2==1) { cout<<"NO"<<endl; return; }

    int flag1=0;
    for(int i=1;i<=n;i++)
    {
        if(a2[i]==a3[i]) flag1=1;
    }

    if(flag1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}