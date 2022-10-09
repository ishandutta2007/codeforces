#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[305][105],N,K;
int P[105],i,j,k,l;
bool Q[305],M[305];

int main(){
   scanf("%d%d",&N,&K);
   for (i=1; i<=N; i++) scanf("%d",P+i);
   for (i=1; i<=N; i++) scanf("%d",A[150]+i);
   for (k=151; k<=150+K; k++){
      for (i=1; i<=N; i++) A[k][i] = A[k-1][P[i]];
   }
   for (k=149; k>=150-K; k--){
      for (i=1; i<=N; i++) A[k][P[i]] = A[k+1][i];
   }
   //debug:
   memset(M,1,sizeof(M));
   memset(Q,0,sizeof(Q));

   for (k=150-K; k<=150+K; k++){
      bool moze=true;
      for (i=1; i<=N; i++) if (A[k][i]!=i) moze=false;
      Q[k] = moze;
      moze=true;
      for (i=1; i<=N; i++) if (A[k][i]!=A[150][i]) moze=false;
      M[k] = moze;
   }

   if (Q[150]){
      printf("NO\n");
      return 0;
   }

   if (K==1){
      if (Q[151]) printf("YES\n"); else printf("NO\n");
      return 0;
   }



   //printf("%c %c %c %c %c\n",M[148],M[149],M[150],M[151],M[152]);
   //printf("%c %c %c %c %c\n",Q[148],Q[149],Q[150],Q[151],Q[152]);

   for (k=150-K; k<=150+K; k++){
      if (k%2==K%2){
         if (Q[k] && !(M[k-1] && M[k+1] && K>1)){
            //printf("%d %d\n",k-1,k+1);
            printf("YES\n");
            return 0;
         }
      }
   }
   printf("NO\n");
   return 0;
}