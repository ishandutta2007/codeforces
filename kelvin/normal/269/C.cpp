#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 200500

using namespace std;
typedef pair<int,int> pii;
const int inf=100000000;

class Edge {
   public:
      int v,u,c,id,dir;
      void input(int ii) {
         id=ii;
         scanf("%d %d %d",&v,&u,&c);
      }
};

int n,m;
vector<Edge> adj[MAXN];
int tot[MAXN],acc[MAXN];
vector<int> que;
bool vis[MAXN];
int ans[MAXN];

void solve() {
   que.push_back(1);
   vis[1]=1;
   while(que.size()) {
      int v=que.back();
      //printf("<%d>\n",v);
      que.pop_back();
      for(int i=0;i<adj[v].size();i++) {
         int u=adj[v][i].u;
         int c=adj[v][i].c;
         int id=adj[v][i].id;
         int dir=adj[v][i].dir;
         //printf("%d: %d %d %d\n",v,u,c,id);
         if(vis[u]) continue;
         //printf("%d: %d %d\n",v,id,dir);
         ans[id]=dir;
         acc[u]+=c;
         if(u==n) continue;
         if(acc[u]*2==tot[u]) {
            que.push_back(u);
            vis[u]=1;
         }
      }
   }
   for(int i=0;i<m;i++)
      printf("%d\n",ans[i]);
}

int main(void)
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<m;i++) {
      Edge e;
      e.input(i);
      e.dir=0;
      adj[e.v].push_back(e);
      swap(e.v,e.u);
      e.dir=1;
      adj[e.v].push_back(e);
      tot[e.v]+=e.c;
      tot[e.u]+=e.c;
   }
   solve();
   return 0;
}