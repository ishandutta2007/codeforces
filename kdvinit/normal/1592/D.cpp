/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e4;

vector<int> adj[N];
int Euler[N], cntr;

void DFS(int chi, int par)
{
    Euler[++cntr]=chi;
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS(x, chi);
        Euler[++cntr]=chi;
    }
}

int query(int l, int r)
{
    set<int> st;
    for(int i=l; i<=r; i++) st.insert(Euler[i]);
    
    cout<<"? ";
    cout<<st.size()<<" ";
    for(int x: st) cout<<x<<" ";
    cout<<endl;
    
    int q; cin>>q;
    return q;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++) adj[i].clear();

    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cntr=0;
    DFS(1, -1);
    
    int l=1;
    int r=cntr;
    
    int mx = query(l, r);
    
    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(query(l, mid)==mx) r=mid;
        else l=mid;
    }
    
    cout<<"! "<<Euler[l]<<" "<<Euler[r]<<endl;
}

int32_t main()
{
    solve();
    return 0;
}