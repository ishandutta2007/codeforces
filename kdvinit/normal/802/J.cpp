/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100 + 1;
int ans=0;
vector< array<int, 2> > adj[N];

void DFS(int c, int p, int sum)
{
    ans = max(ans, sum);
    for(auto x: adj[c])
    {
        int v = x[0];
        int w = x[1];

        if(v==p) continue;
        DFS(v, c, sum+w);
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n-1; i++)
    {
        int u, v, c;
        cin>>u>>v>>c;
        adj[u].push_back( {v, c} );
        adj[v].push_back( {u, c} );
    }

    DFS(0, -1, 0);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}