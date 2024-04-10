/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e6 + 1;

vector<int> adj[N];
int n, m;


/****************SCC Starts*****************/

//KDVinit's Implementation for Tarjan's Algorithm (GFG)
//Global Variables for SCC,
//This will additionally use N = max, adj[N] for edges,
//and n, m for number of nodes and edges respectively.

//Outputs of the Tarjan's Algorithm
vector<int> SCC_Nodes;          //Nodes from main graph that are heads of SCC.
vector<int> SCC_Component[N];   //Vertexes in the SCC Component of a head node.

//Note - Adj List may store multiple edges between 2 vertex
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
        int w; SCC_Nodes.push_back(chi); SCC_Component[chi].push_back(chi);
        while(stk.top()!=chi)
        {
            w=stk.top();
            stk.pop();
            SCC_par[w]=chi;
            In_stk[w]=0;
            SCC_Component[chi].push_back(w);
        }
        stk.pop(); In_stk[chi]=0; SCC_par[chi]=chi;
    }
}

//Main Function for SCC.
void SCC_Compress()
{
    //Initializes Containers
    while(!stk.empty()) stk.pop(); SCC_Nodes.clear(); SCC_time=0;
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

/*****************SCC Ends*****************/


void solve()
{
    //cin>>n>>m;
    int h, w;
    cin>>h>>w;

    int w2=w+2;

    int a[h+2][w+2];
    int id[h+2][w+2];
    n = (h+2)*(w+2);
    m = 4*n;

    for(int i=0; i<=h+1; i++)
    {
        for(int j=0; j<=w+1; j++)
        {
            id[i][j] = i*w2 + j;
            if(i==0 || j==0 || i==h+1 || j==w+1) { a[i][j]=0; continue; }
            char x; cin>>x;
            if(x=='#') a[i][j]=1;
            else a[i][j]=0;
        }
    }

    int sand[w+1];
    for(int i=1; i<=w; i++) cin>>sand[i];

    for(int j=0; j<=w+1; j++) a[h+1][j]=1;

    for(int j=1; j<=w; j++)
    {
        int li=0, ri=0, nxt=1;
        for(int i=1; i<=h; i++)
        {
            if(a[i][j]==0) continue;
            while(li<i || a[li][j-1]==0) li++;
            while(ri<i || a[ri][j+1]==0) ri++;
            while(nxt<=i || a[nxt][j]==0) nxt++;

            //cout<<i<<" "<<j<<" --> "<<endl;
            //cout<<li<<" "<<j-1<<endl;
            //cout<<ri<<" "<<j+1<<endl;
            //cout<<nxt<<" "<<j<<endl;
            //cout<<endl;

            adj[id[i][j]].push_back(id[li][j-1]);
            adj[id[i][j]].push_back(id[ri][j+1]);
            adj[id[i][j]].push_back(id[nxt][j]);
            if(a[i-1][j]==1) adj[id[i][j]].push_back(id[i-1][j]);
        }
    }

    SCC_Compress();

    int ans=0;
    for(auto x: SCC_Nodes)
    {
        int i = x/w2;
        int j = x%w2;
        if(a[i][j]==0 || i>h) continue;

        if(SCC_incoming[x].size()==0)
        {
            ans++;
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}