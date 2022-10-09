#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 131072
#define OFFS 131071
using namespace std;


struct polje{
   int x,vr;
};

bool cmppolja(polje a,polje b){
   return a.vr > b.vr;
}

int N,Perm[100005],Vred[100005],K,lutalica,i,j,k;
long long Budzet,Suma;
bool Used[100005];
polje A[100005];

int main(){
   scanf("%d%d%I64d",&N,&K,&Budzet);
   for (i=1; i<N; i++){
      scanf("%d",&A[i].vr);
      A[i].x = i;
      Vred[i] = A[i].vr;
   }
   sort(A+1,A+N,cmppolja);
   for (i=1; i<N; i++) Perm[A[i].x] = i;
   for (i=1; i<K; i++) Suma+=A[i].vr;

   //for (i=1; i<N; i++) printf("%d ",Perm[i]);
   //printf("\n");
   //printf("%lld\n",Suma);

   lutalica = K-1;
   for (i=1; i<=N-K; i++){
      Used[Perm[i]] = true;
      if (Perm[i] <= lutalica){
         Suma-=Vred[i];
         lutalica++;
         while (Used[lutalica]) lutalica++;
         Suma+=A[lutalica].vr;
      }
      //printf("%d %lld %d\n",i,Suma,lutalica);
      if (Suma+Vred[i] > Budzet){
         printf("%d\n",i);
         return 0;
      }
   }
   printf("%d\n",N);
   return 0;
}