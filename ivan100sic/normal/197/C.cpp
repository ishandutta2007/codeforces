#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 131072
#define OFFS 131071
using namespace std;

struct slovo{
   char x;
   int p;
};

int RMC[2*MAXN],N,i,j;
slovo Tree[2*MAXN],dz;
char S[105000];

slovo boljicvor(slovo a,slovo b){
   if (a.x > b.x) return a;
   if (a.x < b.x) return b;
   if (a.p < b.p) return a;
   return b;
}

void spremi(){
   scanf("%s",S);
   N=strlen(S);
   for (i=0; i<N; i++){
      Tree[i+MAXN].x = S[i];
      Tree[i+MAXN].p = i+1;
   }
   for (i=MAXN; i<2*MAXN; i++) RMC[i]=i;
   for (i=OFFS; i>=1; i--){
      Tree[i] = boljicvor(Tree[2*i],Tree[2*i+1]);
      RMC[i] = RMC[2*i+1];
   }
}

slovo vadi(int l,int r){
   l+=OFFS;
   r+=OFFS;
   bool used=false;
   slovo rez;
   while (l<=r){
      while (l%2==0 && RMC[l/2]<=r) l/=2;
      if (!used){
         used=true;
         rez = Tree[l];
      } else {
         rez = boljicvor(rez,Tree[l]);
      }
      l = RMC[l]+1;
   }
   return rez;
}

int main(){
   spremi();
   j=1;
   while (j<=N){
      dz = vadi(j,N);
      printf("%c",dz.x);
      j = dz.p + 1;
   }
   printf("\n");
   return 0;
}