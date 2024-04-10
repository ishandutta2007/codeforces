#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[105],B[105],N,KKK,i,j,k,l;

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++) scanf("%d",A+i);
   for (i=1; i<=N+1; i++){
      if (A[i] < 0) j++;
      if (j==3 || i==N+1){
         j=1;
         KKK++;
         B[KKK] = i-1;
      }
   }
   printf("%d\n",KKK);
   for (i=1; i<=KKK; i++) printf("%d%c",B[i]-B[i-1],i==N?'\n':' ');
   return 0;
}