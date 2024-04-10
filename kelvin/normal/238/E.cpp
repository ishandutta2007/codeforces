#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 105
#define MAXK 105

using namespace std;

const int inf=1000000000;
typedef pair<int,int> pii;

int n,m,k,src,des;
int bsrc[MAXK],bdes[MAXK];

int dist[MAXN][MAXN];

bool mustpass[MAXN][MAXK];
int minbus[MAXN][MAXK];
int unsure[MAXN][MAXK],next[MAXN][MAXK];

inline bool onroute(int b,int v) {
   int bs=bsrc[b];
   int bd=bdes[b];
   //printf("%d %d: %d\n",b,v,dist[bs][v]+dist[v][bd]==dist[bs][bd]);
   return dist[bs][v]+dist[v][bd]==dist[bs][bd];
}

inline void relax(int v,int b,int d,priority_queue<pair<int,pii> > &pq) {
      //printf("%d %d %d<-%d\n",b,v,d,minbus[v][b]);
   if(d<minbus[v][b]) {
      minbus[v][b]=d;
      pq.push(make_pair(-d,make_pair(v,b)));
   }
}

int solve() {
   if(src==des) return 0;
   //
   for(int b=0;b<k;b++) {
      int bs=bsrc[b],bt=bdes[b];
      vector<int> stops[MAXN];
      for(int i=0;i<n;i++)
         if(onroute(b,i)) stops[dist[bs][i]].push_back(i);
      for(int d=0;d<=dist[bs][bt];d++)
         if(stops[d].size()==1) mustpass[stops[d].back()][b]=1;
   }
   //
   priority_queue<pair<int,pii> > pq;
   for(int v=0;v<n;v++) {
      for(int b=0;b<k;b++) {
         if(!onroute(b,v)) continue;
         minbus[v][b]=(v==des?0:inf);
         unsure[v][b]=0;
         next[v][b]=0;
         for(int u=0;u<n;u++)
            if(onroute(b,u)&&dist[bsrc[b]][v]+1==dist[bsrc[b]][u]&&dist[v][u]==1) unsure[v][b]++;
      }
   }
   for(int b=0;b<k;b++)
      if(onroute(b,des)) pq.push(make_pair(0,make_pair(des,b)));
   //
   while(pq.size()) {
      int d=-pq.top().first;
      int v=pq.top().second.first;
      int b=pq.top().second.second;
      //printf("<%d %d = %d>\n",v,b,d);
      pq.pop();
      if(minbus[v][b]!=d) continue;
      // change bus
      if(mustpass[v][b]) {
         for(int i=0;i<k;i++)
            if(onroute(i,v)) relax(v,i,d+1,pq);
      }
      // same bus
      for(int u=0;u<n;u++) {
         if(onroute(b,u)&&dist[bsrc[b]][v]==dist[bsrc[b]][u]+1&&dist[u][v]==1) { // bsrc->u->v->bdes
            unsure[u][b]--;
            next[u][b]=max(next[u][b],d);
            if(!unsure[u][b]) relax(u,b,next[u][b],pq);
         }
      }
   }
   //
   int sol=inf;
   for(int b=0;b<k;b++)
      if(mustpass[src][b]) sol=min(sol,minbus[src][b]+1);
   return sol<inf?sol:-1;
}

int main(void)
{
   scanf("%d %d %d %d",&n,&m,&src,&des);
   src--; des--;
   for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++)
         dist[i][j]=inf;
      dist[i][i]=0;
   }
   for(int i=0;i<m;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      v--; u--;
      dist[v][u]=1;
   }
   for(int t=0;t<n;t++)
      for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            dist[i][j]=min(dist[i][j],dist[i][t]+dist[t][j]);
   scanf("%d",&k);
   for(int i=0;i<k;i++) {
      scanf("%d %d",bsrc+i,bdes+i);
      bsrc[i]--; bdes[i]--;
      if(dist[bsrc[i]][bdes[i]]>=inf) {
         i--; k--;
         continue;
      }
   }
   printf("%d\n",solve());
   return 0;
}