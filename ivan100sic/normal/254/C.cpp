#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S1[100005],S2[100005],X[100005];
int L[256],N,i,j,k,l;
int V[256],F[256];

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   scanf("%s",S1+1);
   scanf("%s",S2+1);
   N = strlen(S1+1);
   for (i=1; i<=N; i++) L[S2[i]]++;
   for (i=1; i<=N; i++){
      if (L[S1[i]] > 0) L[S1[i]]--; else{
         k++;
         V[S1[i]]++;
      }
   }
   printf("%d\n",k);
   //memset(L,0,sizeof(L));
   //for (i=1; i<=N; i++) L[S2[i]]++;
   for (i=1; i<=N; i++) F[S1[i]]++;
   for (i=1; i<=N; i++){
      if (V[S1[i]]){
         //lagodno
         if (V[S1[i]] != F[S1[i]]){
            for (j='A'; j<S1[i]; j++) if (L[j]){
               L[j]--;
               X[i] = j;
               V[S1[i]]--;
               goto blaa;
            }
            X[i] = S1[i];
            //L[S1[i]]--;
         } else { //gusto, mora menjas
            for (j='A'; j<='Z'; j++) if (L[j] && j!=S1[i]){
               L[j]--;
               X[i] = j;
               V[S1[i]]--;
               goto blaa;
            }
         }
      } else {
         X[i] = S1[i];
      }
      blaa:
      F[S1[i]]--;
      //printf("%d %d %d %d\n",i,L['A'],L['B'],L['C']);
   }
   printf("%s\n",X+1);
   k=0;
   sort(S2+1,S2+N+1);
   sort(X+1,X+N+1);
   //printf("%s\n%s\n",S2+1,X+1);
   return k;
}