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

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int cnt=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i+1]) cnt++;
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt==0) break;

        if(i<n && a[i]>a[i+1] && x<=a[i+1]) cnt--;

        if(a[i]>x) { swap(a[i],x); ans++; }
    }

    if(cnt!=0) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}