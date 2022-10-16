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

    vector<int> edges;

    int freq[3*n+1]={0};
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(edges.size()==n) continue;

        if(freq[x]==1 || freq[y]==1) continue;
        edges.push_back(i);
        freq[x]=1;
        freq[y]=1;
    }

    if(edges.size()==n)
    {
        cout<<"Matching"<<endl;
        for(int i=1;i<=n;i++) cout<<edges[i-1]<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"IndSet"<<endl;
        int cnt=0;
        for(int i=1;i<=3*n;i++)
        {
            if(freq[i]==1) continue;
            cout<<i<<" ";
            cnt++;
            if(cnt==n) break;
        }
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