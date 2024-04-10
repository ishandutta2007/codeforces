#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[3],r;

int main(){
   scanf("%d%d%d",A+0,A+1,A+2);
   sort(A,A+3);
   while (A[0]>1){
      r += 2*(A[0]+A[1]+A[2]-3);
      A[0]--;
      A[1]--;
      A[2]--;
   }
   r+=A[1]*A[2];
   printf("%d\n",r);
   return 0;
}