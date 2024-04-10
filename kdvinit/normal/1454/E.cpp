/*
K.D. Vinit
*/
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int rC2(int r)
{
    return (r*(r-1))/2;
}

void solve()
{
    int n,x,y;
    cin>>n;

    vector< set<int> > adj(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    queue<int> leaf;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==1) leaf.push(i);
    }

    int siz[n+1];
    for(int i=1;i<=n;i++) siz[i]=1;

    while(!leaf.empty())
    {
        int ch=leaf.front();
        leaf.pop();
        int pa= *adj[ch].begin();

        adj[pa].erase(ch);
        siz[pa]+=siz[ch];
        siz[ch]=1;

        if(adj[pa].size()==1) leaf.push(pa);
    }


    int ans=2*rC2(n);
    for(int i=1;i<=n;i++)
    {
        if(siz[i]==1) continue;
        x=siz[i];
        ans-=rC2(x);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}