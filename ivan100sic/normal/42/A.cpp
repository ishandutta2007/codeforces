#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,i,j,k,l;
double V,A[50],B[50],xm,all;

int main(){
   xm=1e20;
   scanf("%d%lf",&N,&V);
   for (i=1; i<=N; i++) scanf("%lf",A+i);
   for (i=1; i<=N; i++) scanf("%lf",B+i);
   for (i=1; i<=N; i++){
      all+=A[i];
      if (B[i]/A[i] < xm) xm=B[i]/A[i];
   }
   if (xm*all > V) printf("%.9lf\n",V); else printf("%.9lf\n",xm*all);
   return 0;
}