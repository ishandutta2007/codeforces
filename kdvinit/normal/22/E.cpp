/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 1;
const int mod = 1e9 + 7;

vector<int> adj[N];
vector<int> adj2[N];
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

int par_comp[N];
int comp_vis[N]={0};

void DFS_comp(int chi, int root)
{
    par_comp[chi]=root;
    comp_vis[chi]=1;
    for(auto x: adj2[chi])
    {
        if(comp_vis[x]==1) continue;
        DFS_comp(x, root);
    }
}

vector<int> In0[N];
vector<int> Out0[N];

void solve()
{
    cin>>n;
    m=n;

    for(int i=1; i<=n; i++)
    {
        int pf; cin>>pf;
        adj[i].push_back(pf);

        adj2[i].push_back(pf);
        adj2[pf].push_back(i);
    }

    SCC_Compress();

    if(SCC_Nodes.size()==1)
    {
        cout<<0<<endl<<endl;
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(comp_vis[i]==1) continue;
        DFS_comp(i, i);
    }

    for(auto i: SCC_Nodes)
    {
        int pc = par_comp[i];
        if(SCC_adj[i].size()==0) Out0[pc].push_back(i);
        if(SCC_incoming[i].size()==0) In0[pc].push_back(i);
    }

    vector<array<int, 2>> edges;
    vector<int> leaves;
    int lst=-1;

    for(int i=1; i<=n; i++)
    {
        if(Out0[i].size()==0) continue;

        int j=0;
        if(lst!=-1) { edges.push_back({lst, In0[i][j]}); j++; }

        lst = Out0[i][0];
        for(int k=j; k<In0[i].size(); k++) leaves.push_back(In0[i][k]);
    }

    for(auto x: leaves)
    {
        edges.push_back({lst, x});
    }

    cout<<edges.size()<<endl;
    for(auto x: edges) cout<<x[0]<<" "<<x[1]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}