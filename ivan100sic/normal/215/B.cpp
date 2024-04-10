#include <cstdio>
#include <algorithm>
#include <math.h>
#define max(a,b) (a>b?a:b)
using namespace std;

double X[5005],Y[5005],Z[5005],a,b,c,d,e,r1,r2,o,ratio;
int N,M,K,i,j,k,l;

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++) scanf("%lf",X+i);
   for (i=1; i<=N; i++) if (X[i] > r1) r1=X[i];
   scanf("%d",&M);
   for (i=1; i<=M; i++) scanf("%lf",Y+i);
   scanf("%d",&K);
   for (i=1; i<=K; i++) scanf("%lf",Z+i);

   scanf("%d%d",&j,&k);
   ratio = (double)j / (double)k;

   for (i=1; i<=M; i++){
      for (j=1; j<=K; j++){
         r2 = max(r2 , (r1*r1*Y[i]) / (Y[i]+ratio*Z[j]));
      }
   }
   printf("%.14lf\n",sqrt(r2));
   return 0;
}