#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#define MAXL 255
#define MAXN 30
#define MAXV (MAXL*2+10)
#define QUESIZE 1000000

using namespace std;

const int inf=1000000000;

int len,nvar;
int seq[MAXL];//,val[MAXL];
map<int,int> vmap;

int vn,src,sink,csrc,csink,ff,cc;
int deg[MAXV],adj[MAXV][MAXV];
int res[MAXV][MAXV],cost[MAXV][MAXV];

int ql,qr,que[QUESIZE];
int dist[MAXV],pred[MAXV];
bool inque[MAXV];

int cur[MAXN];
vector<string> sol;

inline int getcost(int to) {
   int c=0;
   while(to) {
      c+=to&1;
      to>>=1;
   }
   return c;
}

/*inline void discrete() {
   vmap.clear();
   for(int i=0;i<len;i++) {
      int id;
      if(vmap.find(seq[i])==vmap.end()) {
         id=vmap.size();
         val[id]=seq[i];
         vmap[seq[i]]=id;
      } else id=vmap[seq[i]];
      seq[i]=id;
   }
   //for(int i=0;i<len;i++)
      ///printf("%d(%d) ",seq[i],val[seq[i]]);puts("");
}*/

inline int in(int s) { return s+1; }
inline int out(int s) { return s+len+1; }

inline void append(int v,int u,int r,int c) {
   adj[v][deg[v]++]=u;
   adj[u][deg[u]++]=v;
   res[v][u]=r;
   res[u][v]=0;
   cost[v][u]=c;
   cost[u][v]=-c;
}

inline void construct() {
   ff=0;
   cc=0;
   src=0;
   sink=len*2+1;
   csrc=sink+1;
   csink=sink+2;
   vn=csink+1;
   for(int i=0;i<vn;i++)
      deg[i]=0;
   append(sink,src,nvar,0);
   for(int i=0;i<len;i++) {
      append(src,in(i),1,getcost(seq[i]));
      append(out(i),sink,1,0);
      append(csrc,out(i),1,0);
      append(in(i),csink,1,0);
      for(int j=i+1;j<len;j++) {
         if(seq[i]==seq[j]) append(out(i),in(j),1,0);
         else append(out(i),in(j),1,getcost(seq[j]));
      }
   }
}

inline void push(int v) {
   if(inque[v]) return;
   que[qr++]=v;
   if(qr==QUESIZE) qr=0;
   inque[v]=1;
}
inline int pop() {
   int v=que[ql++];
   if(ql==QUESIZE) ql=0;
   inque[v]=0;
   return v;
}
inline bool bfs() {
   ql=qr=0;
   for(int i=0;i<vn;i++) {
      dist[i]=inf;
      inque[i]=0;
   }
   dist[csrc]=0;
   push(csrc);
   while(ql!=qr) {
      int v=pop();
      for(int i=0;i<deg[v];i++) {
         int u=adj[v][i];
         if(!res[v][u]) continue;
         if(dist[v]+cost[v][u]>=dist[u]) continue;
         dist[u]=dist[v]+cost[v][u];
         pred[u]=v;
         push(u);
      }
   }
   return dist[csink]<inf;
}

inline void augment() {
   int v=csink;
   ff++;
   while(v!=csrc) {
      cc+=cost[pred[v]][v];
      res[pred[v]][v]--;
      res[v][pred[v]]++;
      v=pred[v];
   }
}

inline int getvar(int val) {
   for(int i=0;i<nvar;i++)
      if(cur[i]==val) return i;
}
inline bool isfrom(int v,int u) {
   return (res[u][v]?1:0);
}

inline void solve() {
   char cmd[100];
   //discrete();
   construct();
   while(bfs())
      augment();
   //
   memset(cur,0,sizeof(cur));
   sol.clear();
   for(int i=0;i<len;i++) {
      int cval,pval,x;
      char ch;
      cval=seq[i];
      if(isfrom(src,in(i))) pval=0;
      else {
         for(int j=0;j<i;j++) {
            if(isfrom(out(j),in(i))) {
               pval=seq[j];
               break;
            }
         }
      }
      x=getvar(pval);
      ch='a'+x;
      if(cval!=pval) {
         sprintf(cmd,"%c=%d\n",ch,cval);
         sol.push_back(cmd);
      }
      sprintf(cmd,"print(%c)\n",ch);
      sol.push_back(cmd);
      cur[x]=cval;
   }
   //
   printf("%d %d\n",sol.size(),cc);
   for(int i=0;i<sol.size();i++)
      cout << sol[i];
}

int main(void)
{
   scanf("%d %d",&len,&nvar);
   for(int i=0;i<len;i++)
      scanf("%d",seq+i);
   solve();
   return 0;
}