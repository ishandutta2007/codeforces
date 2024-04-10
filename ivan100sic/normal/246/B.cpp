#include <cstdio>
#include <cstring>
using namespace std;

int S,N,i,j;

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++){
      scanf("%d",&j);
      S+=j;
   }
   if (S%N == 0) printf("%d\n",N); else printf("%d\n",N-1);
   return 0;
}