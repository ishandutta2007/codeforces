/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 100;

vector<int> adj[N];
int rnk[N];

void DFS(int chi, int par, int ord)
{
    rnk[chi]=ord;
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS(x, chi, ord+1);
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++) adj[i].clear();

    int deg[n+1]={0}, uu[n+1], vv[n+1];
    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin>>u>>v;

        deg[u]++;
        deg[v]++;

        adj[u].push_back(v);
        adj[v].push_back(u);

        uu[i]=u;
        vv[i]=v;
    }

    int root=-1;

    for(int i=1; i<=n; i++)
    {
        if(deg[i]>2) { cout<<-1<<endl; return; }
        if(deg[i]==1) root=i;
    }

    DFS(root, -1, 0);

    for(int i=1; i<=n-1; i++)
    {
        int u=uu[i], v=vv[i];
        int x = min(rnk[u], rnk[v]);
        if(x%2==0) cout<<2<<" ";
        else cout<<3<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}