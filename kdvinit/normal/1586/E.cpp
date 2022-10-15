/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mxn = (4e5)+100;

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

const int N = (4e5)+100;

vector<int> adj[N];
int a[N];
map<pair<int, int>, int> mp;
vector< vector<int> > paths;
vector<int> curp;

bool DFS(int chi, int par, int til)
{
    if(chi==til)
    {
        curp.push_back(chi);
        return true;
    }
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        if(DFS(x, chi, til))
        {
            mp[{chi, x}]++;
            mp[{x, chi}]++;
            curp.push_back(chi);
            return true;
        }
    }
    return false;
}

vector<int> adj2[N];
int vis[N]={0};
int mx;

void DFS2(int chi, int par)
{
    int tmp = adj2[chi].size();
    if(tmp%2==1) mx++;
    vis[chi]=1;
    for(auto x: adj2[chi])
    {
        if(x==par) continue;
        DFS2(x, chi);
    }
}

int get_it(int n)
{
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==1) continue;
        mx=0;
        DFS2(i, -1);
        int tmp = mx/2;
        ans+=tmp;
    }
    return ans;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++) make_set(i);
    for(int i=1; i<=n; i++) adj[i].clear();
    for(int i=1; i<=n; i++) adj2[i].clear();

    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        if(union_sets(u, v)) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++) a[i]=0;

    paths.clear();
    int q; cin>>q;
    while(q--)
    {
        int x, y;
        cin>>x>>y;
        curp.clear();
        DFS(y, -1, x);
        paths.push_back(curp);
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int x: adj[i])
        {
            int y = mp[{i, x}];
            if((y%2)==1)
            {
                ans++;
                adj2[i].push_back(x);
            }
        }
    }

    if(ans==0)
    {
        cout<<"YES"<<endl;
        for(auto x: paths)
        {
            cout<<x.size()<<endl;
            for(int y: x) cout<<y<<" ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
        ans = get_it(n);
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}