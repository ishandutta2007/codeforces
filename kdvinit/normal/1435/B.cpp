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
    int b[n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }

    int used[n*m+1]={0};
    for(int i=1;i<=n;i++)  used[a[i][1]]=1;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x; cin>>x;
            if(used[x]==1) b[j]=x;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j][1]!=b[i]) continue;
            for(int k=1;k<=m;k++) cout<<a[j][k]<<" ";
            cout<<endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}