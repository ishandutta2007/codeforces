/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

const int N = 1e6+5;
vector<int> adj[N];
int n, m;

void add_edge(int cx, int cy, int nx, int ny)
{
    int u = (cx-1)*m + cy;
    int v = (nx-1)*m + ny;
    adj[u].push_back(v);
}

int vis[N]={0};

int DFS(int chi)
{
    int ans=1;
    vis[chi]=1;
    for(int x: adj[chi])
    {
        if(vis[x]) continue;
        ans += DFS(x);
    }
    return ans;
}

void solve()
{
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int x; cin>>x;
            for(int k=3; k>=0; k--)
            {
                int y = x%2; x/=2;
                if(y==1) continue;
                int nx = i+dx[k];
                int ny = j+dy[k];
                add_edge(i, j, nx, ny);
            }
        }
    }

    vector<int> ans;
    for(int i=1; i<=(n*m); i++)
    {
        if(vis[i]) continue;
        ans.push_back(DFS(i));
    }

    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}