#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,i;

int main(){
   scanf("%d",&N);
   if (N<=2){
      printf("-1\n");
      return 0;
   }
   for (i=N; i; i--) printf("%d%c",i,i==1?'\n':' ');
   return 0;
}