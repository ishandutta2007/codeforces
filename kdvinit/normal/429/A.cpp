/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 1;
vector<int> adj[N];

int a[N];
int n;

vector<int> Ans;

void DFS(int c, int p, int affect, int not_affect)
{
    a[c]^=affect;
    if(a[c]==1)
    {
        affect^=1;
        Ans.push_back(c);
    }

    for(auto x: adj[c])
    {
        if(x==p) continue;
        DFS(x, c, not_affect, affect);
    }
}

void solve()
{
    cin>>n;

    for(int i=1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++) cin>>a[i];

    int x;
    for(int i=1; i<=n; i++) { cin>>x; a[i]^=x; }

    DFS(1, -1, 0, 0);

    cout<<Ans.size()<<endl;
    for(int i=0; i<Ans.size(); i++) cout<<Ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}