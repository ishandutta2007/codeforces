#include <stdio.h>
#include <string.h>
#define MAXN 605

const int inf=1000000000;
const int large=300000001;

int n,src,sink;
int deg[MAXN],adj[MAXN][MAXN];
int res[MAXN][MAXN];

int ql,qr,que[MAXN];
int pred[MAXN],aug[MAXN];
int visited[MAXN]={0},visid=0;

inline int left(int v) { return v; }
inline int right(int v) { return v+n; }

inline void append(int v,int u,int c) {
   adj[v][deg[v]++]=u;
   if(u!=sink&&v!=src) adj[u][deg[u]++]=v;
   res[v][u]=c;
   res[u][v]=0;
}

inline int min(int a,int b) { return a<b?a:b; }

inline bool bfs() {
   ++visid;
   ql=qr=0;
   que[qr++]=src;
   visited[src]=visid;
   aug[src]=inf;
   while(ql<qr) {
      int v=que[ql++];
      if(v==sink) return 1;
      for(int i=0;i<deg[v];i++) {
         int u=adj[v][i];
         if(!res[v][u]) continue;
         if(visited[u]==visid) continue;
         aug[u]=min(aug[v],res[v][u]);
         pred[u]=v;
         que[qr++]=u;
         visited[u]=visid;
      }
   }
   return 0;
}

inline void augment() {
   int v=sink,a=aug[sink];
   while(v!=src) {
      res[v][pred[v]]+=a;
      res[pred[v]][v]-=a;
      v=pred[v];
   }
}

inline long long mincut() {
   long long f=0;
   while(bfs()) {
      f+=aug[sink];
      augment();
   }
   return f;
}

int main(void)
{
   while(scanf("%d",&n)==1) {
      src=0;
      sink=2*n+1;
      memset(deg,0,sizeof(deg));
      for(int i=1;i<=n;i++) {
         int d,j;
         scanf("%d",&d);
         while(d--) {
            scanf("%d",&j);
            append(left(i),right(j),inf);
         }
      }
      long long costsum=0;
      for(int i=1;i<=n;i++) {
         int c;
         scanf("%d",&c);
         costsum+=c;
         append(src,left(i),large-c);
         append(right(i),sink,large);
      }
      int sol=costsum+mincut()-(long long)n*large;
      printf("%d\n",sol);
   }
   return 0;
}