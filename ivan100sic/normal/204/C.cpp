#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long SumaPrvi[200005],SumaDrugi[200005],N,i,j,k,l,m,n,sol,big;
double xs,xb;
char S1[200005],S2[200005],c;

void ofc(){
   if (sol<0){
      sol+=1000000000000000000ll;
      xs-=1.0;
   }
   if (sol>=1000000000000000000ll){
      xs+=(double)(sol/1000000000000000000ll);
      sol%=1000000000000000000ll;
   }
}

int main(){
   scanf("%I64d%s%s",&N,S1+1,S2+1);
   for (c='A'; c<='Z'; c++){
      memset(SumaPrvi,0,sizeof(SumaPrvi));
      memset(SumaDrugi,0,sizeof(SumaDrugi));
      for (i=N; i>=1ll; i--){
         if (S2[i]==c) SumaDrugi[i]+=N-i+1ll;
         SumaDrugi[i]+=SumaDrugi[i+1ll];
      }
      for (i=N; i>=1ll; i--){
         if (S1[i]==c) SumaPrvi[i]+=N-i+1ll;
         SumaPrvi[i]+=SumaPrvi[i+1ll];
      }
      for (i=1ll; i<=N; i++){
         if (S1[i]==c){
            sol+=i*SumaDrugi[i];
            ofc();
         }
      }
      for (i=1ll; i<=N; i++){
         if (S2[i]==c){
            sol+=i*SumaPrvi[i];
            ofc();
         }
      }
      for (i=1ll; i<=N; i++){
         if (S1[i]==S2[i] && S1[i]==c){
            sol-=i*(N-i+1ll);
            ofc();
         }
      }
   }
   xs*=1e18;
   xs+=(double)sol;
   big = N*(1.0+N*(3.0+2.0*N)) / 6.0;
   //return (int)sol;
   printf("%.9lf\n",xs/big);
   return 0;
}