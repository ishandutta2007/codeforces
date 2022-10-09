#include <cstdio>
using namespace std;

int main(){
   long deli,N,i,j;
   scanf("%ld",&N);
   deli=0;
   for (i=N; i>1; i--){
      if (deli % i == 0){
         printf("%ld ",i);
         deli=i;
      }
   }
   printf("1\n");
   return 0;
}