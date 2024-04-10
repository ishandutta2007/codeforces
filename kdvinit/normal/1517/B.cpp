/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin>>n>>m;

    priority_queue< array<int, 3> > pq;

    int b[n+1][m+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>b[i][j];
            pq.push({-b[i][j], i, j});
        }
    }

    int ans[n+1][m+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) ans[i][j]=0;
    }

    int spec[m+1];

    for(int i=1; i<=m; i++)
    {
        auto x=pq.top();
        pq.pop();

        ans[x[1]][i] = -x[0];
        spec[i] = x[1];
    }

    int pos[n+1]={0};

    while(!pq.empty())
    {
        auto x=pq.top();
        pq.pop();

        int i = x[1];
        int w = -x[0];

        pos[i]++;
        while(ans[i][pos[i]]!=0) pos[i]++;
        ans[i][pos[i]]=w;
    }


    /*
    for(int i=1; i<=m; i++)
    {
        cout<<i<<" -> "<<spec[i]<<endl;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }


    for(int i=1; i<=n; i++)
    {
        int k=1;
        for(int j=1; j<=m; j++)
        {
            if(i==spec[j]) continue;

            while(ans[i][k]!=0) k++;
            ans[i][k]=j;
        }
    }
    */

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}