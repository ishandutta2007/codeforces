/*
K.D. Vinit  |,,|
Don't Stalk My Code :)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 1;
const int K = 20 + 1;

vector<int> adj[N];
int Value[N];
int Ans[N];
int Tot[N][2*K];

int n, k;

void Xor(int &x, int &y)
{
    x^=y;
}

void Neg_Xor(int &x, int &y)
{
    // Xor Inverse is Xor Itself.
    x^=y;
}

void Add_Edge(int c, int x)
{
    for(int i=1; i<2*k; i++)
    {
        Xor( Tot[c][i+1], Tot[x][i] );
    }
    Xor( Tot[c][1], Tot[x][2*k] );
}

void Sub_Edge(int c, int x)
{
    for(int i=1; i<2*k; i++)
    {
        Neg_Xor( Tot[c][i+1], Tot[x][i] );
    }
    Neg_Xor( Tot[c][1], Tot[x][2*k] );
}

void Initiase_Node(int c)
{
    for(int i=1; i<=2*k; i++)
    {
        Tot[c][i]=0;
    }
    Tot[c][1] = Value[c];
}

void DFS_Get_Tot(int c, int p=-1)
{
    Initiase_Node(c);
    for(auto x: adj[c])
    {
        if(x==p) continue;
        DFS_Get_Tot(x, c);
        Add_Edge(c, x);
    }
}

bool Check_Node(int c)
{
    int ans = 0;
    for(int i=k+1; i<=2*k; i++) Xor(ans, Tot[c][i]);
    return ans>0;
}

void DFS_Reroot(int c, int p=-1)
{
    Ans[c] = Check_Node(c) ;

    for(auto x: adj[c])
    {
        if(x==p) continue;

        Sub_Edge(c, x);
        Add_Edge(x, c);

        DFS_Reroot(x, c);

        Sub_Edge(x, c);
        Add_Edge(c, x);
    }
}

void solve()
{
    cin>>n>>k;

    for(int i=1; i<=n; i++) adj[i].clear();

    for(int i=1; i<n; i++)
    {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++) cin>>Value[i];

    DFS_Get_Tot(1);
    DFS_Reroot(1);

    for(int i=1; i<=n; i++) cout<<Ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}