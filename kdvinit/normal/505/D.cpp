/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 1;
vector<int> adj[N];
vector<int> adj2[N];

int n, m;



/**SCC Starts**/
//Global Variables for SCC,
//This will additionally use N = max, adj[N] for edges,
//and n, m for number of nodes and edges respectively.

vector<int> SCC_Nodes;      //Nodes from main graph that are part of SCC.
vector<int> SCC_Components[N];  //Strongly Connected Components of main Graph.
vector<int> SCC_adj[N];     //Adj list in SCC compressed.
int SCC_par[N];             //SCC Head of a node from original graph.

int disc[N], low[N], In_stk[N], SCC_time;       //Helpers
stack<int> stk;

//Helper DFS for SCC
void SCC_DFS(int chi)
{
    SCC_time++;
    disc[chi]=SCC_time; low[chi]=SCC_time;
    stk.push(chi); In_stk[chi]=1;

    for(auto x: adj[chi])
    {
        if(disc[x]==-1) { SCC_DFS(x); low[chi] = min(low[chi], low[x]); }
        else if(In_stk[x]==1) low[chi] = min(low[chi], disc[x]);
    }

    if(low[chi]==disc[chi])
    {
        int w;  SCC_Nodes.push_back(chi);   SCC_Components[chi].push_back(chi);
        while(stk.top()!=chi)
        {
            w=stk.top(); stk.pop();
            SCC_par[w]=chi; In_stk[w]=0; SCC_Components[chi].push_back(w);
        }
        stk.pop(); In_stk[chi]=0; SCC_par[chi]=chi;
    }
}

//Main Function for SCC.
void SCC_Compress()
{
    while(!stk.empty()) stk.pop();    SCC_Nodes.clear();  SCC_time=0;
    for(int i=1; i<=n; i++) { disc[i]=-1; In_stk[i]=0; SCC_adj[i].clear(); }
    for(int i=1; i<=n; i++) if(disc[i]==-1) SCC_DFS(i);
}
/**SCC Ends**/

//To find number of connected components
int vis[N]={0};
int par_comp[N];
int DFS_comp(int chi, int root)
{
    par_comp[chi]=root;
    int ans = 1;
    vis[chi] = 1;
    for(auto x: adj2[chi])
    {
        if(vis[x]==1) continue;
        ans += DFS_comp(x, root);
    }
    return ans;
}

void solve()
{
    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);

        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    SCC_Compress();

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==1) continue;
        int tmp = DFS_comp(i, i);
        ans += (tmp - 1);
    }

    int freq[n+1]={0};
    for(auto x: SCC_Nodes)
    {
        if(SCC_Components[x].size()>1 && freq[par_comp[x]]==0)
        {
            freq[par_comp[x]]=1;
            ans++;
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}