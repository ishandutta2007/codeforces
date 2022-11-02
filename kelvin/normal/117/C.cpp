#include <stdio.h>
#include <vector>
#define MAXN 5050

using namespace std;

int n;
char mat[MAXN][MAXN];

bool visited[MAXN]={0};
bool instack[MAXN]={0};
int sn,stk[MAXN],pos[MAXN];
vector<int> cyc;

bool dfs(int v) {
   visited[v]=1;
   instack[v]=1;
   pos[v]=sn;
   stk[sn++]=v;
   for(int u=1;u<=n;u++) {
      if(u==v) continue;
      if(mat[v][u]!='1') continue;
      if(instack[u]) {
         for(int i=pos[u];i<sn;i++)
            cyc.push_back(stk[i]);
         return 1;
      }
      if(!visited[u]) {
         if(dfs(u)) return 1;
      }
   }
   sn--;
   instack[v]=0;
   return 0;
}

inline bool findCycle() {
   sn=0;
   cyc.clear();
   for(int i=1;i<=n;i++) {
      if(!visited[i]) {
         if(dfs(i)) return 1;
      }
   }
   return 0;
}

inline bool solve() {
   if(!findCycle()) return 0;
   int rt=cyc[0],len=cyc.size();
   for(int i=1;i<len-1;i++) {
      int v=cyc[i],u=cyc[i+1];
      if(mat[rt][v]=='1'&&mat[u][rt]=='1') {
         printf("%d %d %d\n",rt,v,u);
         break;
      }
   }
   return 1;
}

int main(void)
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
      scanf("%s",mat[i]+1);
   if(!solve()) puts("-1");
   return 0;
}