#include <stdio.h>
#include <vector>
#define MAXN 100050

#define IGNORE 0
#define ASSIGN 1
#define USE 2

using namespace std;

int n,m;
int state[MAXN];
vector<int> adj[MAXN];
vector<int> rdj[MAXN];

int ql,qr,que[MAXN];
bool vis1[MAXN],vis2[MAXN];

void bfs(int ss,bool *vis,vector<int> *adj) {
   ql=qr=0;
   for(int i=1;i<=n;i++) {
      if(state[i]==ss) {
         que[qr++]=i;
         vis[i]=1;
      }
   }
   while(ql<qr) {
      int v=que[ql++];
      for(int i=0;i<adj[v].size();i++) {
         int u=adj[v][i];
         if(vis[u]) continue;
         vis[u]=1;
         if(state[u]==ASSIGN) continue;
         que[qr++]=u;
      }
   }
}

void solve() {
   bfs(ASSIGN,vis1,adj);
   bfs(USE,vis2,rdj);
   for(int i=1;i<=n;i++) {
      int b=(vis1[i]&&vis2[i])?1:0;
      printf("%d\n",b);
   }
}

int main(void)
{
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)
      scanf("%d",state+i);
   for(int i=0;i<m;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v].push_back(u);
      rdj[u].push_back(v);
   }
   solve();
   return 0;
}