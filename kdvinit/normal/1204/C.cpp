/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int sd[101][101];
int a[101][101];
int n;

int infy=1e20;

void find_sd(int src)
{
    sd[src][src]=0;
    int used[n+1]={0};
    for(int j=1;j<=n;j++)
    {
        int mn=infy,key;
        for(int i=1;i<=n;i++)
        {
            if(used[i]==1) continue;
            if(sd[src][i]<=mn)
            {
                mn=sd[src][i];
                key=i;
            }
        }
        used[key]=1;

        for(int i=1;i<=n;i++)
        {
            if(used[i]==1 || a[key][i]==0) continue;
            sd[src][i]=min(sd[src][i],sd[src][key]+1);
        }
    }
}

void solve()
{
    cin>>n;

    char x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           cin>>x;
           a[i][j]=x-48;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) sd[i][j]=infy;
    }

    for(int i=1;i<=n;i++) find_sd(i);

    int m; cin>>m;
    int y,z;

    int path[m+1];
    for(int i=1;i<=m;i++)
    {
        cin>>path[i];
    }

    int poss[m+1],cnt=m;
    for(int i=1;i<=m;i++) poss[i]=1;

    for(int i=2;i<m;i++)
    {
        y=path[i-1];
        z=path[i+1];
        if(a[y][z]==0 && y!=z)
        {
            int cnt2=1;
            while( i<m && sd[y][path[i+1]]>cnt2 && path[i+1]!=y)
            {
                poss[i]=0;
                cnt--;
                cnt2++;
                i++;
            }
        }
    }

    cout<<cnt<<endl;
    for(int i=1;i<=m;i++)
    {
        if(poss[i]==1) cout<<path[i]<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}