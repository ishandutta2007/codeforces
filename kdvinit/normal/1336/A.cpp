/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 1;
vector<int> adj[N];
int siz[N];
int dep[N];

void DFS(int p, int c)
{
    if(p==-1) dep[c]=0;
    else dep[c] = dep[p]+1;

    siz[c]=1;
    for(auto x: adj[c])
    {
        if(x==p) continue;
        DFS(c, x);
        siz[c]+=siz[x];
    }
}

void solve()
{
    int n, k;
    cin>>n>>k;

    for(int i=1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(-1, 1);

    int hap[n+1];
    for(int i=1; i<=n; i++)
    {
        hap[i]=dep[i]-(siz[i]-1);
    }

    sort(hap+1, hap+n+1);

    int ans=0;
    for(int i=1; i<=k; i++)
    {
        ans+=hap[n+1-i];
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}