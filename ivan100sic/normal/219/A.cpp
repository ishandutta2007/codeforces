#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[1005],R[1005];
int N,K,C[200],NN,i,j,k;

int main(){
   scanf("%d%s",&K,S+1);
   N = strlen(S+1);
   for (i=1; i<=N; i++) C[S[i]]++;
   for (i='a'; i<='z'; i++){
      if (C[i]%K != 0){
         printf("-1\n");
         return 0;
      }
   }
   for (i='a'; i<='z'; i++){
      for (j=1; j<=C[i]/K; j++){
         NN++;
         R[NN] = i;
      }
   }
   for (i=1; i<=K; i++) printf("%s",R+1);
   puts("");
   return 0;
}