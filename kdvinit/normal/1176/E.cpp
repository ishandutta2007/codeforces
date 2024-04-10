#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> edges[200001];
bool visited[200001];

vector<int> ans1, ans2;

void dfs(int x, int parity)
{
    if(parity % 2 == 0) ans1.push_back(x);
    else ans2.push_back(x);

    visited[x] = true;

    for(int c : edges[x])
    {
        if(!visited[c]) dfs(c, parity + 1);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) edges[i].clear();

    while(m--)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for(int i=1; i<=n; i++) visited[i]=0;
    ans1.clear();
    ans2.clear();

    dfs(1, 0);

    if( ans1.size() <= ans2.size() )
    {
        cout<<ans1.size()<<endl;
        for(int x : ans1) cout<<x<<" ";
        cout<<endl;
    }
    else
    {
        cout<<ans2.size()<<endl;
        for(int x : ans2) cout<<x<<" ";
        cout<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}