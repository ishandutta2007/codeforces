#include <cstdio>
#define MAXN 3000
using namespace std;

long Dolazeci[MAXN],Odlazeci[MAXN],Kolicina[MAXN],R1[MAXN],R2[MAXN],R3[MAXN],N,P,i,j,k,l,c,flm,kraj;

int main(){
   scanf("%ld%ld",&N,&P);
   for (i=1; i<=P; i++) {
      scanf("%ld%ld%ld",&j,&k,&l);
      Dolazeci[k]=j;
      Odlazeci[j]=k;
      Kolicina[j]=l;
   }
   c=0;
   for (i=1; i<=N; i++){
      if (Dolazeci[i]==0){
         flm=1000000000;
         j=i;
         while (Odlazeci[j]!=0){
            if (Kolicina[j] < flm) flm=Kolicina[j];
            j=Odlazeci[j];
         }
         if (i!=j){
            c++;
            R1[c]=i;
            R2[c]=j;
            R3[c]=flm;
         }
      }
   }
   printf("%ld\n",c);
   for (i=1; i<=c; i++) printf("%ld %ld %ld\n",R1[i],R2[i],R3[i]);
   return 0;
}