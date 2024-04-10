#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAXN 1050
#define MAXK 35

using namespace std;

class Edge {
   public:
      int v,u,d;
      Edge(int _v,int _u,int _d):v(_v),u(_u),d(_d) {}
      const bool operator<(const Edge &b) const {
         return d<b.d;
      }
};

class Coor {
   public:
      int x,y;
      Coor() {}
      Coor(int _x,int _y):x(_x),y(_y){}
      Coor& operator-=(const Coor &b) {
         x-=b.x;
         y-=b.y;
         return *this;
      }
      Coor operator-(const Coor &b) const {
         return Coor(*this)-=b;
      }
      const bool operator==(const Coor &b) const {
         return x==b.x&&y==b.y;
      }
      void input() {
         scanf("%d %d",&x,&y);
      }
};

int n,k;
Coor pt[MAXN];

int src,sink;
vector<int> adj[MAXN];
int res[MAXN][MAXN];
int visited[MAXN],visid=0;
int forbidden[MAXN],fid=0;
int involve[MAXN];
int failcnt[MAXN];

inline int sqr(int x) { return x*x; }
inline int dist2(Coor a,Coor b) {
   return sqr(a.x-b.x)+sqr(a.y-b.y);
}
inline int dist2(int a,int b) { return dist2(pt[a],pt[b]); }
inline int cross(Coor a,Coor b) {
   return a.x*b.y-a.y*b.x;
}
inline int cross(Coor o,Coor a,Coor b) {
   return cross(Coor(a.x-o.x,a.y-o.y),Coor(b.x-o.x,b.y-o.y));
}

inline void append(int v,int u) {
   adj[v].push_back(u);
   adj[u].push_back(v);
   res[v][u]=1;
   res[u][v]=0;
}
bool dfs(int v) {
   visited[v]=visid;
   if(v==sink) return 1;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(visited[u]==visid) continue;
      if(forbidden[u]==fid) continue;
      if(res[v][u]<=0) continue;
      if(dfs(u)) {
         res[v][u]--;
         res[u][v]++;
         return 1;
      }
   }
   return 0;
}
inline int flow(int maxallow) {
   int f=0;
   while(1) {
      if(f>maxallow) return f;
      ++visid;
      if(dfs(src)) f++;
      else return f;
   }
}

#define COINCIDE 2
#define INSIDE 1
#define OUTSIDE 0

inline int test(int v,int u) {
   int d2=dist2(v,u),cnt=0;
   src=n;
   sink=n+1;
   adj[src].clear();
   adj[sink].clear();
   int tt=0,maxallow=k;
   for(int i=0;i<n;i++) {
      adj[i].clear();
      res[i][sink]=res[sink][i]=res[src][i]=res[i][src]=0;
      if(pt[i]==pt[v]||pt[i]==pt[u]) {
         involve[i]=COINCIDE;
         cnt++;
         continue;
      }
      if(dist2(i,v)>d2||dist2(i,u)>d2) {
         involve[i]=OUTSIDE;
         maxallow--;
         continue;
      }
      involve[i]=INSIDE;
      if(cross(pt[v],pt[u],pt[i])<0) append(src,i);
      else append(i,sink);
      tt++;
   }
   fid++;
   for(int i=0;i<n;i++) {
      if(involve[i]!=INSIDE) continue;
      for(int j=i+1;j<n;j++) {
         if(involve[j]!=INSIDE) continue;
         if(dist2(i,j)<=d2) continue;
         if(res[src][i]+res[i][src]) append(i,j);
         else append(j,i);
      }
   }
   for(int i=0;i<n;i++) {
      if(adj[i].size()>=k+1) {
         forbidden[i]=fid;
         tt--;
         maxallow--;
      }
   }
   if(maxallow<0) return -1;
   if(tt+cnt<n-k) return -1;
   int ret=tt-flow(max(0,maxallow))+cnt;
   return ret;
}

inline void solve() {
   vector<Edge> e;
   for(int v=0;v<n;v++)
      for(int u=v+1;u<n;u++)
         e.push_back(Edge(v,u,dist2(v,u)));
   sort(e.begin(),e.end());
   int i;
   int maxtry=min((int)e.size(),k*(k+1)+1),lasti=-1;
   for(int i=(int)e.size()-1;i>=0;i--) {
      if(failcnt[e[i].v]>k) continue;
      if(failcnt[e[i].u]>k) continue;
      if(maxtry--<=0) break;
      int ret=test(e[i].v,e[i].u);
      if(ret>=n-k) lasti=i;
      failcnt[e[i].v]++;
      failcnt[e[i].u]++;
   }
   int v=e[lasti].v,u=e[lasti].u;
   int ret=test(e[lasti].v,e[lasti].u);
   int rem=k;
   for(int j=0;j<n;j++) {
      if(n-j<=rem) {
         printf("%d ",j+1);
         rem--;
         continue;
      }
      if(involve[j]==COINCIDE) continue;
      if(involve[j]==OUTSIDE
         ||forbidden[j]==fid
         ||dist2(j,v)>dist2(v,u)||dist2(j,u)>dist2(v,u)
         ||(res[src][j]+res[j][src])&&visited[j]<visid
         ||(res[sink][j]+res[j][sink])&&visited[j]==visid) {
         printf("%d ",j+1);
         rem--;
      }
   }
   puts("");
}

int main(void)
{
   scanf("%d %d",&n,&k);
   for(int i=0;i<n;i++)
      pt[i].input();
   solve();
   return 0;
}