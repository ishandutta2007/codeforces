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

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++) { a[i]-=i; a[i]+=(2e5); }

    int mx=6e5;
    int freq[mx+1]={0};

    for(int i=1;i<=n;i++)
    {
        freq[a[i]]+=(a[i]+i-2e5);
    }

    int ans=0;
    for(int i=0;i<=mx;i++)
    {
        ans=max(ans,freq[i]);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}