#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int C[5000],N,M,K,key,i,j,k,l;
int A[2000000],sol;

int main(){
   scanf("%d%d%d",&N,&M,&K);
   key=1;
   while (true){
      for (i=1; C[i]>=K; i++);
      i = min(i,key);
      if (i>M+N) break;
      for (j=i; j<i+N; j++) C[j]++;
      //printf("%d %d\n",i,key);
      key = i+N-1;
      sol++;
      A[sol] = i;
   }
   printf("%d\n",sol);
   for (i=1; i<=sol; i++) printf("%d\n",A[i]);
   return 0;
}