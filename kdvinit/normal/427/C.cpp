/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 1;
const int mod = 1e9 + 7;

vector<int> adj[N];
int n, m;



/**SCC Starts**/

//KDVinit's Implementation for Tarjan's Algorithm (GFG)
//Global Variables for SCC,
//This will additionally use N = max, adj[N] for edges,
//and n, m for number of nodes and edges respectively.

//Outputs of the Tarjan's Algorithm
vector<int> SCC_Nodes;          //Nodes from main graph that are heads of SCC.
vector<int> SCC_Component[N];   //Vertexes in the SCC Component of a head node.
vector<int> SCC_adj[N];         //Adj list in SCC compressed, outgoing edges.
vector<int> SCC_incoming[N];    //Adj list in SCC compressed, incoming edges.
int SCC_par[N];                 //SCC Head of a node from original graph.

//Helpers
int disc[N], low[N], In_stk[N], SCC_time;
stack<int> stk;

//Helper DFS for SCC
void SCC_DFS(int chi)
{
    //Assigns the low and disc values
    SCC_time++;
    disc[chi]=SCC_time; low[chi]=SCC_time;
    stk.push(chi); In_stk[chi]=1;       //Put them in Stack

    //Runs DFS
    for(auto x: adj[chi])
    {
        if(disc[x]==-1) { SCC_DFS(x); low[chi] = min(low[chi], low[x]); }
        else if(In_stk[x]==1) low[chi] = min(low[chi], disc[x]);
    }

    //if low = disc, it is the head node, and thus extracts the subtree
    if(low[chi]==disc[chi])
    {
        int w;  SCC_Nodes.push_back(chi);   SCC_Component[chi].push_back(chi);
        while(stk.top()!=chi)
        {
            w=stk.top(); stk.pop();
            SCC_par[w]=chi; In_stk[w]=0; SCC_Component[chi].push_back(w);
        }
        stk.pop(); In_stk[chi]=0; SCC_par[chi]=chi;
    }
}

//Main Function for SCC.
void SCC_Compress()
{
    //Initializes Containers
    while(!stk.empty()) stk.pop();    SCC_Nodes.clear();  SCC_time=0;
    for(int i=1; i<=n; i++) { disc[i]=-1; In_stk[i]=0; SCC_adj[i].clear(); }

    //SCC_DFS from vertex unvisited
    for(int i=1; i<=n; i++) if(disc[i]==-1) SCC_DFS(i);

    //To add edges to SCC Compressed
    for(int i=1; i<=n; i++)
    {
        for(auto x: adj[i])
        {
            int su = SCC_par[i], sv = SCC_par[x];       //Head of SCC comp
            if(su==sv) continue;        //Belong to same comp
            SCC_adj[su].push_back(sv);
            SCC_incoming[sv].push_back(su);
        }
    }
}

/**SCC Ends**/

void solve()
{
    cin>>n;

    int cost[n+1];
    for(int i=1; i<=n; i++) cin>>cost[i];

    cin>>m;
    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    SCC_Compress();

    int min_cost=0, ways=1;
    for(auto x: SCC_Nodes)
    {
        int tmp_min=1e10, cnt=0;
        for(auto y: SCC_Component[x])
        {
            if(cost[y]>tmp_min) continue;
            if(cost[y]==tmp_min) { cnt++; continue;}
            tmp_min=cost[y]; cnt=1;
        }
        min_cost+=tmp_min;
        ways*=cnt;
        ways%=mod;
    }

    cout<<min_cost<<" "<<ways<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}