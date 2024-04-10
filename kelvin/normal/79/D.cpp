#include <stdio.h>
#define MAXL 10050
#define MAXT 20
#define MAXJ 205
#define MAXSTATE (1<<MAXT)

const int inf=100000000;

int tp[MAXT+1];

int len;
int tn=0,todo[MAXT+1];
int jn=0,jump[MAXJ];
int cost[MAXT][MAXT];
int dp[MAXSTATE];

int visited[MAXL]={0},visid=0;
int ql,qr,que[MAXL],dist[MAXL];

inline void relax(int &x,int val) { if(val<x) x=val; }

inline void addtodo(int x) {
   if(tn&&todo[tn-1]==x) tn--;
   else todo[tn++]=x;
}

inline void bfs(int s) {
   ++visid;
   ql=qr=0;
   que[qr++]=s;
   dist[s]=0;
   visited[s]=visid;
   while(ql<qr) {
      int v=que[ql++];
      for(int i=0;i<jn;i++) {
         int u=v+jump[i];
         if(u<0||u>len) continue;
         if(visited[u]==visid) continue;
         dist[u]=dist[v]+1;
         visited[u]=visid;
         que[qr++]=u;
      }
   }
}

inline void pre() {
   for(int i=0;i<tn;i++)
      for(int j=0;j<tn;j++)
         cost[i][j]=inf;
   for(int i=0;i<tn;i++) {
      int s=todo[i];
      bfs(s);
      for(int j=0;j<tn;j++)
         if(visited[todo[j]]==visid) relax(cost[i][j],dist[todo[j]]);
   }
}

inline int getzero(int b) {
   for(int i=0;i<tn;i++)
      if(!(b&tp[i])) return i;
}

inline int solve() {
   pre();
   for(int b=0;b<tp[tn];b++)
      dp[b]=inf;
   dp[0]=0;
   for(int b=0;b<tp[tn]-1;b++) {
      if(dp[b]>=inf) continue;
      int z=getzero(b);
      for(int j=0;j<tn;j++) {
         if(z==j) continue;
         if(b&tp[j]) continue;
         if(cost[z][j]>=inf) continue;
//         printf("<%d %d %d>, %d %d, %d\n",b,z,j,todo[z],todo[j],cost[z][j]);
         relax(dp[b|tp[z]|tp[j]],dp[b]+cost[z][j]);
      }
   }
   return dp[tp[tn]-1]<inf?dp[tp[tn]-1]:-1;
}

int main(void)
{
   int tt;
   for(int i=0;i<=MAXT;i++)
      tp[i]=1<<i;
   scanf("%d %d %d",&len,&tt,&jn);
   for(int i=0;i<tt;i++) {
      int x;
      scanf("%d",&x);
      addtodo(x-1);
      addtodo(x);
   }
   for(int i=0;i<jn;i++) {
      scanf("%d",jump+i);
      jump[jn+i]=-jump[i];
   }
   jn*=2;
   printf("%d\n",solve());
   return 0;
}