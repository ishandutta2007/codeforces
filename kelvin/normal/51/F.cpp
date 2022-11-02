#include <stdio.h>
#include <vector>
#include <utility>
#define MAXN 2050
#define MAXM 100050

/* op = merge_component + merge_bcc + make_caterpillar */
/*    = (#component-1) + (#origv-#bccv) + sigma(#treev-#maxcat) */

using namespace std;

typedef pair<int,int> pii;

class Node {
   public:
      int rank;
      Node *r;
      void init() { rank=0; r=this; }
      Node* rep() { if(r!=this) r=r->rep(); return r; }
};

inline void merge(Node *v,Node *u) {
   v=v->rep();
   u=u->rep();
   if(v==u) return;
   if(v->rank<u->rank) {
      v->r=u;
   } else {
      u->r=v;
      if(v->rank==u->rank) u->rank++;
   }
}

int vn,realgn,compn;
int vdeg[MAXN]={0},vadj[MAXN][MAXN];
int gdeg[MAXN]={0},gadj[MAXN][MAXN];
bool isrep[MAXN];

int visited[MAXN]={0},visid=0;
int low[MAXN],dfn[MAXN],dfsid;
vector<pii> stk;
Node bset[MAXN];

inline int min(int a,int b) { return a<b?a:b; }

void dfsbcc(int v) {
   visited[v]=visid;
   low[v]=dfn[v]=dfsid++;
   for(int i=0;i<vdeg[v];i++) {
      int u=vadj[v][i];
      if(visited[u]==visid) {
         low[v]=min(low[v],dfn[u]);
      } else {
         stk.push_back(make_pair(v,u));
         dfsbcc(u);
         low[v]=min(low[v],low[u]);
         if(low[u]>=dfn[v]) {
            bool proper=0;
            pii ed;
            if(stk.back().first!=v) proper=1;
            do {
               ed=stk.back();
               stk.pop_back();
               if(proper) merge(bset+ed.first,bset+ed.second);
            } while(ed.first!=v);
         }
      }
   }
}

inline void find_bcc() {
   dfsid=0;
   compn=0;
   ++visid;
   for(int i=0;i<vn;i++)
      bset[i].init();
   for(int i=0;i<vn;i++) {
      if(visited[i]<visid) {
         compn++;
         stk.clear();
         dfsbcc(i);
      }
   }
}

inline void reconstruct() {
   realgn=0;
   for(int v=0;v<vn;v++) {
      isrep[v]=(bset[v].rep()==bset+v);
      if(isrep[v]) realgn++;
      int tv=bset[v].rep()-bset;
      for(int i=0;i<vdeg[v];i++) {
         int u=bset[vadj[v][i]].rep()-bset;
         if(tv==u) continue;
         gadj[tv][gdeg[tv]++]=u;
      }
   }
}

int farv,fard;
void dfs_far(int v,int p,int d) {
   visited[v]=visid;
   if(d>fard) {
      fard=d;
      farv=v;
   }
   for(int i=0;i<gdeg[v];i++) {
      int u=gadj[v][i];
      if(u==p) continue;
      dfs_far(u,v,d+1);
   }
}

inline int find_far(int rt) {
   fard=-1;
   dfs_far(rt,rt,0);
   rt=farv;
   fard=-1;
   dfs_far(rt,rt,0);
   return fard-(fard?1:0);
}

inline int solve() {
   find_bcc();
   reconstruct();
   int sol=(compn-1)+vn;
   ++visid;
   for(int i=0;i<vn;i++)
      if(isrep[i]&&visited[i]<visid) sol-=find_far(i);
   for(int i=0;i<vn;i++)
      if(isrep[i]&&gdeg[i]<=1) sol--;
   return sol;
}

int main(void)
{
   int m;
   scanf("%d %d",&vn,&m);
   while(m--) {
      int v,u;
      scanf("%d %d",&v,&u);
      v--; u--;
      vadj[v][vdeg[v]++]=u;
      vadj[u][vdeg[u]++]=v;
   }
   printf("%d\n",solve());
   return 0;
}