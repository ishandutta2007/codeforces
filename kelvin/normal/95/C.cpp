#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#define MAXN 1060
#define MAXM 1060

using namespace std;

const long long infll = 10000000000000000LL;

int n,m,sv,ev;
int deg[MAXN],adj[MAXN][MAXN];
long long cost[MAXN][MAXN];
int span[MAXN],taxi[MAXN];
long long dist[MAXN];
bool visited[MAXN];

void dijkstra(int s) {
   int i,v,u,t;
   long long vd;
   priority_queue<pair<long long, int> > pq;
   for(i=0;i<n;i++)
      dist[i]=infll;
   dist[s]=0;
   pq.push(make_pair(0,s));
   for(t=0;t<n;t++) {
      do {
         if(pq.empty()) break;
         v=pq.top().second;
         vd=-pq.top().first;
         pq.pop();
      } while(vd!=dist[v]);
      for(i=0;i<deg[v];i++) {
         u=adj[v][i];
         if(vd+cost[v][u]<dist[u]) {
            dist[u]=vd+cost[v][u];
            pq.push(make_pair(-dist[u],u));
         }
      }
   }
}

long long dijkstra2() {
   int i,v,u,t;
   long long vd;
   for(i=0;i<n;i++) {
      dist[i]=infll;
      visited[i]=0;
   }
   dist[sv]=0;
   for(t=0;t<n;t++) {
      for(v=0;v<n;v++)
         if(!visited[v]) break;
      for(i=v;i<n;i++)
         if(!visited[i]&&dist[i]<dist[v]) v=i;
      vd=dist[v];
      visited[v]=1;
      for(u=0;u<n;u++) {
         if(visited[u]) continue;
         if(cost[v][u]>span[v]) continue;
         if(vd+taxi[v]<dist[u])
            dist[u]=vd+taxi[v];
      }
   }
   return dist[ev];
}

inline long long solve() {
   int i,j;
   for(i=0;i<n;i++) {
      dijkstra(i);
      for(j=0;j<n;j++)
         cost[i][j]=dist[j];
   }
/*   for(i=0;i<n;i++) {
      for(j=0;j<n;j++)
         printf("%lld ",cost[i][j]);puts("");}*/
   return dijkstra2();
}

int main(void)
{
   int i,v,u,c;
   long long res;
   while(scanf("%d %d %d %d",&n,&m,&sv,&ev)==4) {
      sv--;
      ev--;
      for(v=0;v<n;v++)
         for(u=0;u<n;u++)
            cost[v][u]=infll;
      for(i=0;i<m;i++) {
         scanf("%d %d %d",&v,&u,&c);
         v--;
         u--;
         adj[v][deg[v]++]=u;
         adj[u][deg[u]++]=v;
         if(c<cost[v][u]) cost[v][u]=c;
         if(c<cost[u][v]) cost[u][v]=c;
      }
      for(i=0;i<n;i++)
         scanf("%d %d",span+i,taxi+i);
      res=solve();
      if(res==infll) puts("-1");
      else cout << res << endl;
   }
   return 0;
}