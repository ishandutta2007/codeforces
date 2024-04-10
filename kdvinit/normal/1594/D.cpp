/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mxn = 2e5 + 100;

int parent[mxn];
int siz[mxn];

//use make_set, find_set and union_sets properly
void make_set(int v)
{
    parent[v] = v;
    siz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b) return true;
    if (siz[a] < siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
    return false;
}


const int N = 2e5+100;

vector<int> adj[N];
int vis[N];

int get_max(int root)
{
    int ans[2]={0};
    map<int, int> mp;

    queue<array<int, 2>> qu;
    vis[root]=1;
    qu.push({root, 1});

    set<int> ver;

    while(!qu.empty())
    {
        auto cur = qu.front();
        qu.pop();

        int u = cur[0];
        int d = cur[1]%2;

        ans[d]+=siz[u];
        mp[u] = d;
        ver.insert(u);

        for(int v: adj[u])
        {
            if(vis[v]) continue;
            vis[v]=1;
            qu.push({v, d+1});
        }
    }

    for(int x: ver)
    {
        for(int y: adj[x])
        {
            if(mp[x]==mp[y]) return -1;
        }
    }

    return max(ans[0], ans[1]);
}

void solve()
{
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++) make_set(i);
    for(int i=1; i<=n; i++) adj[i].clear();
    for(int i=1; i<=n; i++) vis[i]=0;

    string imp = "imposter";
    vector<array<int, 2>> edges;

    for(int i=1; i<=m; i++)
    {
        int u, v;
        string c;
        cin>>u>>v>>c;

        if(c==imp) edges.push_back({u, v});
        else union_sets(u, v);
    }

    for(auto x: edges)
    {
        int u = find_set(x[0]);
        int v = find_set(x[1]);
        if(u==v)
        {
            cout<<-1<<endl;
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<int> ver;
    for(int i=1; i<=n; i++) ver.insert(find_set(i));

    int ans=0;
    for(int x: ver)
    {
        if(vis[x]) continue;
        int tmp = get_max(x);
        if(tmp==-1) { cout<<-1<<endl; return; }
        ans += tmp;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}