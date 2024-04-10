#include <stdio.h>
#include <stack>
#define MAXN 105
#define MAXM 10050

using namespace std;

int n,m;
int deg[MAXN],adj[MAXN][MAXN],dd[MAXN];
bool visited[MAXN];

inline bool detatch() {
   int i,v,u;
   stack<int> stk;
   for(i=0;i<n;i++) {
      dd[i]=deg[i];
      if(deg[i]==1) stk.push(i);
   }
   while(!stk.empty()) {
      v=stk.top();
      stk.pop();
      visited[v]=1;
      for(i=0;i<deg[v];i++) {
         u=adj[v][i];
         if(!visited[u]&&dd[u]==1) return 0;
         dd[u]--;
         if(dd[u]==1) stk.push(u);
      }
   }
   for(i=0;i<n;i++)
      if(!visited[i]&&dd[i]!=2) return 0;
   return 1;
}

inline bool gocycle(int v) {
   int i,u,c=0;
   while(1) {
      c++;
      visited[v]=1;
      for(i=0;i<deg[v];i++) {
         u=adj[v][i];
         if(!visited[u]) break;
      }
      if(i==deg[v]) break;
      v=u;
   }
   return c>=3;
}

inline bool solve() {
   int i;
   for(i=0;i<n;i++)
      visited[i]=0;
   if(!detatch()) return 0;
//   fprintf(stderr,"detatch\n");
   for(i=0;i<n;i++)
      if(!visited[i]) break;
   if(i==n) return 0;
//   fprintf(stderr,"visited\n");
   if(!gocycle(i)) return 0;
//   fprintf(stderr,"gocycle\n");
   for(i=0;i<n;i++)
      if(!visited[i]) return 0;
   return 1;
}

int main() {
   int i,v,u;
   while(scanf("%d %d",&n,&m)==2) {
      for(i=0;i<n;i++)
         deg[i]=0;
      for(i=0;i<m;i++) {
         scanf("%d %d",&v,&u);
         v--; u--;
         adj[v][deg[v]++]=u;
         adj[u][deg[u]++]=v;
      }
      puts(solve()?"FHTAGN!":"NO");
   }
   return 0;
}