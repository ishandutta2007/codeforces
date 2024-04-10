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

    int a[n+1],mn=k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) mn=min(mn,a[i]);

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=k-a[i];
        x/=mn;
        ans+=x;
    }
    int x=k-mn;
    x/=mn;
    ans-=x;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}