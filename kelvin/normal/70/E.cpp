#include <stdio.h>
#define MAXN 205

const int inf=1000000000;

int n,bcost;
int dcost[MAXN];

int deg[MAXN]={0},adj[MAXN][MAXN];
int pred[MAXN];
bool subof[MAXN][MAXN]={0};
int len[MAXN][MAXN];

int dp[MAXN][MAXN],self[MAXN],subr[MAXN];
int order[MAXN],oid=0;
int root[MAXN];

inline int min(int a,int b) { return a<b?a:b; }
inline void relax(int &x,int val) { if(val<x) x=val; }

void dfs(int v,int p,int s,int l,bool ss=0) {
   len[s][v]=l;
   if(ss) subof[s][v]=1;
   if(s==1) pred[v]=p;
   for(int i=0;i<deg[v];i++) {
      int u=adj[v][i];
      if(u==p) continue;
      dfs(u,v,s,l+1,ss);
   }
   if(!ss&&s==1) order[oid++]=v;
}

inline void pre() {
   for(int v=1;v<=n;v++)
      dfs(v,0,v,0);
   for(int v=1;v<=n;v++)
      dfs(v,pred[v],v,0,1);
   for(int v=1;v<=n;v++) {
      for(int i=0;i<deg[v];i++) {
         int u=adj[v][i];
         if(u==pred[v]) {
            adj[v][i]=adj[v][--deg[v]];
            break;
         }
      }
   }
}

inline void process(int v) {
   for(int r=1;r<=n;r++) {
      int c=dcost[len[v][r]]+(r==v?bcost:0);
      for(int i=0;i<deg[v];i++) {
         int u=adj[v][i];
         if(subof[u][r]) c+=dp[u][r];
         else c+=min(self[u],dp[u][r]);
      }
      dp[v][r]=c;
      //printf("<%d %d>: %d\n",v,r,c);
   }
   self[v]=inf;
   subr[v]=0;
   for(int u=1;u<=n;u++) {
      if(subof[v][u]) {
         if(dp[v][u]<self[v]) {
            self[v]=dp[v][u];
            subr[v]=u;
         }
      }
   }
   //printf("%d - <%d>\n",v,self[v]);
}

inline void recover(int v,int r) {
   if(subof[v][r]||dp[v][r]<=self[v]) root[v]=r;
   else root[v]=subr[v];
}

inline void solve() {
   pre();
   for(int i=0;i<n;i++)
      process(order[i]);
   dp[1][0]=inf;
   for(int i=n-1;i>=0;i--) {
      int v=order[i];
      recover(v,v==1?0:root[pred[v]]);
   }
   printf("%d\n",self[1]);
   for(int v=1;v<=n;v++)
      printf("%d%c",root[v],v<n?' ':'\n');
}

int main(void)
{
   scanf("%d %d",&n,&bcost);
   dcost[0]=0;
   for(int i=1;i<n;i++)
      scanf("%d",dcost+i);
   for(int i=1;i<n;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v][deg[v]++]=u;
      adj[u][deg[u]++]=v;
   }
   solve();
   return 0;
}