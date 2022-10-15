/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int ans[20001][7],cnt;

void input(int x1,int x2,int x3,int x4,int x5,int x6)
{
    cnt++;
    ans[cnt][1]=x1;
    ans[cnt][2]=x2;
    ans[cnt][3]=x3;
    ans[cnt][4]=x4;
    ans[cnt][5]=x5;
    ans[cnt][6]=x6;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    int nm=n*m;

    cnt=0;
    int a[n+1][m+1];
    char x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) { cin>>x; a[i][j]=x-48; }
    }

    if(n%2==0 && m%2==0)
    {
        for(int i=1;i<=n;i+=2)
        {
            for(int j=1;j<=m;j+=2)
            {
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    continue;
                }
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i+1,j+1,i+1,j,i,j+1);
                    input(i+1,j+1,i+1,j,i,j);
                    input(i+1,j+1,i,j,i,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i+1,j,i+1,j+1,i,j);
                    input(i+1,j,i,j+1,i,j);
                    input(i+1,j,i+1,j+1,i,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    input(i+1,j,i,j+1,i,j);
                    input(i+1,j,i+1,j+1,i,j+1);
                    input(i,j,i+1,j+1,i,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i,j,i+1,j,i+1,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i,j,i+1,j,i+1,j+1);
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j+1,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    input(i+1,j,i+1,j+1,i,j);
                    input(i+1,j,i,j+1,i,j);
                    input(i,j,i+1,j+1,i,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i,j+1,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i,j+1,i+1,j,i+1,j+1);
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    input(i,j+1,i+1,j,i+1,j+1);
                    input(i,j,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i,j,i,j+1,i+1,j);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i+1,j+1,i+1,j,i,j+1);
                    input(i+1,j+1,i+1,j,i,j);
                    input(i+1,j+1,i,j,i,j+1);
                }
            }
        }

    }
    if(n%2==0 && m%2==1)
    {
        if(a[n][m]==1)
        {
            input(n,m,n,m-1,n-1,m-1);
            a[n][m-1]=(a[n][m-1]+1)%2;
            a[n-1][m-1]=(a[n-1][m-1]+1)%2;
        }
        for(int i=1;i<n;i++)
        {
            if(a[i][m]==1)
            {
                input(i,m,i,m-1,i+1,m-1);
                a[i][m-1]=(a[i][m-1]+1)%2;
                a[i+1][m-1]=(a[i+1][m-1]+1)%2;
            }
        }

        for(int i=1;i<=n;i+=2)
        {
            for(int j=1;j<m;j+=2)
            {
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    continue;
                }
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i+1,j+1,i+1,j,i,j+1);
                    input(i+1,j+1,i+1,j,i,j);
                    input(i+1,j+1,i,j,i,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i+1,j,i+1,j+1,i,j);
                    input(i+1,j,i,j+1,i,j);
                    input(i+1,j,i+1,j+1,i,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    input(i+1,j,i,j+1,i,j);
                    input(i+1,j,i+1,j+1,i,j+1);
                    input(i,j,i+1,j+1,i,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i,j,i+1,j,i+1,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i,j,i+1,j,i+1,j+1);
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j+1,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    input(i+1,j,i+1,j+1,i,j);
                    input(i+1,j,i,j+1,i,j);
                    input(i,j,i+1,j+1,i,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i,j+1,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i,j+1,i+1,j,i+1,j+1);
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    input(i,j+1,i+1,j,i+1,j+1);
                    input(i,j,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i,j,i,j+1,i+1,j);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i+1,j+1,i+1,j,i,j+1);
                    input(i+1,j+1,i+1,j,i,j);
                    input(i+1,j+1,i,j,i,j+1);
                }
            }
        }

    }
    if(n%2==1 && m%2==0)
    {
        if(a[n][m]==1)
        {
            input(n,m,n,m-1,n-1,m-1);
            a[n][m-1]=(a[n][m-1]+1)%2;
            a[n-1][m-1]=(a[n-1][m-1]+1)%2;
        }
        for(int j=1;j<m;j++)
        {
            if(a[n][j]==1)
            {
                input(n,j,n-1,j+1,n-1,j);
                a[n-1][j]=(a[n-1][j]+1)%2;
                a[n-1][j+1]=(a[n-1][j+1]+1)%2;
            }
        }

        for(int i=1;i<n;i+=2)
        {
            for(int j=1;j<=m;j+=2)
            {
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    continue;
                }
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i+1,j+1,i+1,j,i,j+1);
                    input(i+1,j+1,i+1,j,i,j);
                    input(i+1,j+1,i,j,i,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i+1,j,i+1,j+1,i,j);
                    input(i+1,j,i,j+1,i,j);
                    input(i+1,j,i+1,j+1,i,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    input(i+1,j,i,j+1,i,j);
                    input(i+1,j,i+1,j+1,i,j+1);
                    input(i,j,i+1,j+1,i,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i,j,i+1,j,i+1,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i,j,i+1,j,i+1,j+1);
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j+1,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    input(i+1,j,i+1,j+1,i,j);
                    input(i+1,j,i,j+1,i,j);
                    input(i,j,i+1,j+1,i,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i,j+1,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i,j+1,i+1,j,i+1,j+1);
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    input(i,j+1,i+1,j,i+1,j+1);
                    input(i,j,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i,j,i,j+1,i+1,j);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i+1,j+1,i+1,j,i,j+1);
                    input(i+1,j+1,i+1,j,i,j);
                    input(i+1,j+1,i,j,i,j+1);
                }
            }
        }

    }
    if(n%2==1 && m%2==1)
    {
        if(a[n][m]==1)
        {
            input(n,m,n,m-1,n-1,m-1);
            a[n][m-1]=(a[n][m-1]+1)%2;
            a[n-1][m-1]=(a[n-1][m-1]+1)%2;
        }
        for(int i=1;i<n;i++)
        {
            if(a[i][m]==1)
            {
                input(i,m,i,m-1,i+1,m-1);
                a[i][m-1]=(a[i][m-1]+1)%2;
                a[i+1][m-1]=(a[i+1][m-1]+1)%2;
            }
        }
        for(int j=1;j<m-1;j++)
        {
            if(a[n][j]==1)
            {
                input(n,j,n-1,j+1,n-1,j);
                a[n-1][j]=(a[n-1][j]+1)%2;
                a[n-1][j+1]=(a[n-1][j+1]+1)%2;
            }
        }
        if(a[n][m-1]==1)
        {
            input(n,m-1,n-1,m-1,n-1,m-2);
            a[n-1][m-1]=(a[n-1][m-1]+1)%2;
            a[n-1][m-2]=(a[n-1][m-2]+1)%2;
        }

        for(int i=1;i<n;i+=2)
        {
            for(int j=1;j<m;j+=2)
            {
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    continue;
                }
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i+1,j+1,i+1,j,i,j+1);
                    input(i+1,j+1,i+1,j,i,j);
                    input(i+1,j+1,i,j,i,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i+1,j,i+1,j+1,i,j);
                    input(i+1,j,i,j+1,i,j);
                    input(i+1,j,i+1,j+1,i,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    input(i+1,j,i,j+1,i,j);
                    input(i+1,j,i+1,j+1,i,j+1);
                    input(i,j,i+1,j+1,i,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i,j,i+1,j,i+1,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i,j,i+1,j,i+1,j+1);
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==0 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j+1,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    input(i+1,j,i+1,j+1,i,j);
                    input(i+1,j,i,j+1,i,j);
                    input(i,j,i+1,j+1,i,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i,j+1,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i,j+1,i+1,j,i+1,j+1);
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    input(i,j+1,i+1,j,i+1,j+1);
                    input(i,j,i+1,j,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j+1);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    input(i,j,i,j+1,i+1,j);
                }
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    input(i,j,i,j+1,i+1,j);
                    input(i+1,j+1,i+1,j,i,j+1);
                    input(i+1,j+1,i+1,j,i,j);
                    input(i+1,j+1,i,j,i,j+1);
                }
            }
        }

    }

    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=1;j<=6;j++)cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}