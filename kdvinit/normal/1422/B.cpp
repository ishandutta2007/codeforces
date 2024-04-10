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

    int a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }

    int ans=0,b[4];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x=a[i][j];
            b[0]=a[i][j];
            b[1]=a[n+1-i][j];
            b[2]=a[i][m+1-j];
            b[3]=a[n+1-i][m+1-j];
            sort(b,b+4);
            int y=b[1];
            ans+=abs(x-y);
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    t=min(t,(int)1000);
    while(t--) solve();
    return 0;
}