/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+1;
const int INF = 1e18;

vector< pair<int,int> > adj[N];
int n,m;

int dist[N],vis[N]={0};

void solve()
{
   cin>>n>>m;

   for(int i=1;i<=m;i++)
   {
       int u,v,w;
       cin>>u>>v>>w;
       adj[u].push_back({v,w});
       adj[v].push_back({u,w});
   }

   priority_queue< array<int, 3> > pq;
   pq.push({0, n, -1});

   int par[n+1];
   while(!pq.empty())
   {
       auto cur=pq.top();
       pq.pop();

       int d = -cur[0];
       int i = cur[1];
       int p = cur[2];
       if(vis[i]==1) continue;

       vis[i] = 1;
       dist[i] = d;
       par[i] = p;

       for(auto x: adj[i])
       {
           int v=x.first;
           int w=x.second;
           if(vis[v]==1) continue;
           pq.push({-(d+w), v, i});
       }

   }

   if(vis[1]==0) { cout<<-1<<endl; return; }

   int cur=1;
   while(cur!=-1)
   {
       cout<<cur<<" ";
       cur = par[cur];
   }
   cout<<endl;

}

int32_t main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   solve();
   return 0;
}