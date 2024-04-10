#include <cstdio>
using namespace std;

int main(){
   long N,i,j,k,mx=0;
   scanf("%ld",&N);
   k=0;
   while (N--){
      scanf("%ld %ld",&i,&j);
      k+=j-i;
      if (k>mx) mx=k;
   }
   printf("%ld",mx);
}