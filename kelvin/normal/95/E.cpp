#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 100060

using namespace std;

const int lim=330;
const int inf=1000000000;

int n,m;
vector<int> adj[MAXN];

int ccc;
vector<int> arr;
bool visited[MAXN]={0};

int ql,qr,que[MAXN],time[MAXN];
int curmax=0,dp[MAXN]={0};

void dodp(int x,int c) {
   int s,j,z;
//   for(j=0;j<=curmax;j++)
//      printf("%d ",dp[j]);puts("");
   for(j=curmax+1;j<=curmax+x*c;j++)
      dp[j]=inf;
   for(s=0;s<x;s++) {
      ql=qr=0;
      for(j=s,z=0;j<=curmax+x*c;j+=x,z++) {
         while(ql<qr&&time[ql]<z-c) ql++;
         if(j<=curmax) {
            while(ql<qr&&que[qr-1]>=dp[j]) qr--;
            que[qr]=dp[j]-z;
            time[qr]=z;
            qr++;
         }
         if(ql<qr) {
            dp[j]=z+que[ql];
         }
      }
   }
   curmax+=x*c;
//   for(j=0;j<=curmax;j++)
//      printf("%d ",dp[j]);puts("");
//   puts("==");
}

void dfs(int v) {
   int i,j,u;
   ccc++;
   visited[v]=1;
   for(i=0;i<adj[v].size();i++) {
      u=adj[v][i];
      if(visited[u]) continue;
      dfs(u);
   }
}

inline bool islucky(int x) {
   while(x) {
      int t=x%10;
      if(t!=4&&t!=7) return 0;
      x/=10;
   }
   return 1;
}
int solve() {
   int i,j,sol;
   for(i=0;i<n;i++) {
      if(visited[i]) continue;
      ccc=0;
      dfs(i);
      arr.push_back(ccc);
   }
   std::sort(arr.begin(),arr.end());
//   for(i=0;i<arr.size();i++)
//      printf("<%d>",arr[i]);puts("");
   for(i=0;i<arr.size();i=j) {
      for(j=i;j<arr.size()&&arr[i]==arr[j];j++);
      dodp(arr[i],j-i);
   }
   sol=inf;
   for(i=1;i<=curmax;i++) {
      if(!islucky(i)) continue;
//      printf("%d %d\n",i,dp[i]);
      if(dp[i]<sol) sol=dp[i];
   }
   if(sol==inf) sol=0;
   return sol-1;
}

int main(void)
{
   int i,v,u;
   scanf("%d %d",&n,&m);
   for(i=0;i<m;i++) {
      scanf("%d %d",&v,&u);
      v--;
      u--;
      adj[v].push_back(u);
      adj[u].push_back(v);
   }
   printf("%d\n",solve());
   return 0;
}