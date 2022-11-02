#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100050

using namespace std;

class Edge {
   public:
      int v,u,c,id;
      void input() { scanf("%d%d%d",&v,&u,&c); v--; u--; }
      const bool operator<(const Edge &b) const { return c<b.c; }
};

class Node {
   public:
      Node *r;
      int sz;
      void init() {
         r=this;
         sz=1;
      }
      Node *rep() {
         if(r!=this) r=r->rep();
         return r;
      }
};
inline void merge(Node *v,Node *u) {
   v=v->rep();
   u=u->rep();
   if(v==u) return;
   if(v->sz<u->sz) {
      v->r=u;
      u->sz+=v->sz;
   } else {
      u->r=v;
      v->sz+=u->sz;
   }
}

int n;
Edge ed[MAXN];
long long pass[MAXN];
Node nd[MAXN];

vector<int> adj[MAXN];
int ndsz[MAXN];
int pred[MAXN],subnum[MAXN],total[MAXN];
int ql,qr,que[MAXN];
int visited[MAXN]={0},visid=0;

inline void bfs(int rt) {
   int i,v,u,qi,tot=0;
   ql=qr=0;
   que[qr++]=rt;
   pred[rt]=-1;
   while(ql<qr) {
      v=que[ql++];
      visited[v]=visid;
      tot+=ndsz[v];
      for(i=0;i<adj[v].size();i++) {
         u=adj[v][i];
         if(u==pred[v]) continue;
         que[qr++]=u;
         pred[u]=v;
      }
   }
   for(qi=qr-1;qi>=0;qi--) {
      v=que[qi];
      subnum[v]=ndsz[v];
      total[v]=tot;
      for(i=0;i<adj[v].size();i++) {
         u=adj[v][i];
         if(u==pred[v]) continue;
         subnum[v]+=subnum[u];
      }
   }
}

inline void process(Edge *arr,int num) {
   int i,v,u,rt,id,ei;
   /* count */
   ++visid;
   //rt=nd[arr[0].v].rep()-nd;
   for(i=0;i<num;i++) {
      v=nd[arr[i].v].rep()-nd;
      u=nd[arr[i].u].rep()-nd;
      adj[v].clear();
      adj[u].clear();
      ndsz[v]=nd[v].rep()->sz;
      ndsz[u]=nd[u].rep()->sz;
   }
   for(i=0;i<num;i++) {
      v=nd[arr[i].v].rep()-nd;
      u=nd[arr[i].u].rep()-nd;
      adj[v].push_back(u);
      adj[u].push_back(v);
   }
   for(i=0;i<num;i++) {
      v=nd[arr[i].v].rep()-nd;
      //u=nd[arr[i].u].rep()-nd;
      if(visited[v]<visid) bfs(v);
   }
   //bfs(rt);
   //total=subnum[rt];
   for(i=0;i<num;i++) {
      v=nd[arr[i].v].rep()-nd;
      u=nd[arr[i].u].rep()-nd;
      id=arr[i].id;
      if(pred[v]==u) std::swap(v,u);
      //printf("<%d> %d %d %d %d\n",rt,id,total,subnum[u],total-subnum[u]);
      pass[id]=(long long)subnum[u]*(total[u]-subnum[u])*2;
   }
   /* union all */
   for(i=0;i<num;i++) {
      v=arr[i].v;
      u=arr[i].u;
      merge(nd+v,nd+u);
   }
}

inline void solve() {
   int i,j;
   long long opt,optn;
   bool flag=0;
   std::sort(ed,ed+n-1);
   for(i=0;i<n;i++)
      nd[i].init();
   for(i=0;i<n-1;i=j) {
      for(j=i;j<n-1&&ed[j].c==ed[i].c;j++);
      process(ed+i,j-i);
   }
   opt=-1;
   for(i=0;i<n-1;i++) {
      if(pass[i]>opt) {
         opt=pass[i];
         optn=1;
      } else if(pass[i]==opt) optn++;
   }
//   for(i=0;i<n-1;i++)
//      cout << pass[i] << " "; puts("");
   cout << opt << " " << optn << endl;
   for(i=0;i<n-1;i++) {
      if(pass[i]==opt) {
         if(flag) printf(" ");
         flag=1;
         printf("%d",i+1);
      }
   }
   puts("");
}

int main(void)
{
   int i;
   while(scanf("%d",&n)==1) {
      for(i=0;i<n-1;i++) {
         ed[i].input();
         ed[i].id=i;
      }
      solve();
   }
   return 0;
}