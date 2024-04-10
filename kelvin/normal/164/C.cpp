#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXTASK 1050
#define MAXV (MAXTASK*2)

using namespace std;

typedef pair<int,int> pii;

const int inf=1000000010;

class Task {
   public:
      int s,f,c;
      void input() {
         scanf("%d %d %d",&s,&f,&c);
         f+=s;
      }
};

class Arc {
   public:
      int u,c,revind;
      int res;
      Arc(int _u,int _r,int _c,int _ri):u(_u),res(_r),c(_c),revind(_ri) {}
};

int ntask,nmac;
Task task[MAXTASK];
int tc[MAXV],tcn;

int vn,src,sink;
vector<Arc> adj[MAXV];
pii check[MAXTASK];
//int res[MAXV][MAXV]={0};

const int QUESIZE=MAXV*MAXV;
int ql,qr,que[QUESIZE];
int cost[MAXV];
pii pred[MAXV];
bool inq[MAXV];

inline void append(int v,int u,int r,int c,int id) {
   int vi=adj[v].size();
   int ui=adj[u].size();
   //printf("(%d %d %d %d)\n",v,u,c,id);
   adj[v].push_back(Arc(u,r,c,ui));
   adj[u].push_back(Arc(v,0,-c,vi));
   if(id>=0) check[id]=make_pair(v,vi);
}

inline void push(int v) {
   if(inq[v]) return;
   inq[v]=1;
   que[qr++]=v;
   if(qr==QUESIZE) qr=0;
}
inline int pop() {
   int v=que[ql++];
   inq[v]=0;
   if(ql==QUESIZE) ql=0;
   return v;
}

inline void bfs() {
   ql=qr=0;
   for(int i=0;i<vn;i++) {
      inq[i]=0;
      cost[i]=-inf;
   }
   cost[src]=0;
   push(src);
   while(ql!=qr) {
      int v=pop();
      if(cost[v]<=-inf) continue;
      for(int i=0;i<adj[v].size();i++) {
         int u=adj[v][i].u;
         int c=adj[v][i].c;
         int r=adj[v][i].res;
         //int ri=adj[v][i].revind;
         if(r<=0) continue;
         if(cost[v]+c<=cost[u]) continue;
         cost[u]=cost[v]+c;
         pred[u]=make_pair(v,i);
         push(u);
      }
   }
}

inline void augment() {
   int v=sink;
   while(v!=src) {
      int p=pred[v].first;
      int i=pred[v].second;
      adj[p][i].res--;
      adj[v][adj[p][i].revind].res++;
      v=p;
   }
}

inline void solve() {
   sort(tc,tc+tcn);
   tcn=unique(tc,tc+tcn)-tc;
   src=0;
   sink=tcn-1;
   vn=tcn;
   //for(int i=0;i<tcn;i++)
      //printf("%d ",tc[i]);puts("");
   for(int i=0;i<sink;i++)
      append(i,i+1,inf,0,-1);
   for(int i=0;i<ntask;i++) {
      task[i].s=lower_bound(tc,tc+tcn,task[i].s)-tc;
      task[i].f=lower_bound(tc,tc+tcn,task[i].f)-tc;
      append(task[i].s,task[i].f,1,task[i].c,i);
   }
   int c=0;
   for(int i=0;i<nmac;i++) {
      //int ret=bfs();
      bfs();
      //printf("<%d>\n",cost[sink]);
      if(cost[sink]>0) {
         c+=cost[sink];
         augment();
      } else break;
   }
   for(int i=0;i<ntask;i++) {
      int v=check[i].first;
      int j=check[i].second;
      int b=(adj[v][j].res?0:1);
      printf("%d ",b);
   }
   puts("");
}

int main(void)
{
   scanf("%d %d",&ntask,&nmac);
   tcn=0;
   for(int i=0;i<ntask;i++) {
      task[i].input();
      tc[tcn++]=task[i].s;
      tc[tcn++]=task[i].f;
   }
   solve();
   return 0;
}