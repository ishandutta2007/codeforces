/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 16*(1e5)+10;

vector<int> adj[N];
int num_vertex;



/****************SCC Starts*****************/

//KDVinit's Implementation for Tarjan's Algorithm (GFG)
//Global Variables for SCC,
//This will additionally use N = max, adj[N] for edges,
//and Vertexes are defined from 1 -> num_vertex.

//Outputs of the Tarjan's Algorithm
//vector<int> SCC_Nodes;          //Nodes from main graph that are heads of SCC.
//vector<int> SCC_Component[N];   //Vertexes in the SCC Component of a head node.
int SCC_par[N];                 //SCC Head of a node from original graph.
int SCC_Topo[N];                //Vertex of SCC, Topologically Sorted.
int SCC_Topo_Index[N];           //Index of vertex v in the topological sort.

//Note - Adj List may store multiple edges between 2 vertex
vector<int> SCC_adj[N];         //Adj list in SCC compressed, outgoing edges.
vector<int> SCC_incoming[N];    //Adj list in SCC compressed, incoming edges.

//Helpers
int disc[N], low[N], In_stk[N], SCC_time;
stack<int> stk;

//Helper DFS for SCC
void SCC_DFS(int chi)
{
   //Assigns the low and disc values
   SCC_time++; disc[chi]=SCC_time; low[chi]=SCC_time;
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
       int w; //SCC_Nodes.push_back(chi); SCC_Component[chi].push_back(chi);
       while(stk.top()!=chi)
       {
           w=stk.top();
           stk.pop();
           SCC_par[w]=chi;
           In_stk[w]=0;
           //SCC_Component[chi].push_back(w);
       }
       stk.pop(); In_stk[chi]=0; SCC_par[chi]=chi;
   }
}

void SCC_Toposort()         //Topologically sorts the newly for DAG of SCC
{
    int in_deg[num_vertex+1]={0};
    for(int i=1; i<=num_vertex; i++) in_deg[i] = SCC_incoming[i].size();

    queue<int> topo_qu; int topo_cnt=0;
    for(int i=1; i<=num_vertex; i++) if(in_deg[i]==0) topo_qu.push(i);

    while(!topo_qu.empty())
    {
        int node = topo_qu.front(); topo_qu.pop();
        SCC_Topo[++topo_cnt] = (node);
        for(auto x: SCC_adj[node]) { in_deg[x]--; if(in_deg[x]==0) topo_qu.push(x); }
    }

    for(int i=1; i<=num_vertex; i++) SCC_Topo_Index[SCC_Topo[i]]=i;
}

//Main Function for SCC.
void SCC_Compress()
{
   //Initializes Containers
   while(!stk.empty()) stk.pop(); SCC_time=0;
   for(int i=1; i<=num_vertex; i++) { disc[i]=-1; In_stk[i]=0; SCC_adj[i].clear(); }

   //SCC_DFS from vertex unvisited
   for(int i=1; i<=num_vertex; i++) if(disc[i]==-1) SCC_DFS(i);

   //To add edges to SCC Compressed
   for(int i=1; i<=num_vertex; i++)
   {
       for(auto x: adj[i])
       {
           int su = SCC_par[i], sv = SCC_par[x];       //Head of SCC comp
           if(su==sv) continue;        //Belong to same comp
           SCC_adj[su].push_back(sv);
           SCC_incoming[sv].push_back(su);
       }
   }

   //Topologically sorts the newly for DAG of SCC
   SCC_Toposort();
}

/*****************SCC Ends*****************/


void Add_Imp(int i, int j)
{
    adj[i].push_back(j);
    //Make sure you add contra positive of every statement you add
}

void solve()
{
    int n, p, M, m;
    cin>>n>>p>>M>>m;

    //From 2 -> 2*p+1       //2i means ith station taken and 2i+1 means ith station not taken.
    int base = (2*p+1);     //base + (2i = f>=i) & (2i+1 = Not f>=i) i.e. f<i
    num_vertex = (base) + (2*M+5);

    for(int i=1; i<=n; i++)
    {
        int x, y; cin>>x>>y;
        Add_Imp(2*x+1, 2*y);
        Add_Imp(2*y+1, 2*x);
    }

    for(int i=1; i<=M; i++)
    {
        Add_Imp(base+2*(i+1), base+2*i);
        Add_Imp(base+(2*i)+1, base+(2*(i+1))+1);
    }

    for(int i=1; i<=p; i++)
    {
        int l, r; cin>>l>>r;
        Add_Imp(2*i, base+2*l);
        Add_Imp(base+2*l+1, 2*i+1);
        Add_Imp(2*i, base+2*(r+1)+1);
        Add_Imp(base+2*(r+1), 2*i+1);
    }

    for(int i=1; i<=m; i++)
    {
        int u, v; cin>>u>>v;
        Add_Imp(2*u, 2*v+1);
        Add_Imp(2*v, 2*u+1);
    }

    SCC_Compress();

    vector<int> Stations;
    for(int i=1; i<=p; i++)
    {
        int x = SCC_par[2*i]; int y = SCC_par[2*i+1];
        if(x==y) { cout<<-1<<endl; return; }
        if(SCC_Topo_Index[x]>SCC_Topo_Index[y]) Stations.push_back(i);
    }

    int max_f=-1;
    for(int i=1; i<=M; i++)
    {
        int x = SCC_par[base+2*i]; int y = SCC_par[base+2*i+1];
        if(x==y) { cout<<-1<<endl; return; }
        if(SCC_Topo_Index[x]>SCC_Topo_Index[y]) max_f=i;
    }

    if(max_f==-1) { cout<<-1<<endl; return; }
    int k=Stations.size();

    cout<<k<<" "<<max_f<<endl;
    for(int x: Stations) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}