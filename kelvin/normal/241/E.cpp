#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1050
#define MAXM 10050

using namespace std;
typedef pair<int,int> pii;

const int inf=100000000;

class Edge {
   public:
      int v,u,c;
      Edge() {}
      Edge(int _v,int _u,int _c):v(_v),u(_u),c(_c) {}
};

int n,m,m2;
vector<int> adj[MAXN];
Edge ed[MAXM],ed2[MAXM];
int d[MAXN];

bool can1[MAXN],cann[MAXN];

void pre() {
   can1[1]=1;
   for(int v=1;v<=n;v++) {
      if(!can1[v]) continue;
      for(int i=0;i<adj[v].size();i++) {
         int u=adj[v][i];
         can1[u]=1;
      }
   }
   cann[n]=1;
   for(int v=n;v>=1;v--) {
      for(int i=0;i<adj[v].size();i++) {
         int u=adj[v][i];
         if(cann[u]) cann[v]=1;
      }
   }
}

bool sub() {
   bool flag=0;
   for(int i=0;i<m2;i++) {
      int v=ed2[i].v;
      int u=ed2[i].u;
      if(!can1[v]||!cann[v]) continue;
      if(!can1[u]||!cann[u]) continue;
      int c=ed2[i].c;
      if(d[v]+c<d[u]) {
         //d[u]=min(d[u],d[v]+c);
         d[u]=d[v]+c;
         flag=1;
      }
   }
   return flag;
}

void solve() {
   pre();
   for(int i=1;i<=n;i++)
      d[i]=inf;
   d[1]=0;
   for(int t=0;t<4*n;t++)
      sub();
   if(sub()) {
      puts("No");
      return;
   }
   puts("Yes");
   for(int i=0;i<m;i++) {
      int v=ed[i].v;
      int u=ed[i].u;
      if(!can1[v]||!cann[v]||!can1[u]||!cann[u]) printf("1\n");
      else printf("%d\n",d[u]-d[v]);
   }
}

int main(void)
{  
   scanf("%d %d",&n,&m);
   m2=0;
   for(int i=0;i<m;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v].push_back(u);
      ed[i]=Edge(v,u,1); //make_pair(v,u);
      ed2[m2++]=Edge(v,u,2);
      ed2[m2++]=Edge(u,v,-1);
   }
   solve();
   return 0;
}