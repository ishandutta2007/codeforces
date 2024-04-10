#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long double ld;

long long N, i, j, k, l, m, n;
long double SumaPrvi[200005],SumaDrugi[200005],sol,big;
double xs,xb;
char S1[200005],S2[200005],c;

int main(){
   scanf("%lld%s%s",&N,S1+1,S2+1);
   for (c='A'; c<='Z'; c++){
      memset(SumaPrvi,0,sizeof(SumaPrvi));
      memset(SumaDrugi,0,sizeof(SumaDrugi));
      for (i=N; i>=1; i--){
         if (S2[i]==c) SumaDrugi[i]+=N-i+ld(1);
         SumaDrugi[i]+=SumaDrugi[i+1];
      }
      for (i=N; i>=1; i--){
         if (S1[i]==c) SumaPrvi[i]+=N-i+ld(1);
         SumaPrvi[i]+=SumaPrvi[i+1];
      }
      for (i=1; i<=N; i++){
         if (S1[i]==c){
            sol+=i*SumaDrugi[i];
         }
      }
      //printf("%c %lld\n",c,sol);
      for (i=1; i<=N; i++){
         if (S2[i]==c){
            sol+=i*SumaPrvi[i];
         }
      }
      //printf("%c %lld\n",c,sol);
      for (i=1; i<=N; i++){
         if (S1[i]==S2[i] && S1[i]==c){
            sol-=i*(N-i+ld(1));
         }
      }
      //printf("%c %lld\n",c,sol);
   }
   big = N+(3ll*N*N+2ll*N*N*N);
   big/=6;
   //return (int)sol;
   xs = sol;
   xb = big;
   printf("%.9lf\n",xs/xb);
   return 0;
}