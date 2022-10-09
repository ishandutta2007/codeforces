#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int P1[100005],P2[100005],PA[100005],C[100005],N;
int O[200005],RBG[200005],MarkCvor[100005],P[19][100005];
int Sol[100005];
int DfsIn[100005],DfsOut[100005],Vreme;
int Tabela[200005];
int K,a,b,c,d;

void ucitajisredi(){
   scanf("%d",&N);
   int i,j,k;
   for (i=1; i<N; i++){
      scanf("%d%d",P1+i,P2+i);
      C[P1[i]]++;
      C[P2[i]]++;
   }
   PA[1] = 1;
   for (i=2; i<=N+1; i++) PA[i] = PA[i-1] + C[i-1];
   memset(C,0,sizeof(C));
   for (i=1; i<N; i++){
      O[PA[P1[i]]+C[P1[i]]] = P2[i];
      RBG[PA[P1[i]]+C[P1[i]]] = i;
      C[P1[i]]++;
      O[PA[P2[i]]+C[P2[i]]] = P1[i];
      RBG[PA[P2[i]]+C[P2[i]]] = i;
      C[P2[i]]++;
   }
}

void dfsmark(int x,int odakle){
   int i,j;
   Vreme++;
   DfsIn[x] = Vreme;
   for (i=PA[x]; i<PA[x+1]; i++) if (O[i]!=odakle){
      dfsmark(O[i],x);
      P[0][O[i]] = x;
   }
   Vreme++;
   DfsOut[x] = Vreme;
}

void parentize(){
   int i,j;
   for (j=1; j<19; j++){
      for (i=1; i<=N; i++) P[j][i] = P[j-1][P[j-1][i]];
   }
}

bool podstablo(int a, int b){
   return DfsIn[a] > DfsIn[b] && DfsOut[a] < DfsOut[b];
}

int lca(int a,int b){
   if (a==b) return a;
   if (podstablo(a,b)) return b;
   if (podstablo(b,a)) return a;
   for (int i=18; i>=0; i--){
      if (!podstablo(b,P[i][a])) a=P[i][a];
   }
   return P[0][a];
}

void dfssolver(int x,int odakle){
   int i,j;
   for (i=PA[x]; i<PA[x+1]; i++) if (O[i]!=odakle){
      dfssolver(O[i],x);
      MarkCvor[x]+=MarkCvor[O[i]];
      Sol[RBG[i]] = MarkCvor[O[i]];
   }
}

int main(){
   ucitajisredi();
   dfsmark(1,1);
   P[0][1] = 1;
   parentize();
   int i;
   scanf("%d",&K);
   for (i=1; i<=K; i++){
      scanf("%d%d",&a,&b);
      MarkCvor[a]++;
      MarkCvor[b]++;
      MarkCvor[lca(a,b)]-=2;
   }

   //for (i=1; i<=N; i++) printf("%d ",MarkCvor[i]);
   //return 0;

   dfssolver(1,1);
   for (i=1; i<N; i++) printf("%d ",Sol[i]);
   return 0;
}