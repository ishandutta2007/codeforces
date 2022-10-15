/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5+10;

vector<int> adj[N];
int leaf[N], tot, cnt, xtra;

bool DFS(int chi, int par)
{
    if(leaf[chi]==1) return true;

    bool pos=0;
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        if(DFS(x, chi)) pos=1;
    }

    if(par==-1) return pos;

    if(pos) { cnt++; return false; }
    else { xtra++; return true; }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++) { adj[i].clear(); leaf[i]=0; }

    tot=0;
    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=2; i<=n; i++)
    {
        if(adj[i].size()==1) { leaf[i]=1; tot++; }
    }

    cnt=0;
    xtra=0;
    int root=DFS(1, -1);;

    tot+=xtra;
    tot-=cnt;

    if(root==0) tot++;
    cout<<tot<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}