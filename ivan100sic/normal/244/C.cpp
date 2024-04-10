#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool U[1100000];
int N,A[100005],i,j,k,l,K;

int main(){
   scanf("%d",&N);
   K=1;
   A[1]=0;
   for (i=1; i<=N; i++){
      scanf("%d",&j);
      for (l=1; l<=K; l++){
         A[l] = A[l] | j;
      }
      K++;
      A[K]=j;
      sort(A+1,A+K+1);
      k=K;
      K=1;
      for (l=2; l<=k; l++){
         if (A[l]!=A[l-1]){
            K++;
            A[K]=A[l];
         }
      }
      for (l=1; l<=K; l++) U[A[l]]=true;
      //printf("%d\n",K);
      //for (l=1; l<=K; l++) printf("%d ",A[l]);
      //puts("");
   }
   K=0;
   for (i=0; i<1100000; i++) if (U[i]) K++;
   printf("%d\n",K);
   return 0;
}