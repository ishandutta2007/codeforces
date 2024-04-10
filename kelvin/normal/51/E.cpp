#include <stdio.h>
#include <iostream>
#define MAXN 705

int n,m;
bool adj[MAXN][MAXN]={0};

int d2[MAXN][MAXN],d3[MAXN][MAXN];
long long sol=0;

inline void find2() {
   for(int v=0;v<n;v++) {
      for(int u=v;u<n;u++) {
         d2[v][u]=0;
         for(int i=0;i<n;i++)
            if(adj[v][i]&&adj[u][i]) d2[v][u]++;
         d2[u][v]=d2[v][u];
         //printf("<2>: %d %d = %d\n",v,u,d2[v][u]);
      }
   }
}

inline void find3() {
   for(int v=0;v<n;v++) {
      for(int u=v+1;u<n;u++) {
         d3[v][u]=0;
         for(int i=0;i<n;i++) {
            if(i==v||i==u) continue;
            if(adj[v][i]) d3[v][u]+=d2[i][u];
            if(adj[v][i]&&adj[v][u]) d3[v][u]--;
         }
         d3[u][v]=d3[v][u];
         //printf("<3>: %d %d = %d\n",v,u,d3[v][u]);
      }
   }
}

inline long long solve() {
   find2();
   find3();
   for(int v=0;v<n;v++) {
      for(int u=0;u<n;u++) {
         if(u==v||!adj[v][u]) continue;
         for(int w=u+1;w<n;w++) {
            if(w==v||!adj[v][w]) continue;
            int add=d3[u][w];
            add-=d2[v][w]; // v u v * w (v)
            add-=d2[v][u]; // v u * v w (v)
            if(adj[u][w]) {
               add+=2;
               // v u v u w (v), v u w v w (v)
            }
            //printf("%d %d %d: %d-%d-%d = %d\n",v,u,w,d3[u][w],d2[v][w],d2[v][u],add);
            sol+=add;
         }
      }
   }
   sol/=5;
   return sol;
}

int main(void)
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<m;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      v--; u--;
      adj[v][u]=adj[u][v]=1;
   }
   std::cout << solve() << std::endl;
   return 0;
}