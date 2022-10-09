#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int P1[1005],P2[1005],PA[1005],C[1005],O[1005],N,M;

void ucitajisredi(){
   int i,j,k;
   scanf("%d%d",&N,&M);
   for (i=1; i<=M; i++){
      scanf("%d%d",P1+i,P2+i);
      C[P1[i]]++;
      C[P2[i]]++;
   }
   PA[1] = 1;
   for (i=2; i<=N+1; i++) PA[i] = PA[i-1] + C[i-1];
   memset(C,0,sizeof(C));
   for (i=1; i<=M; i++){
      O[C[P1[i]]+PA[P1[i]]] = P2[i];
      O[C[P2[i]]+PA[P2[i]]] = P1[i];
      C[P1[i]]++;
      C[P2[i]]++;
   }
}

bool Vis[1005];
int Cvorova,Stepeni,ParC,NepC,ParP,NepP;
int i,j,k;

void dfs(int x){
   Cvorova++;
   Vis[x] = true;
   int i;
   for (i=PA[x]; i<PA[x+1]; i++){
      Stepeni++;
      if (!Vis[O[i]]){
         dfs(O[i]);
      }
   }
}

int main(){
   ucitajisredi();
   for (i=1; i<=N; i++) if (!Vis[i]){
      Cvorova = 0;
      Stepeni = 0;
      dfs(i);
      if (Cvorova*2 == Stepeni){
         if (Cvorova % 2 == 1) NepC++; else ParC++;
      } else {
         if (Cvorova % 2 == 1) NepP++; else ParP++;
      }
   }
   printf("%d\n",NepC+NepP%2);
   return 0;
}