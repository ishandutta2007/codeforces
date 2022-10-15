/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int N = 2e5+1;
const int INF = 9e18;
 
struct cmp
{
   bool operator()(pair<int, int>& a, pair<int, int>& b)
   {
       return a.first>b.first;
   }
};
 
vector< pair<int,int> > adj[N], rev[N];
int n,m;
 
int dist[N], vis[N]={0}, ans[N];
 
void solve()
{
   cin>>n>>m;
   
   for(int i=1;i<=n;i++) 
   {
       vis[i]=0;
       adj[i].clear();
       rev[i].clear();
   }
 
   for(int i=1;i<=m;i++)
   {
       int u,v;
       cin>>u>>v;
       adj[u].push_back({v,1});
       rev[v].push_back({u,1});
   }
 
   priority_queue< pair<int,int>, vector< pair<int,int> >, cmp> q;
   q.push({0,1});
 
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
 
   for(int i=1;i<=n;i++) vis[i]=0;
   
   q.push({0,1});
   for(int i=1;i<=n;i++) q.push( {dist[i], i} );
   
   while(!q.empty())
   {
       auto cur=q.top();
       q.pop();
 
       int d=cur.first;
       int i=cur.second;
       if(vis[i]==1) continue;
 
       vis[i]=1;
       ans[i]=d;
 
       for(auto x: rev[i])
       {
           int v=x.first;
           int w=x.second;
           
           if(dist[i]>dist[v]) q.push({d,v});
           else q.push( {dist[i],v} );
       }
 
   }
   
   for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
   cout<<endl;
 
}
 
int32_t main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int t; cin>>t;
   while(t--) solve();
   return 0;
}