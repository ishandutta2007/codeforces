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

    int a[n+2]={0},b[n+1],c[n+2]={0};
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    vector< pair<int,int> > vv;
    for(int i=1;i<=n;i++) vv.push_back({a[i],b[i]});
    sort(vv.begin(),vv.end());
    sort(a+1,a+n+1);

    for(int i=n;i>0;i--) c[i]=c[i+1]+vv[i-1].second;

    int ans=a[n];
    for(int i=0;i<=n;i++) ans=min(ans, max(a[i],c[i+1]) );

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}