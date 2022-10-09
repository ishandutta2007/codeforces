#include <cstdio>
#include <cstring>
using namespace std;

int x,n,px;

int main(){
   scanf("%d",&x);
   if (x==3){
      printf("5\n");
      return 0;
   }
   for (n=1; 1; n+=2){
      px = n*n/2+1;
      if (px>=x){
         printf("%d\n",n);
         return 0;
      }
   }
   return 0;
}