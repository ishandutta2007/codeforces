/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mxn = 2e5+100;

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

bool check_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b) return true;
    else return false;
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

const int N = 2e5 + 100;

vector<array<int, 2>> adj[N];
int paru[N];
int dep[N];

void DFS(int chi, int par)
{
    for(auto x: adj[chi])
    {
        int gc = x[0];
        int ei = x[1];
        if(gc==par) continue;

        dep[gc]=dep[chi]+1;
        paru[gc] = ei;
        DFS(gc, chi);
    }
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int edge[m+1][2];
    int tree_edge_from[n+1];
    vector<int> blue;

    for(int i=1; i<=n; i++) { make_set(i); adj[i].clear(); }

    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        edge[i][0]=u;
        edge[i][1]=v;

        if(check_sets(u, v)) blue.push_back(i);
        else
        {
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
            union_sets(u, v);
        }
    }

    int l = blue.size();

    if(l<3)
    {
        int a[m+1]={0};
        for(int x: blue) a[x]=1;
        for(int i=1; i<=m; i++) cout<<a[i];
        cout<<endl;
        return;
    }

    set<int> st;
    for(int i: blue)
    {
        st.insert(edge[i][0]);
        st.insert(edge[i][1]);
    }

    l = st.size();

    if(l>3)
    {
        int a[m+1]={0};
        for(int x: blue) a[x]=1;
        for(int i=1; i<=m; i++) cout<<a[i];
        cout<<endl;
        return;
    }

    dep[1]=0;
    DFS(1, -1);

    int ui = blue[2];
    int u = edge[ui][0];
    int v = edge[ui][1];

    if(dep[u]<dep[v]) u=v;
    blue[2] = paru[u];

    int a[m+1]={0};
    for(int x: blue) a[x]=1;
    for(int i=1; i<=m; i++) cout<<a[i];
    cout<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}