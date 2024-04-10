#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A,B,N;
int i,j,k,l,m,n;

int main(){
   scanf("%d%d%d",&A,&B,&N);
   k = 10*A % B;
   if (k==0) k=B;
   j = B-k;
   if (j<10){
      printf("%d",A);
      putchar(j+48);
      for (l=1; l<=N-1; l++) putchar('0');
   } else {
      printf("-1");
   }
   puts("");
   return 0;
}