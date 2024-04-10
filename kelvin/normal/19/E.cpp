#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#define MAXN 10050
#define MAXM 10050

using namespace std;

class Edge {
   public:
      int v,u;
      Edge() {}
      Edge(int vi,int ui):v(vi),u(ui) { if(v>u) swap(v,u); }
      const bool operator<(const Edge &b) const {
         return v<b.v||v==b.v&&u<b.u;
      }
};

typedef pair<int,int> pii;

int n,m;
vector<int> adj[MAXN];
map<Edge,int> e2i;

vector<int> cyc;
bool incycle[MAXN];
int cycid[MAXN];

int visited[MAXN]={0},visid=0;
bool color[MAXN];
vector<int> dfstack;
vector<int> seq;
vector<pii> seg;
int event[MAXN]={0};

inline int abs(int x) { return x>=0?x:0-x; }
bool dfscyc(int v) {
   visited[v]=visid;
   dfstack.push_back(v);
   if(incycle[v]) seq.push_back(v);
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(incycle[u]&&incycle[v]) {
         int d=abs(cycid[v]-cycid[u]);
         if(d==1||d==cyc.size()-1) continue;
      }
      if(visited[u]<visid) {
         color[u]=!color[v];
         if(dfscyc(u)) return 1;
      } else {
         if(color[u]==color[v]) {
            //printf("%d %d, %d %d\n",v,u,incycle[v],incycle[u]);
            for(int j=dfstack.size()-1;;j--) {
               int w=dfstack[j];
               cyc.push_back(w);
               incycle[w]=1;
               if(w==u) break;
            }
            return 1;
         }
      }
   }
   dfstack.pop_back();
   return 0;
}
inline bool find_odd_cycle() {
   ++visid;
   cyc.clear();
   memset(incycle,0,(n+1)*sizeof(bool));
   for(int i=1;i<=n;i++) {
      if(visited[i]<visid) {
         dfstack.clear();
         if(dfscyc(i)) {
            for(int j=0;j<cyc.size();j++)
               cycid[cyc[j]]=j;
            return 1;
         }
      }
   }
   return 0;
}

inline bool postcheck() {
   bool flag=0;
   /*printf("postcheck #\n");
   for(int i=0;i<seq.size();i++)
      printf("%d(%d) ",seq[i],color[seq[i]]);puts("");*/
   if(seq.size()<=1) return 1;
   for(int i=0;i<seq.size();i++)
      seq[i]=cycid[seq[i]];
   sort(seq.begin(),seq.end());
   for(int i=0;i<seq.size();i++) {
      int ni=(i==seq.size()-1?0:i+1);
      int v=cyc[seq[i]],u=cyc[seq[ni]];
      int d=seq[ni]-seq[i]+(ni==0?cyc.size():0);
      if((color[v]^color[u]^d)&1) {
         if(flag) return 0;
         flag=1;
         seg.push_back(make_pair(seq[i],seq[ni]));
      }
   }
   return 1;
}

inline bool bicolor_nodes() {
   ++visid;
   for(int i=1;i<=n;i++) {
      if(visited[i]<visid) {
         dfstack.clear();
         seq.clear();
         if(dfscyc(i)) return 0;
         if(!postcheck()) return 0;
      }
   }
   return 1;
}

Edge ed[MAXM];
inline void find_overlap() {
   int cur=0;
   vector<int> sol;
   /*printf("overlap #\n");
   for(int i=0;i<seg.size();i++)
      printf("%d %d ",seg[i].first,seg[i].second);puts("");*/
   for(int i=0;i<seg.size();i++) {
      if(seg[i].first>seg[i].second) cur++;
      event[seg[i].first]++;
      event[seg[i].second]--;
   }
   for(int i=0;i<cyc.size();i++) {
      cur+=event[i];
      //printf("%d %d\n",i,cur);
      if(cur==seg.size()) sol.push_back(e2i[Edge(cyc[i],cyc[i==cyc.size()-1?0:i+1])]);
   }
   sort(sol.begin(),sol.end());
   printf("%d\n",(int)sol.size());
   for(int i=0;i<sol.size();i++)
      printf("%d%c",sol[i],i<sol.size()-1?' ':'\n');
}

inline void solve() {
   if(!find_odd_cycle()) {
      printf("%d\n",m);
      for(int i=1;i<=m;i++)
         printf("%d%c",i,i<m?' ':'\n');
      return;
   }
   /*printf("odd cycle found:\n");
   for(int i=0;i<cyc.size();i++)
      printf("%d ",cyc[i]);puts("");*/
   if(!bicolor_nodes()) {
      puts("0\n");
      return;
   }
   find_overlap();
}

int main(void)
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<m;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v].push_back(u);
      adj[u].push_back(v);
      e2i[Edge(v,u)]=i+1;
      ed[i+1]=Edge(v,u);
   }
   solve();
   return 0;
}