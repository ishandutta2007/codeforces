#include <cstdio>

int A[4],N,i,j;

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++){
      scanf("%d",&j);
      A[i%3]+=j;
   }
   if (A[0] > A[1] && A[0] > A[2]) printf("back\n"); else
   if (A[1] > A[2]) printf("chest\n"); else printf("biceps\n");
   return 0;
}