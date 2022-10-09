#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,i,j,k;
int Once[100005];

int main(){
   scanf("%d%d",&N,&M);
   if (M%2==1){
      Once[1] = M/2+1;
      for (i=1; i<=M/2; i++){
         Once[2*i] = M/2+1-i;
         Once[2*i+1] = M/2+1+i;
      }
   } else {
      for (i=1; i<=M/2; i++){
         Once[2*i-1] = M/2+1-i;
         Once[2*i] = M/2+i;
      }
   }
   j=1;
   for (k=1; k<=N; k++){
      printf("%d\n",Once[j]);
      j++;
      if (j>M) j=1;
   }
   return 0;
}