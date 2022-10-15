/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 2e5+100;

vector<int> adj[N];
int frnd[N], n, k;
bool pos[N];

bool ans;

int DFS(int chi, int par, int dep)
{
    if(frnd[chi]==1) return 1;

    int mn = n+1;
    int cnt=0;

    for(auto x: adj[chi])
    {
        if(x==par) continue;
        cnt++;
        int cur = DFS(x, chi, dep+1);
        //if(cur>n) pos[chi]=true;
        mn = min(mn, cur);
    }

    pos[chi]=true;
    if(dep>=mn) pos[chi]=false;

    mn++;
    return mn;
}

void DFS2(int chi, int par)
{
    if(!pos[chi]) return;

    int cnt=0;
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS2(x, chi);
        cnt++;
    }

    if(cnt==0) ans=true;
    return;
}

void solve()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++) { adj[i].clear(); frnd[i]=0; pos[i]=false; }
    for(int i=1; i<=k; i++) { int x; cin>>x; frnd[x]=1; }

    for(int i=1; i<=n-1; i++)
    {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = false;
    DFS(1, -1, 0);
    DFS2(1, -1);

    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}