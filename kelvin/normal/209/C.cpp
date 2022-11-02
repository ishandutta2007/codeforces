#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1000500

using namespace std;

int n,m;
vector<int> adj[MAXN];

bool vis[MAXN]={0};
int oddc,tr,v1;

void dfs(int v) {
   vis[v]=1;
   if(v==1) v1=1;
   if(adj[v].size()&1) oddc++;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i];
      tr++;
      if(!vis[u]) dfs(u);
   }
}

int solve() {
   vector<int> arr;
   for(int i=1;i<=n;i++) {
      if(vis[i]) continue;
      oddc=0;
      tr=0;
      v1=0;
      dfs(i);
      if(!tr&&!v1) continue;
      arr.push_back(oddc);
   }
   if(arr.size()==1) return arr[0]/2;
   int sum=0;
   for(int i=0;i<arr.size();i++) {
      if(arr[i]==0) arr[i]=2;
      sum+=arr[i];
   }
   return sum/2;
}

int main(void)
{
   while(scanf("%d %d",&n,&m)==2) {
      for(int i=1;i<=n;i++)
         adj[i].clear();
      for(int i=0;i<m;i++) {
         int v,u;
         scanf("%d %d",&v,&u);
         adj[v].push_back(u);
         adj[u].push_back(v);
      }
      printf("%d\n",solve());
   }
   return 0;
}