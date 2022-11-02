#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#define MAXN 100050

using namespace std;

typedef pair<int,int> pii;

int n;
int tar[MAXN]={0},type[MAXN];
vector<int> adj[MAXN];

vector<int> vvv;
bool done[MAXN]={0};

vector<int> dfstack,cyc;
int visited[MAXN]={0},visid=0;
pii dp[MAXN][2],opt[MAXN];
int connect[MAXN];
vector<pii> spn,spy;

pii ans;
vector<pii> aar;

inline pii max(pii a,pii b) { return b<a?a:b; }
pii& operator+=(pii &a,const pii &b) {
   a.first+=b.first;
   a.second+=b.second;
   return a;
}
pii operator+(const pii &a,const pii &b) {
   return pii(a.first+b.first,a.second+b.second);
}
pii operator-(const pii &a,const pii &b) {
   return pii(a.first-b.first,a.second-b.second);
}

inline void remove(int v,int u) {
   for(int t=0;t<2;t++) {
      for(int i=0;i<adj[v].size();i++) {
         if(adj[v][i]==u) {
            adj[v][i]=adj[v].back();
            adj[v].pop_back();
            break;
         }
      }
      swap(v,u);
   }
}
inline void insert(int v,int u) {
   adj[v].push_back(u);
   adj[u].push_back(v);
}

bool dfs(int v,int p) {
   visited[v]=visid;
   dfstack.push_back(v);
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(visited[u]==visid) {
         if(u!=p) {
            //printf("<%d %d %d>\n",v,u,p);
            for(int j=dfstack.size()-1;j>=0;j--)
               cyc.push_back(dfstack[j]);
            return 1;
         }
         continue;
      }
      if(dfs(u,v)) return 1;
   }
   dfstack.pop_back();
   return 0;
}
inline void find_cycle() {
   ++visid;
   cyc.clear();
   dfstack.clear();
   //printf("<%d>\n",vvv[0]);
   if(!dfs(vvv[0],0)) {
      for(int i=0;i<vvv.size();i++) {
         int v=vvv[i];
         if(tar[tar[v]]==v) {
            cyc.push_back(v);
            cyc.push_back(tar[v]);
            break;
         }
      }
   }
}

void go(int v,int p) {
   pii allbest(0,0),takebest(0,0);
   int optu=0;
   visited[v]=visid;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(u==p) continue;
      go(u,v);
      allbest+=opt[u];
   }
   dp[v][0]=allbest;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(u==p) continue;
      pii t=allbest-opt[u]+dp[u][0]+make_pair(1,type[v]!=type[u]);
      if(t>takebest) optu=u;
      takebest=max(takebest,t);
   }
   dp[v][1]=takebest;
   opt[v]=max(dp[v][0],dp[v][1]);
   if(dp[v][0]>dp[v][1]) connect[v]=0;
   else connect[v]=optu;
   //printf("%d: %d %d, %d %d\n",v, dp[v][0].first,dp[v][0].second,dp[v][1].first,dp[v][1].second);
}
inline pii dp_best() {
   pii sol(0,0);
   ++visid;
   for(int i=0;i<vvv.size();i++) {
      int v=vvv[i];
      if(visited[v]<visid) {
         go(v,0);
         sol+=opt[v];
      }
   }
   return sol;
}

void re(int v,int p,bool isfree,vector<pii> &sp) {
   visited[v]=visid;
   int x=isfree?connect[v]:0;
   if(x) sp.push_back(make_pair(v,x));
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(u==p||u==x) continue;
      re(u,v,1,sp);
   }
   if(x) re(x,v,0,sp);
}
inline void trace(vector<pii> &sp) {
   ++visid;
   sp.clear();
   for(int i=0;i<vvv.size();i++) {
      int v=vvv[i];
      if(visited[v]<visid) re(v,0,1,sp);
   }
}
inline void sub() {
   find_cycle();
   /*for(int i=0;i<cyc.size();i++)
      printf("%d ",cyc[i]);puts("");*/
   int cv=cyc[0],cu=cyc[1];
   /* no (cv,cu) */
   remove(cv,cu);
   pii sn=dp_best();
   trace(spn);
   /* take (cv,cu) */
   for(int i=0;i<vvv.size();i++) {
      int v=vvv[i];
      remove(v,cv);
      remove(v,cu);
   }
   pii sy=dp_best()+make_pair(1,type[cv]!=type[cu]);
   trace(spy);
   spy.push_back(make_pair(cv,cu));
   //printf("<%d %d>\n",cv,cu);
   //printf("[%d %d, %d %d]\n",sn.first,sn.second,sy.first,sy.second);
   ans+=max(sy,sn);
   //printf("%d %d\n",sol.first,sol.second);
   vector<pii> &sp=(sy<sn?spn:spy);
   for(int i=0;i<sp.size();i++)
      aar.push_back(sp[i]);
      //printf("%d %d\n",sp[i].first,sp[i].second);
}

void trav(int v) {
   visited[v]=visid;
   done[v]=1;
   vvv.push_back(v);
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      if(visited[u]<visid) trav(u);
   }
}
inline void solve() {
   for(int i=1;i<=n;i++) {
      if(done[i]) continue;
      ++visid;
      vvv.clear();
      trav(i);
      sub();
   }
   printf("%d %d\n",ans.first,ans.second);
   for(int i=0;i<aar.size();i++)
      printf("%d %d\n",aar[i].first,aar[i].second);
}

int main(void)
{
   scanf("%d",&n);
   for(int v=1;v<=n;v++) {
      int u;
      scanf("%d %d",&u,type+v);
      tar[v]=u;
      if(tar[u]==v) continue;
      adj[v].push_back(u);
      adj[u].push_back(v);
   }
   solve();
   return 0;
}