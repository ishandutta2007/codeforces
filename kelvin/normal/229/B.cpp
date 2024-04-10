#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#define MAXN 100050
#define MAXM 100050
#define MAXK 100050

using namespace std;
typedef pair<int,int> pii;

const int inf=1010000000;

int n,m;
vector<pii> adj[MAXN];
vector<int> fb[MAXN];

int dist[MAXN];

int solve() {
   priority_queue<pii> pq;
   for(int i=1;i<=n;i++)
      dist[i]=inf;
   dist[1]=0;
   pq.push(make_pair(-0,1));
   while(pq.size()) {
      int d=-pq.top().first;
      int v=pq.top().second;
      pq.pop();
      if(dist[v]<d) continue;
      if(v==n) return d;
      for(int i=0;i<fb[v].size();i++)
         if(fb[v][i]==d) d++;
      for(int i=0;i<adj[v].size();i++) {
         int u=adj[v][i].first;
         int l=adj[v][i].second;
         if(d+l<dist[u]) {
            dist[u]=d+l;
            pq.push(make_pair(-dist[u],u));
         }
      }
   }
   return -1;
}

int main(void)
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<m;i++) {
      int v,u,l;
      scanf("%d %d %d",&v,&u,&l);
      adj[v].push_back(make_pair(u,l));
      adj[u].push_back(make_pair(v,l));
   }
   for(int i=1;i<=n;i++) {
      int fn;
      scanf("%d",&fn);
      fb[i].resize(fn);
      for(int j=0;j<fn;j++)
         scanf("%d",&(fb[i][j]));
   }
   printf("%d\n",solve());
   return 0;
}