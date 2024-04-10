#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[2000005],N,i,j,k,l;
long long sol;

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++) scanf("%d",A+i);
   sort(A+1,A+N+1);
   reverse(A+1,A+N+1);
   for (i=1; i<=N; i++){
       k=0;
       j=i;
       while (j<=N){
           j *= 4;
           k++;
       }
       sol += (long long)k * A[i];
   }
   printf("%I64d\n",sol);
   return 0;
}