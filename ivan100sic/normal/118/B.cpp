#include <cstdio>
using namespace std;

int N,i,j,k,d;

void stred(int x){
   int i;
   for (i=1; i<=2*(N-x); i++) printf(" ");
   for (i=0; i<x; i++) printf("%d ",i);
   for (i=x; i>0; i--) printf("%d ",i);
   printf("0\n");
   return;
}

int main(){
   scanf("%d",&N);
   for (k=0; k<N; k++) stred(k);
   for (k=N; k>=0; k--) stred(k);
   return 0;
}