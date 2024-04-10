#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long D1,D2,X,i,j,k,l,m,n,sol;

int main(){
   scanf("%lld",&X);
   //zero
   //single digit nums:
   for (D1=1; D1<=9; D1++){
      j=0;
      while (j<=X){
         j*=10;
         j+=D1;
         if (j<=X) sol++;
      }
   }
   //different digit nums:
   for (D1=0; D1<=9; D1++){
      for (D2=0; D2<=9; D2++) if (D1<D2){
         for (m=1; m<=9; m++){
            for (j=1; j<=(1<<(m+1))-2; j++){
               k=0;
               for (l=0; l<=m; l++){
                  k*=10;
                  if ((1<<l)&j){
                     k+=D1;
                  } else {
                     k+=D2;
                  }
               }
               if ((1&j) >0 && D1==0) k=1000000001;
               if ((1&j)==0 && D2==0) k=1000000001;
               if (k<=X){
                  sol++;
                  //printf("%lld %lld %lld\n",m,j,k);
               }
            }
         }
      }
   }
   printf("%lld\n",sol);
   return 0;
}