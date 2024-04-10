/*
K.D. Vinit
*/
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n,l=0,x,y;
    cin>>n;

    double s;
    cin>>s;

    vector< vector<int> > adj(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==1) l++;
    }

    s*=2;
    s/=(double)l;

    cout<<s<<endl;
}

int32_t main()
{
    std::cout << std::setprecision(15);
    std::cout << std::fixed;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}