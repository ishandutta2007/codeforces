#include <cstdio>
#include <cstring>
#define OFS 20
using namespace std;

int C[50],N,i,j,k;
long long X,Y;

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++){
      scanf("%d",&k);
      k+=OFS;
      C[k]++;
   }
   X=0;
   for (i=1; i<=10; i++){
      Y=C[i+OFS];
      Y*=C[-i+OFS];
      X+=Y;
   }
   Y=C[OFS];
   Y*=C[OFS]-1;
   Y/=2;
   X+=Y;
   printf("%I64d",X);
   return 0;
}