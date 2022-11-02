#include <iostream>
#include <stdio.h>
#include <vector>
#define MAXN 100050

using namespace std;

int n;
vector<int> adj[MAXN];

int cnt;
int visited[MAXN]={0},visid=0;

int ql,qr,que[MAXN];
int arr[MAXN];

inline bool islucky(int w) {
   while(w) {
      int x=w%10;
      if(x!=4&&x!=7) return 0;
      w/=10;
   }
   return 1;
}

inline void bfs(int s) {
   int i,v,u;
   ql=qr=0;
   visited[s]=visid;
   que[qr++]=s;
   while(ql<qr) {
      v=que[ql++];
      for(i=0;i<adj[v].size();i++) {
         u=adj[v][i];
         if(visited[u]==visid) continue;
         que[qr++]=u;
         visited[u]=visid;
      }
   }
   for(i=0;i<qr;i++)
      arr[que[i]]=n-qr;
}

inline long long solve() {
   int i;
   long long sol=0;
   ++visid;
   for(i=1;i<=n;i++)
      if(visited[i]<visid) bfs(i);
   for(i=1;i<=n;i++)
      sol+=(long long)arr[i]*(arr[i]-1);
   return sol;
}

int main(void)
{
   int i,v,u,w;
   while(scanf("%d",&n)==1) {
      for(i=1;i<=n;i++)
         adj[i].clear();
      for(i=0;i<n-1;i++) {
         scanf("%d %d %d",&v,&u,&w);
         if(!islucky(w)) {
            adj[v].push_back(u);
            adj[u].push_back(v);
         }
      }
      cout << solve() << endl;
   }
   return 0;
}