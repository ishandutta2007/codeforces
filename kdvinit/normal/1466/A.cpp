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

    int freq[100]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            freq[a[j]-a[i]]=1;
        }
    }

    int ans=0;
    for(int i=1;i<=99;i++)
    {
        if(freq[i]!=0) ans++;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}