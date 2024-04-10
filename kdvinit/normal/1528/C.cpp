/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e5+2;
vector<int> adj1[N], adj2[N];

int strt[N];
int nd[N];
int ans;

set< pair<int, int> > st;
int rep[N];

bool check_sub(int v)
{
    pair<int, int> tmp = {strt[v], v};
    auto nxt = *st.upper_bound(tmp);
    int ind = nxt.second;

    if(nd[ind]<nd[v]) return true;
    else return false;
}

int ances(int v)
{
    pair<int, int> tmp = {strt[v], v};
    auto nxt = st.upper_bound(tmp); nxt--;
    auto cur = *nxt;
    int ind = cur.second;

    if(nd[ind]>nd[v]) return ind;
    else return 0;
}

void Add_Node(int v)
{
    if(check_sub(v)) return;

    int pre = ances(v);
    st.insert({strt[v], v});

    if(pre==0) return;
    rep[v] = pre;
    st.erase({strt[pre], pre});
}

void Delete_Node(int v)
{
    st.erase({strt[v], v});
    int x = rep[v];
    if(x!=0) st.insert({strt[x], x});
}

void Evaluate()
{
    int tmp = st.size();
    ans = max(ans, tmp);
}

void DFS1(int chi, int par, int& time)
{
    strt[chi] = ++time;
    for(auto x: adj2[chi])
    {
        if(x==par) continue;
        DFS1(x, chi, time);
    }
    nd[chi] = ++time;
}

void DFS2(int chi, int par)
{
    Add_Node(chi);
    for(auto x: adj1[chi])
    {
        if(x==par) continue;
        DFS2(x, chi);
    }
    if(adj1[chi].size()==1) Evaluate();
    Delete_Node(chi);
}

void solve()
{
    int n;
    cin>>n;

    //Reset Adjacency List
    for(int i=1; i<=n; i++) { adj1[i].clear(); adj2[i].clear(); }

    //Take Input
    for(int i=2; i<=n; i++) { int p; cin>>p; adj1[p].push_back(i); adj1[i].push_back(p); }
    for(int i=2; i<=n; i++) { int p; cin>>p; adj2[p].push_back(i); adj2[i].push_back(p); }

    //Euler's Tour
    int time = 0;
    DFS1(1, -1, time);

    //Preparation for DFS
    ans=0;  st.clear();
    strt[n+1] = 2*n+4; nd[n+1] = 2*n+5; st.insert({strt[n+1], n+1});
    strt[0] = -2; nd[0] = -1; st.insert({strt[0], 0});
    for(int i=1; i<=n; i++) rep[i]=0;

    //DFS on first tree
    DFS2(1, -1);
    cout<<ans-2<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}