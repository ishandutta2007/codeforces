#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[100],B[100],N,M,i,j,k,l,m,mc;

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++) scanf("%d",A+i);
   scanf("%d",&M);
   for (i=1; i<=M; i++) scanf("%d",B+i);
   mc = 0;
   m = -1;
   for (i=1; i<=N; i++){
      for (j=1; j<=M; j++){
         if (B[j] % A[i] == 0){
            l = B[j]/A[i];
            if (l==m){
               mc++;
            } else
            if (l>m){
               mc=1;
               m=l;
            }
         }
      }
   }
   printf("%d\n",mc);
   return 0;
}