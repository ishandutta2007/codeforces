/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 9e18;

struct cmp
{
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        return a.first>b.first;
    }
};

vector< pair<int,int> > adj[N];

int dist[N],vis[N]={0};

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        
        for(int j=0;j<4;j++)
        {
            adj[4*u+j].push_back({4*v+j,w});
            adj[4*v+j].push_back({4*u+j,w});
            
            int sk=j%2;
            int tw=j/2;
            
            if(sk==0)
            {
                adj[4*u+j].push_back({4*v+j+1,(int)0});
                adj[4*v+j].push_back({4*u+j+1,(int)0});
            }
            if(tw==0)
            {
                adj[4*u+j].push_back({4*v+j+2,2*w});
                adj[4*v+j].push_back({4*u+j+2,2*w});
            }
            if(sk==0 && tw==0)
            {
                adj[4*u+j].push_back({4*v+j+3,w});
                adj[4*v+j].push_back({4*u+j+3,w});
            }
        }
        
    }

    priority_queue< pair<int,int>, vector< pair<int,int> >, cmp> q;
    q.push({0,4});

    while(!q.empty())
    {
        auto cur=q.top();
        q.pop();

        int d=cur.first;
        int i=cur.second;
        if(vis[i]==1) continue;

        vis[i]=1;
        dist[i]=d;

        for(auto x: adj[i])
        {
            int v=x.first;
            int w=x.second;
            if(vis[v]==1) continue;
            q.push({d+w,v});
        }

    }

    for(int i=2; i<=n; i++) cout<<dist[4*i+3]<<" ";
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}