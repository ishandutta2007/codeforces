/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5+1;
const int Infy = 1e17;

vector< pair<int,int> > adj[N];
vector< array<int, 3> > edges;
vector< array<int, 2> > lft;
int n, m, L, s, t, ls;

int Dickstra()
{
    int dist[n+1], vis[n+1]={0};
    priority_queue< pair<int,int> > pq;
    pq.push({-0, s});

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        int d = -cur.first;
        int i = cur.second;
        if(vis[i]==1) continue;

        vis[i] = 1;
        dist[i] = d;

        for(auto x: adj[i])
        {
            int v = x.first;
            int w = x.second;
            if(vis[v]==1) continue;
            pq.push({-(d+w), v});
        }
    }

    if(vis[t]==0) return Infy;
    return dist[t];
}

int First_k(int k)
{
    for(int i=0; i<=n; i++) adj[i].clear();

    for(auto x: edges)
    {
        int u=x[0], v=x[1], w=x[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for(int i=0; i<k; i++)
    {
        int u=lft[i][0], v=lft[i][1];
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
    }

    int ans = Dickstra();
    return ans;
}

void solve()
{
    cin>>n>>m>>L>>s>>t;

    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;

        if(w==0) lft.push_back({u, v});
        else edges.push_back({u, v, w});
    }

    ls=lft.size();

    int len = First_k(0);
    if(len<L) { cout<<"NO"<<endl; return; }

    len = First_k(ls);
    if(len>L) { cout<<"NO"<<endl; return; }

    int l=-1, r=ls;
    while(l+1!=r)
    {
        int mid = (l+r)/2;
        len = First_k(mid);
        if(len<=L) r=mid;
        else l=mid;
    }

    for(int i=0; i<r-1; i++)
    {
        int u=lft[i][0], v=lft[i][1];
        edges.push_back({u, v, 1});
    }

    if(r!=0)
    {
        len = First_k(r);
        int k = L-len+1;
        int u = lft[r-1][0], v=lft[r-1][1];
        edges.push_back({u, v, k});
    }

    for(int i=r; i<ls; i++)
    {
        int u=lft[i][0], v=lft[i][1];
        edges.push_back({u, v, Infy});
    }

    cout<<"YES"<<endl;
    for(int i=0; i<edges.size(); i++)
    {
        cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<edges[i][2]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}