#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define MAXN 100050

using namespace std;

int n,k;
int ed[MAXN][2];
vector<int> adj[MAXN];
int dep[MAXN],pred[MAXN];
int oid,order[MAXN];

int up[MAXN];
/*set<int> vset[MAXN];
set<int> *spt[MAXN];
vector<int> dlist[MAXN];*/
vector<int> alist[MAXN];
int add[MAXN];

class Query { public:
   int v,u,sol;
   Query() {}
   Query(int vi,int ui):v(vi),u(ui) {}
};

class Node { public:
   int rank,anc;
   Node *r;
   void init(int v) { r=this; rank=0; anc=v; }
   Node *rep() {
      if(r!=this) r=r->rep();
      return r;
   }
};

void merge(Node *v,Node *u) {
   v=v->rep(); u=u->rep();
   if(v==u) return;
   if(v->rank<u->rank) {
      v->r=u;
      u->anc=v->anc;
   } else {
      u->r=v;
      if(v->rank==u->rank) v->rank++;
   }
}

int qn;
Node vs[MAXN];
Query qarr[MAXN];
vector<Query*> qadj[MAXN];
int visited[MAXN]={0},visid=0;

inline void tarjan() {
   int v,u,i;
   ++visid;
   for(i=1;i<=n;i++) vs[i].init(i);
   /** process in anti-dfn-order, might need revision here!! **/
   for(oid=0;oid<n;oid++) {
      v=order[oid];
      //printf("(%d)\n",v);
      for(i=0;i<qadj[v].size();i++) {
         u=qadj[v][i]->u==v?qadj[v][i]->v:qadj[v][i]->u;
            //printf("<%d %d>\n",v,u);
         if(visited[u]==visid) {
            //printf("<%d %d>\n",v,i);
            qadj[v][i]->sol=vs[u].rep()->anc;
         }
      }
      if(pred[v]) merge(vs+pred[v],vs+v);
      visited[v]=visid;
   }
}

void dfs(int v,int p) {
   pred[v]=p;
   dep[v]=dep[p]+1;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(u!=p) dfs(u,v);
   }
   order[oid++]=v;
}

inline void solve() {
   oid=0;
   dep[0]=-1;
   dfs(1,0);
   //puts("dfs done");
   tarjan();
   //puts("tarjan done");
   for(int i=0;i<qn;i++) {
      //printf("%d %d: %d\n",qarr[i].v,qarr[i].u,qarr[i].sol);
      //alist[qarr[i].v].push_back(qarr[i].sol);
      add[qarr[i].sol]-=2;
   }
   /*for(int i=1;i<=n;i++) {
      if(alist[i].size()==0) continue;
      int a=alist[i][0];
      for(int j=0;j<alist[i].size();j++)
         if(dep[alist[i][j]]<dep[a]) a=alist[i][j];
      dlist[a].push_back(i);
   }*/
   for(oid=0;oid<n;oid++) {
      int v=order[oid];
      up[v]=0;
      for(int i=0;i<adj[v].size();i++) {
         int u=adj[v][i];
         if(u==pred[v]) continue;
         /*if(spt[u]->size()<spt[v]->size()) {
            spt[v]->insert(spt[u]->begin(),spt[u]->end());
         } else {
            spt[u]->insert(spt[v]->begin(),spt[v]->end());
            spt[v]=spt[u];
         }*/
         up[v]+=up[u];
      }
      /*for(int i=0;i<dlist[v].size();i++) {
         int u=dlist[v][i];
         spt[v]->erase(u);
      }*/
      //up[v]=spt[v]->size();
      up[v]+=add[v];
   }
   for(int i=0;i<n-1;i++) {
      int v=ed[i][0];
      int u=ed[i][1];
      v=(dep[v]>dep[u]?v:u);
      printf("%d%c",up[v],i<n-2?' ':'\n');
   }
   puts("");
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n-1;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v].push_back(u);
      adj[u].push_back(v);
      ed[i][0]=v;
      ed[i][1]=u;
   }
   scanf("%d",&k);
   for(int i=0;i<k;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      if(v==u) {
         k--;
         i--;
         continue;
      }
      add[v]++;
      add[u]++;
      //vset[v].insert(v);
      //vset[u].insert(v);
      qarr[i]=Query(v,u);
      qadj[v].push_back(qarr+i);
      qadj[u].push_back(qarr+i);
   }
   qn=k;
   /*for(int i=1;i<=n;i++)
      spt[i]=vset+i;*/
   solve();
   return 0;
}