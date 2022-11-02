#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAXN 1050

using namespace std;

const int inf=100000000;

inline int min(int a,int b) { return a<b?a:b; }

class Pair {
   public:
      int f,t,c;
      Pair(int fi,int ti,int ci):f(fi),t(ti),c(ci) {}
      void print() {
         printf("%d %d %d\n",f,t,c);
      }
      const bool operator<(const Pair &b) const {
         return f<b.f;
      }
};

int n,m;
int in[MAXN]={0};
int deg[MAXN]={0},adj[MAXN][MAXN],cap[MAXN][MAXN];
vector<Pair> arr;

void dfs(int v,int s,int c) {
   if(!deg[v]) {
      arr.push_back(Pair(s,v,c));
      return;
   }
   dfs(adj[v][0],s,min(c,cap[v][adj[v][0]]));
}

inline void solve() {
   int i;
   for(i=1;i<=n;i++) {
      if(in[i]) continue;
      if(!in[i]&&!deg[i]) continue;
      dfs(i,i,inf);
   }
   printf("%d\n",arr.size());
   std::sort(arr.begin(),arr.end());
   for(i=0;i<arr.size();i++)
      arr[i].print();
}

int main(void)
{
   int i,v,u,c;
   scanf("%d %d",&n,&m);
   for(i=0;i<m;i++) {
      scanf("%d %d %d",&v,&u,&c);
      adj[v][deg[v]++]=u;
      in[u]++;
      cap[v][u]=c;
   }
   solve();
   return 0;
}