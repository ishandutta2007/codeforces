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
    int n,p,k;
    cin>>n>>p>>k;

    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        char x; cin>>x;
        a[i]=x-48;
    }

    int x,y;
    cin>>x>>y;

    int ans=1e20;
    int dp[n+k+1]={0};
    for(int i=n;i>0;i--)
    {
        if(a[i]==0) dp[i]=dp[i+k]+1;
        else dp[i]=dp[i+k];
    }

    for(int i=p;i<=n;i++)
    {
        int temp=((i-p)*y) + dp[i]*x;
        ans=min(ans,temp);
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