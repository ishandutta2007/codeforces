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

    int sum1=0,sum2=0,ans1=0,ans2=0,ans;

    int r[n+2];
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        sum1+=r[i];
        ans1=max(ans1,sum1);
    }

    int m; cin>>m;

    int b[m+2];
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        sum2+=b[i];
        ans2=max(ans2,sum2);
    }

    ans=ans1+ans2;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}