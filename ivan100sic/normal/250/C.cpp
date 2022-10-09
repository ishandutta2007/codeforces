#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Reduce[100005],A[100005];
int G[100005],GS[100005],GGG;
int N,K,i,j,k,l;

int main(){
   scanf("%d%d",&N,&K);
   for (i=1; i<=N; i++) scanf("%d",A+i);

   for (i=1; i<=N; i++){
      if (A[i]==A[i-1]){
         GS[GGG]++;
      } else {
         GGG++;
         G[GGG] = A[i];
         GS[GGG] = 1;
      }
   }

   for (i=2; i<=GGG-1; i++){
      Reduce[G[i]]++;
      if (G[i-1] == G[i+1]) Reduce[G[i]]++;
   }
   Reduce[G[GGG]]++;
   Reduce[G[1]]++;

   k=1;
   for (i=2; i<=N; i++) if (Reduce[i] > Reduce[k]) k=i;
   printf("%d\n",k);
   return 0;
}