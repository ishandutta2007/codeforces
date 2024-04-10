#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 100050

using namespace std;

typedef pair<int,int> pii;

int n,m;
vector<pii> adj[MAXN];
bool visited[MAXN]={0};
int value[MAXN];

inline int gcd(int a,int b) {
   while(b) {
      int t=b;
      b=a%b;
      a=t;
   }
   return a;
}

void dfs(int v,int val) {
   visited[v]=1;
   value[v]=val;
   for(int i=0;i<adj[v].size();i++) {
      int u=adj[v][i].first;
      int c=adj[v][i].second;
      if(visited[u]) continue;
      dfs(u,val+c);
   }
}

inline int solve() {
   for(int i=1;i<=n;i++)
      if(!visited[i]) dfs(i,0);
   int g=-1;
   for(int v=1;v<=n;v++) {
      for(int i=0;i<adj[v].size();i++) {
         int u=adj[v][i].first;
         int c=adj[v][i].second;
         int l=abs(value[v]+c-value[u]);
         if(l==0) continue;
         if(g<0) g=l;
         else g=gcd(g,l);
      }
   }
   if(g<0) return n;
   else return g;
}

int main(void)
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<m;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v].push_back(make_pair(u,1));
      adj[u].push_back(make_pair(v,-1));
   }
   printf("%d\n",solve());
   return 0;
}