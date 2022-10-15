/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 1;

vector<int> adj[N];
int vis[N], n, ans[N], cnt;

void dfs(int v,int p)
{
    vis[v]=1;
    if(ans[p]==1) ans[v]=0;

    int nt=1;
    
    for(int i : adj[v]) if(ans[i]==1) nt=0;
    if(ans[p]==0) ans[v]=nt;
    
    for(int i : adj[v])
    {
        if(vis[i]==1) continue;
        dfs(i, v);
    }
    
    if(ans[v]==1) cnt++;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    cnt=0;
    
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
        vis[i]=0;
        ans[i]=2;
    }

    for(int i=1;i<=m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans[0]=0;
    dfs(1, 0);
    
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0) { cout<<"NO"<<endl; return; }
    }
    
    cout<<"YES"<<endl;
    
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==1) cout<<i<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}