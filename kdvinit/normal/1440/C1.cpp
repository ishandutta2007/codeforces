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

    int nm=n*m;

    int ans[3*nm+1][7],cnt=1;
    int a[n+1][m+1];
    char x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) { cin>>x; a[i][j]=x-48; }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(a[i][j]==1)
            {
                ans[cnt][1]=i;
                ans[cnt][2]=j;
                ans[cnt][3]=i+1;
                ans[cnt][4]=j;
                ans[cnt][5]=i;
                ans[cnt][6]=j+1;
                cnt++;
                ans[cnt][1]=i;
                ans[cnt][2]=j;
                ans[cnt][3]=i+1;
                ans[cnt][4]=j;
                ans[cnt][5]=i+1;
                ans[cnt][6]=j+1;
                cnt++;
                ans[cnt][1]=i;
                ans[cnt][2]=j;
                ans[cnt][3]=i;
                ans[cnt][4]=j+1;
                ans[cnt][5]=i+1;
                ans[cnt][6]=j+1;
                cnt++;
            }
        }
    }

    for(int i=n;i<=n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(a[i][j]==1)
            {
                ans[cnt][1]=i;
                ans[cnt][2]=j;
                ans[cnt][3]=i-1;
                ans[cnt][4]=j;
                ans[cnt][5]=i;
                ans[cnt][6]=j+1;
                cnt++;
                ans[cnt][1]=i;
                ans[cnt][2]=j;
                ans[cnt][3]=i-1;
                ans[cnt][4]=j;
                ans[cnt][5]=i-1;
                ans[cnt][6]=j+1;
                cnt++;
                ans[cnt][1]=i;
                ans[cnt][2]=j;
                ans[cnt][3]=i;
                ans[cnt][4]=j+1;
                ans[cnt][5]=i-1;
                ans[cnt][6]=j+1;
                cnt++;
            }
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=m;j<=m;j++)
        {
            if(a[i][j]==1)
            {
                ans[cnt][1]=i;
                ans[cnt][2]=j;
                ans[cnt][3]=i+1;
                ans[cnt][4]=j;
                ans[cnt][5]=i;
                ans[cnt][6]=j-1;
                cnt++;
                ans[cnt][1]=i;
                ans[cnt][2]=j;
                ans[cnt][3]=i+1;
                ans[cnt][4]=j;
                ans[cnt][5]=i+1;
                ans[cnt][6]=j-1;
                cnt++;
                ans[cnt][1]=i;
                ans[cnt][2]=j;
                ans[cnt][3]=i;
                ans[cnt][4]=j-1;
                ans[cnt][5]=i+1;
                ans[cnt][6]=j-1;
                cnt++;
            }
        }
    }

    for(int i=n;i<=n;i++)
    {
        for(int j=m;j<=m;j++)
        {
            if(a[i][j]==1)
            {
                ans[cnt][1]=i;
                ans[cnt][2]=j;
                ans[cnt][3]=i-1;
                ans[cnt][4]=j;
                ans[cnt][5]=i;
                ans[cnt][6]=j-1;
                cnt++;
                ans[cnt][1]=i;
                ans[cnt][2]=j;
                ans[cnt][3]=i-1;
                ans[cnt][4]=j;
                ans[cnt][5]=i-1;
                ans[cnt][6]=j-1;
                cnt++;
                ans[cnt][1]=i;
                ans[cnt][2]=j;
                ans[cnt][3]=i;
                ans[cnt][4]=j-1;
                ans[cnt][5]=i-1;
                ans[cnt][6]=j-1;
                cnt++;
            }
        }
    }

    cnt--;
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