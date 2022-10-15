/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 5001;
int ff=0;
//set<int> :: iterator itr;

class Graph
{
private:
    int V, E;
    set<int> adj[N];
    int Euler_Path[4*N];
    int Eu_cnt=0;
    int Special_Adjacent1=0;

public:
    Graph(int n, int m);
    void Help_Check_Conected(int p, int c, int vis[]);
    bool Check_Conected();
    bool Check_Star(int sv, int Edge_Parity[], int Total_Odd);
    int Find_Star();
    void Print_Path(int sv);
    void Get_Euler_From(int u);
    bool Is_Valid_Next(int u, int v);
    int dfs_count(int u, int vis[]);
    void Color_dfs(int c, int vis[], int Cmp);
    bool Already();
};

Graph::Graph(int n, int m)
{
    V = n;
    E = m;
    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        if(i==1) ff=u;
        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void Graph::Help_Check_Conected(int p, int c, int vis[])
{
    vis[c]=1;
    for(set<int> :: iterator itr=adj[c].begin(); itr!=adj[c].end(); itr++)
    {
        int cc = *itr;
        if(vis[cc]==1) continue;
        Help_Check_Conected(c, cc, vis);
    }
}

bool Graph::Check_Conected()
{
    int vis[V+1]={0};
    Help_Check_Conected(-1, 1, vis);

    for(int i=1; i<=V; i++)
    {
        if(vis[i]==0 && adj[i].size()!=0) return false;
    }

    return true;
}

void Graph::Color_dfs(int c, int vis[], int Cmp)
{
    vis[c]=Cmp;
    for(set<int> :: iterator itr=adj[c].begin(); itr!=adj[c].end(); itr++)
    {
        int cc = *itr;
        if(vis[cc]!=0) continue;
        Color_dfs(cc, vis, Cmp);
    }
}

bool Graph::Check_Star(int sv, int Edge_Parity[], int Total_Odd)
{
    if(adj[sv].size()==0) return false;

    int Out_Odd = Total_Odd;
    Out_Odd -= Edge_Parity[sv];

    int Star_Size=0;
    vector<int> Star_Vertex;


    for(set<int> :: iterator itr=adj[sv].begin(); itr!=adj[sv].end(); itr++)
    {
        int c = *itr;
        int x = Edge_Parity[c];
        Out_Odd -= x;
        Star_Size += x;
        if(x==1) Star_Vertex.push_back(c);
    }

    if(Out_Odd>1) return false;

    for(int i=0; i<Star_Vertex.size(); i++)
    {
        int c = Star_Vertex[i];
        adj[sv].erase(c);
        adj[c].erase(sv);
    }

    int pos = Check_Conected();

    int vis[V+1]={0};
    int Cmp=0;
    Cmp++;
    Color_dfs(sv, vis, Cmp);

    for(int i=0; i<Star_Vertex.size(); i++)
    {
        int c = Star_Vertex[i];
        if(adj[c].size()==0) vis[c]=1;
        if(vis[c]!=0) continue;
        Cmp++;
        Color_dfs(c, vis, Cmp);
    }


    for(int i=0; i<Star_Vertex.size(); i++)
    {
        int c = Star_Vertex[i];
        adj[sv].insert(c);
        adj[c].insert(sv);
    }

    for(int i=0; i<Star_Vertex.size(); i++)
    {
        int c = Star_Vertex[i];
        if(vis[c]==2) Special_Adjacent1=c;
    }

    if(Out_Odd==1)
    {
        if(Cmp<=1) return true;
        else return false;
    }
    else
    {
        if(Cmp<=2) return true;
        else return false;
    }
    return false;
}

int Graph::Find_Star()
{
    int Edge_Parity[V+1] = {0};
    int Total_Odd = 0;

    for(int i=1; i<=V; i++)
    {
        int Deg=adj[i].size();
        Edge_Parity[i] = Deg%2;
        Total_Odd += Deg%2;
    }

    for(int i=1; i<=V; i++)
    {
        if(Check_Star(i, Edge_Parity, Total_Odd)) return i;
    }
    return -1;
}

void Graph::Print_Path(int sv)
{
    vector<int> Star_Vertex;

    for(set<int> :: iterator itr=adj[sv].begin(); itr!=adj[sv].end(); itr++)
    {
        int c = *itr;
        int x = adj[c].size()%2;
        if(x==0) continue;
        if(c==Special_Adjacent1) continue;
        Star_Vertex.push_back(c);
    }

    for(int i=0; i<Star_Vertex.size(); i++)
    {
        int c = Star_Vertex[i];
        adj[sv].erase(c);
        adj[c].erase(sv);
    }

    int strt=sv;
    for(int i=1; i<=V; i++)
    {
        if(i==sv) continue;
        if(adj[i].size()%2==1) strt=i;
    }

    Get_Euler_From(strt);

    int Total = Eu_cnt + 2*Star_Vertex.size();
    if(Star_Vertex.size()!=0) Total++;
    cout<<Total<<endl;

    for(int i=1; i<=Eu_cnt; i++) cout<<Euler_Path[i]<<" ";

    if(Star_Vertex.size()!=0) cout<<-1<<" ";

    for(int i=0; i<Star_Vertex.size(); i++)
    {
        cout<<Star_Vertex[i]<<" ";
        cout<<sv<<" ";
    }
    cout<<endl;
}

void Graph::Get_Euler_From(int u)
{
    Euler_Path[++Eu_cnt]=u;
    //cout<<"Degree Of "<<u<<" is "<<adj[u].size()<<endl;
    
    vector<int> Next;
    
    for(set<int> :: iterator itr=adj[u].begin(); itr!=adj[u].end(); itr++)
    {
        int c = *itr;
        Next.push_back(c);
    }
    
    for(int i=0; i<Next.size(); i++)
    {
        int c = Next[i];
        if(Is_Valid_Next(u, c))
        {
            adj[u].erase(c);
            adj[c].erase(u);
            Get_Euler_From(c);
            return;
        }
    }
    return;
}

bool Graph::Is_Valid_Next(int u, int v)
{
    if(adj[u].size()==1) return true;

    int vis1[N]={0};
    int count_inc = dfs_count(v, vis1);

    adj[u].erase(v);
    adj[v].erase(u);

    int vis2[N]={0};
    int count_exc = dfs_count(v, vis2);

    adj[u].insert(v);
    adj[v].insert(u);

    //cout<<"U = "<<u<<" V = "<<v<<endl;
    //cout<<"Count_inc = "<<count_inc<<" Count_exc = "<<count_exc<<endl;
    //cout<<endl;

    if(count_inc>count_exc) return false;
    else return true;
}

int Graph::dfs_count(int u, int vis[])
{
    vis[u]=1;
    int cnt=1;
    for(set<int> :: iterator itr=adj[u].begin(); itr!=adj[u].end(); itr++)
    {
        int c = *itr;
        if(vis[c]==1) continue;
        cnt+=dfs_count(c, vis);
    }
    return cnt;
}

bool Graph::Already()
{
    int Odd_Deg = 0;
    int strt = 1;
    for(int i=1; i<=V; i++)
    {
        int x = adj[i].size();
        if(x%2==0) continue;
        Odd_Deg++;
        strt = i;
    }

    if(Odd_Deg>2) return false;

    Get_Euler_From(strt);

    cout<<" "<<Eu_cnt<<endl;
    for(int i=1; i<=Eu_cnt; i++) cout<<Euler_Path[i]<<" ";
    cout<<endl;

    return true;
}

void solve()
{
    int n, m;
    cin>>n>>m;
    Graph G(n, m);

    if(G.Check_Conected()==0) { cout<<0<<endl; return; }

    if(G.Already())
    {
        //cout<<"It Was Already There."<<endl;
        return;
    }

    int sv = G.Find_Star();
    if(sv == -1) { cout<<0<<endl; return; }
    
    //cout<<"Hello5"<<endl;

    G.Print_Path(sv);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}