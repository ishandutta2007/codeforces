#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[100005],L,R,N,i,j,k,K;
long long sol,f;

int main(){
   scanf("%d%d",&N,&K);
   for (i=1; i<=N; i++) scanf("%d",A+i);
   sort(A+1,A+N+1);
   L=1;
   R=2;
   for (L=1; L<=N-2; L++){
      while (A[R+1]-A[L]<=K && R<N) R++;
      f = R-L;
      if (f>1) sol += f*(f-1)/2;
   }
   printf("%I64d\n",sol);
   return 0;
}