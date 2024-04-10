/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 1;

vector<int> adj[N];
int aep;
int depth=0;

void dfs(int v,int p)
{
    if(adj[v].size()==1 && depth%2==1) aep=0;
    depth++;

    for(int i : adj[v])
    {
        if(i==p) continue;
        dfs(i, v);
    }
    depth--;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int lr;
    int parl[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==1)
        {
            lr=i;
            parl[adj[i][0]]++;
        }
    }

    int mx=n-1;
    for(int i=1;i<=n;i++)
    {
        if(parl[i]==0) continue;
        mx-=(parl[i]-1);
    }

    aep=1;
    dfs(lr,0);

    int mn=3;
    if(aep==1) mn=1;

    cout<<mn<<" "<<mx<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}