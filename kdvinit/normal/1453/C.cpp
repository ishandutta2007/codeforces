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

    int a[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char x; cin>>x;
            a[i][j]=x-48;
        }
    }

    int dr[n+1][10],ans[10]={0};

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=9;j++) dr[i][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int z=a[i][j];
            int x=i-1;
            int y=n-i;
            int w=max(x,y);
            dr[j][z]=max(dr[j][z],w);
        }
    }

    for(int k=0;k<=9;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(dr[i][k]==0) continue;
            for(int j=i+1;j<=n;j++)
            {
                if(dr[j][k]==0) continue;
                int z=a[i][j];
                int y=max(dr[i][k],dr[j][k]);
                int w=y*(j-i);
                ans[k]=max(ans[k],w);
            }
        }
    }

    int dc[n+1][10];

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=9;j++) dc[i][j]=0;
    }

    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            int z=a[i][j];
            int x=j-1;
            int y=n-j;
            int w=max(x,y);
            dc[i][z]=max(dc[i][z],w);
        }
    }

    for(int k=0;k<=9;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(dc[i][k]==0) continue;
            for(int j=i+1;j<=n;j++)
            {
                if(dc[j][k]==0) continue;
                int y=max(dc[i][k],dc[j][k]);
                int w=y*(j-i);
                ans[k]=max(ans[k],w);
            }
        }
    }

    for(int k=0;k<=9;k++) cout<<ans[k]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}