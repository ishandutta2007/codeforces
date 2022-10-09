#include <cstdio>
#include <cstring>
using namespace std;

int N,K,dvoj;

int main(){
   scanf("%d%d",&N,&K);
   while (2*N < K){
      N--;
      K-=3;
   }
   if (N<0) printf("0\n"); else printf("%d\n",N);
   return 0;
}