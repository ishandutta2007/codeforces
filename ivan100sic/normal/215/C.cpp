#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long N,M,S,a,b,c,d,e,f,g,h,sol,dx,dy,i,j,k,os;

int main(){
   scanf("%I64d%I64d%I64d",&N,&M,&S);
   for (i=1; i<=N; i+=2){
      for (j=1; j<=M; j+=2) if (i*j==S){
         d=2ll*((i+1)/2)*((j+1)/2) - 1ll;
         sol += d*(N-i+1)*(M-j+1);
      }
   }
   for (i=1; i<=N; i+=2){
      for (j=1; j<=M; j+=2) if (i*j > S){
         for (dx=2; true; dx+=2){ //include a break
            os = sol;
            //i*j - dx*dy == S;
            dy = (i*j-S) / dx;
            if (dy==0 || dx>=i) break;
            if (i*j - dx*dy == S && dy%2 == 0 && dy < j) sol+=2ll*(N-i+1)*(M-j+1);
            //if (os < sol) printf("%I64d %I64d %I64d %I64d\n",i,j,dx,dy);
         }
      }
   }
   printf("%I64d\n",sol);
   return 0;
}