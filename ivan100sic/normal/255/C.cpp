#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,A[5005],i,j,k,q,n,jo,f;
bool F[1000005];
int K[1000005];

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++) scanf("%d",A+i);
   if (N<=2){
      printf("%d\n",N);
      return 0;
   }
   k=2;
   for (i=1; i<=N-2; i++){
      j=i;
      while (true){
         jo=j;
         j++;
         while (j <= N && A[j]!=A[i]) j++;
         for (f=jo+1; f<j; f++) F[A[f]]=true;
         //printf("%d %d %d\n",A[i],jo,j);;
         if (j <= N){
            for (f=jo+1; f<j; f++){
               if (F[A[f]]){
                  F[A[f]] = false;
                  K[A[f]] += 2;
               }
            }
            K[A[i]]++;
         } else {
            for (f=jo+1; f<=N; f++){
               if (F[A[f]]){
                  F[A[f]] = false;
                  K[A[f]] += 1;
               }
            }
            break;
         }
      }
      for (f=i; f<=N; f++){
         if (K[A[f]]+1 > k) k = K[A[f]]+1;
         K[A[f]] = 0;
      }
   }
   printf("%d\n",k);
   return 0;
}