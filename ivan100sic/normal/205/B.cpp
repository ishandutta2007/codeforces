#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1112223334
using namespace std;

int i,j,k,l,N,A[100005],B[100005],C[100005];
long long sol;

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++) scanf("%d",A+i);
   for (i=1; i<=N; i++){
      if (A[i]>B[i-1]) B[i] = A[i]; else B[i]=B[i-1];
   }
   for (i=1; i<=N; i++) C[i]=B[i]-A[i];
   for (i=0; i<=N; i++){
      sol+=abs(C[i]-C[i+1]);
   }
   //for (i=1; i<=N; i++) printf("%d\n",C[i]);
   printf("%I64d\n",sol/2);
   return 0;
}