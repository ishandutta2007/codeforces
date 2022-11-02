#include <stdio.h>
#include <vector>
#define MAXN 2050

using namespace std;

int n;
int p[MAXN];
vector<int> adj[MAXN];

int ql,qr;
int que[MAXN],d[MAXN];

inline int bfs(int s) {
   ql=qr=0;
   que[qr++]=s;
   d[s]=1;
   while(ql<qr) {
      int v=que[ql++];
      for(int i=0;i<adj[v].size();i++) {
         int u=adj[v][i];
         que[qr++]=u;
         d[u]=d[v]+1;
      }
   }
   return d[que[qr-1]];
}

inline int solve() {
   int v,d,maxd=0;
   for(v=1;v<=n;v++) {
      if(p[v]>=0) continue;
      d=bfs(v);
      if(d>maxd) maxd=d;
   }
   return maxd;
}

int main(void)
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++) {
      scanf("%d",p+i);
      adj[p[i]].push_back(i);
   }
   printf("%d\n",solve());
   return 0;
}