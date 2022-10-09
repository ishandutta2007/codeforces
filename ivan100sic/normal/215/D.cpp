#include <cstdio>
#define min(a,b) (a<b?a:b)
using namespace std;

long long sol,t1,t2,x,cost,N,M,i,j,k,guraj,redjaj;

int main(){
   scanf("%I64d%I64d",&N,&M);
   for (i=1; i<=N; i++){
      scanf("%I64d%I64d%I64d%I64d",&t1,&t2,&x,&cost);
      k = t2-t1;
      //sol += min(cost + M*x , (k>0ll)?(((M+k-1)/k)*cost):(999999999999999999ll));
      guraj = cost + M*x;
      if (k<=0) sol+=guraj; else {
         redjaj = ((M+k-1)/k)*cost;
         sol += min(guraj,redjaj);
      }
   }
   printf("%I64d\n",sol);
   return 0;
}