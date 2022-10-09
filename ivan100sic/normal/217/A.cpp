#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int X[105],Y[105],N,i,j,k,l,sol;
bool Vis[105];

void dfs(int x){
   Vis[x] = true;
   for (int i=1; i<=N; i++){
      if (!Vis[i] && (X[i]==X[x] || Y[i]==Y[x])) dfs(i);
   }
}

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++) scanf("%d%d",X+i,Y+i);
   sol=-1;
   for (i=1; i<=N; i++){
      if (!Vis[i]){
         dfs(i);
         sol++;
      }
   }
   printf("%d\n",sol);
   return 0;
}