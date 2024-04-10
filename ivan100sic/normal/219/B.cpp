#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long P,D,i,j,k,l,sol,x,y,p10;

long long nines(long long x){
   x++;
   long long r=0;
   while (x%10==0){
      r++;
      x/=10;
   }
   return r;
}

int main(){
   scanf("%I64d%I64d",&P,&D);
   if (P<10 || D==0){
      printf("%I64d\n",P);
      return 0;
   }
   p10=1;
   for (i=0; i<=19; i++){
      x = P - P%p10 - 1;
      if (P%p10+1 <= D){
         y = x;
      }
      p10*=10;
   }
   if (nines(P) >= nines(y)) printf("%I64d\n",P); else printf("%I64d\n",y);
   return 0;
}