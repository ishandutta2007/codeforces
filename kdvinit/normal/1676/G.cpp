/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1e5;

vector<int> adj[N];
int a[N];
int w[N];
int b[N];
int ans;

void DFS(int chi, int par)
{
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS(x, chi);
        w[chi] += w[x];
        b[chi] += b[x];
    }

    if(a[chi]==0) w[chi]++;
    else b[chi]++;

    if(w[chi]==b[chi]) ans++;
}

void solve()
{
    int n; cin>>n;

    ans=0;
    for(int i=1; i<=n; i++)
    {
        adj[i].clear();
        w[i]=0;
        b[i]=0;
    }

    for(int i=2; i<=n; i++)
    {
        int p;
        cin>>p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i]=0;
        if(x=='B') a[i]=1;
    }

    DFS(1, -1);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}