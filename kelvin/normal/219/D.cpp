#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 200050

using namespace std;

typedef pair<int,int> pii;

const int inf=100000000;

int n;
vector<pii> adj[MAXN];
int visited[MAXN],visid=0,cc;
int cost[MAXN];

void cnt(int v) {
   visited[v]=visid;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i].first;
      if(visited[u]==visid) continue;
      cc+=adj[v][i].second;
      cnt(u);
   }
}

void dfs(int v,int c) {
   visited[v]=visid;
   cost[v]=c;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i].first;
      if(visited[u]==visid) continue;
      int nc=adj[v][i].second?c-1:c+1;
      dfs(u,nc);
   }
}

void solve() {
   int opt=inf;
   vector<int> ans;
   cc=0;
   ++visid;
   cnt(1);
   ++visid;
   dfs(1,cc);
   for(int i=1;i<=n;i++) {
      if(cost[i]<opt) {
         opt=cost[i];
         ans.clear();
      }
      if(cost[i]==opt) ans.push_back(i);
   }
   printf("%d\n",opt);
   for(int i=0;i<ans.size();i++)
      printf("%d%c",ans[i],i+1<ans.size()?' ':'\n');
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n-1;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v].push_back(make_pair(u,0));
      adj[u].push_back(make_pair(v,1));
   }
   solve();
   return 0;
}