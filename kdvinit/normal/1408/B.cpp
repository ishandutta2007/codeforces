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

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1]) cnt++;
    }

    if(k==1)
    {
        if(cnt==1) cout<<1<<endl;
        else cout<<-1<<endl;
        return;
    }
    
    if(cnt==1) { cout<<1<<endl; return; }

    cnt--;
    k--;
    int ans=((cnt+k-1)/k);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}