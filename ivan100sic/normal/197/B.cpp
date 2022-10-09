#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
   if (b==0) return a; else return gcd(b,a%b);
}

int P[105],Q[105],p,q,N,M,i,j,k,l;
bool minus;

int main(){
   scanf("%d%d",&N,&M);
   for (i=N; i>=0; i--) scanf("%d",P+i);
   for (i=M; i>=0; i--) scanf("%d",Q+i);
   if (N>M){
      if (P[N]*Q[M] < 0) printf("-");
      printf("Infinity\n");
   } else if (N<M) printf("0/1\n"); else {
      p=P[N];
      q=Q[N];
      if (q<0){
         p*=-1;
         q*=-1;
      }
      if (p<0){
         minus=true;
         p*=-1;
      }
      k = gcd(p,q);
      p/=k;
      q/=k;
      if (minus) printf("-");
      printf("%d/%d\n",p,q);
   }
   return 0;
}