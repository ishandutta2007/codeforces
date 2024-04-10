#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool Used[1000];
int N,i,j,k,A[50],S[50][50],K,L[50];

int main(){
   scanf("%d%d",&N,&K);
   for (i=1; i<=K; i++) scanf("%d",A+i);
   for (i=1; i<=K; i++){
      S[i][1] = A[i];
      L[i]++;
      Used[A[i]]=true;
   }
   j=1;
   for (i=1; i<=N*K; i++){
      if (!Used[i]){
         if (L[j]==N) j++;
         L[j]++;
         S[j][L[j]] = i;
      }
   }
   for (i=1; i<=K; i++){
      for (j=1; j<=N; j++) printf("%d%c",S[i][j],j==N?'\n':' ');
   }
   return 0;
}