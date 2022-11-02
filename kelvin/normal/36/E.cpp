#include <stdio.h>
#include <vector>
#include <utility>
#define MAXN 10050

using namespace std;

int m,n;
pair<int,int> ed[MAXN];
vector<int> adj[MAXN];
bool used[MAXN]={0};

int visited[MAXN]={0},visid=0;
vector<int> dfsv;

int remdeg[MAXN];
bool trav[MAXN]={0};

inline int getu(int ei,int v) {
   return ed[ei].first+ed[ei].second-v;
}

void dfscomp(int v) {
   visited[v]=visid;
   dfsv.push_back(v);
   for(int i=0;i<adj[v].size();i++) {
      int u=getu(adj[v][i],v);
      if(visited[u]<visid) dfscomp(u);
   }
}

bool dfseu(int v,vector<int> &rt) {
   while(adj[v].size()) {
      int ei=adj[v].back();
      int u=getu(ei,v);
      if(trav[ei]) {
         adj[v].pop_back();
         continue;
      }
      trav[ei]=1;
      adj[v].pop_back();
      remdeg[v]--;
      remdeg[u]--;
      dfseu(u,rt);
      rt.push_back(ei);
   }
}

inline void euler(vector<int> &rt) {
   int i;
   for(i=0;i<n;i++)
      if(remdeg[i]&1) break;
   if(i==n) {
      for(i=0;i<n;i++)
         if(remdeg[i]) break;
   }
   dfseu(i,rt);
   //puts("--");
}

inline bool solve() {
   int compn=0,somev[2];
   vector<int> oddv[2];
   if(m<2) return 0;
   ++visid;
   for(int i=0;i<n;i++) {
      if(!used[i]) continue;
      if(visited[i]==visid) continue;
      if(compn>=2) return 0;
      dfsv.clear();
      dfscomp(i);
      for(int j=0;j<dfsv.size();j++) {
         int v=dfsv[j];
         if(adj[v].size()&1) oddv[compn].push_back(v);
      }
      somev[compn]=dfsv[0];
      compn++;
   }
   if(oddv[0].size()+oddv[1].size()>4) return 0;
   if(compn>1&&(oddv[0].size()>=4||oddv[1].size()>=4)) return 0;
   vector<int> rt[2],eu;
   if(oddv[0].size()&&oddv[1].size()) {
      ed[0]=make_pair(oddv[0][0],oddv[1][0]);
   } else if(oddv[0].size()) {
      if(compn==2) ed[0]=make_pair(oddv[0][0],somev[1]);
      else ed[0]=make_pair(oddv[0][0],oddv[0][1]);
   } else if(oddv[1].size()) {
      ed[0]=make_pair(somev[0],oddv[1][0]);
   } else {
      if(compn==2) ed[0]=make_pair(somev[0],somev[1]);
      else ed[0]=make_pair(somev[0],somev[0]);
   }
   //printf("(%d %d)\n",ed[0].first,ed[1].first);
   adj[ed[0].first].push_back(0);
   adj[ed[0].second].push_back(0);
   for(int i=0;i<n;i++)
      remdeg[i]=adj[i].size();
   euler(eu);
   //for(int i=0;i<eu.size();i++)
   //   printf("%d ",eu[i]);puts("");
   int ei;
   for(ei=0;ei<eu.size()&&eu[ei]!=0;ei++)
      rt[0].push_back(eu[ei]);
   for(ei++;ei<eu.size();ei++)
      rt[1].push_back(eu[ei]);
   for(int i=0;i<2;i++) {
      if(!rt[i].size()) {
         rt[i].push_back(rt[!i].back());
         rt[!i].pop_back();
      }
   }
   for(int i=0;i<2;i++) {
      printf("%d\n",rt[i].size());
      for(int j=0;j<rt[i].size();j++)
         printf("%d\n",rt[i][j]);
   }
   return 1;
}

int main(void)
{
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   scanf("%d",&m);
   n=0;
   for(int i=1;i<=m;i++) {
      scanf("%d %d",&ed[i].first,&ed[i].second);
      if(ed[i].first>=n) n=ed[i].first+1;
      if(ed[i].second>=n) n=ed[i].second+1;
      adj[ed[i].first].push_back(i);
      adj[ed[i].second].push_back(i);
      used[ed[i].first]=used[ed[i].second]=1;
   }
   if(!solve()) puts("-1");
   return 0;
}