/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 1;

vector<int> adj[N];
int a[N];
int vis[N];
int col[N];

bool bi(int chi, int cur)
{
    vis[chi]=1; col[chi]=cur;

    for(auto x: adj[chi])
    {
        if(vis[x]==1)
        {
            if(col[x]==cur) return false;
            else continue;
        }
        else
        {
            if(bi(x, cur^1)) continue;
            else return false;
        }
    }

    return true;
}

int Get_Sum(int chi)
{
    int sum=a[chi];
    vis[chi]=1;

    for(auto x: adj[chi])
    {
        if(vis[x]==1) continue;
        sum-=Get_Sum(x);
    }

    return sum;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int sum=0;

    for(int i=1; i<=n; i++) { adj[i].clear(); vis[i]=0; col[i]=0; }

    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x; a[i]-=x;
        sum+=a[i];
    }

    for(int i=1; i<=m; i++)
    {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(sum%2) { cout<<"NO"<<endl; return; }

    if(!bi(1, 0)) { cout<<"YES"<<endl; return; }

    for(int i=1; i<=n; i++) vis[i]=0;

    if(Get_Sum(1)==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}