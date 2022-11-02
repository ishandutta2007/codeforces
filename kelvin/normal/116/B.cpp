#include <stdio.h>
#define MAXL 12
#define MAXN 120

int mat[4][2]={1,0, 0,1, -1,0, 0,-1};

int rn,cn;
char gr[MAXL][MAXL];

int src,sink,n;
int deg[MAXN]={0},adj[MAXN][MAXN],res[MAXN][MAXN];

int visited[MAXN]={0},visid=0;

inline bool valid(int r,int c) {
   return r>=0&&r<rn&&c>=0&&c<cn;
}

inline int id(int r,int c) { return r*cn+c+1; }

inline void append(int v,int u) {
   adj[v][deg[v]++]=u;
   adj[u][deg[u]++]=v;
   res[v][u]=1;
   res[u][v]=0;
}

inline void construct() {
   n=rn*cn+2;
   src=0;
   sink=n-1;
   for(int i=0;i<rn;i++) {
      for(int j=0;j<cn;j++) {
         if(gr[i][j]=='.') continue;
         if(gr[i][j]=='W') append(id(i,j),sink);
         if(gr[i][j]=='P') {
            append(src,id(i,j));
            for(int k=0;k<4;k++) {
               int ni=i+mat[k][0];
               int nj=j+mat[k][1];
               if(!valid(ni,nj)) continue;
               if(gr[ni][nj]=='W') append(id(i,j),id(ni,nj));
            }
         }
      }
   }
}

bool dfs(int v) {
   visited[v]=visid;
   if(v==sink) return 1;
   for(int i=0;i<deg[v];i++) {
      int u=adj[v][i];
      if(visited[u]==visid) continue;
      if(!res[v][u]) continue;
      if(dfs(u)) {
         res[v][u]--;
         res[u][v]++;
         return 1;
      }
   }
   return 0;
}

inline int flow() {
   int f=0;
   while(1) {
      ++visid;
      if(dfs(src)) f++;
      else return f;
   }
}

inline int solve() {
   construct();
   return flow();
}

int main(void)
{
   scanf("%d %d",&rn,&cn);
   for(int i=0;i<rn;i++)
      scanf("%s",gr[i]);
   printf("%d\n",solve());
   return 0;
}