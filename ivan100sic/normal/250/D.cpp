#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

double KejoviL[100005],KejoviR[100005],DuzineR[100005];
int N,M,A,B;

void ucitaj(){
   scanf("%d%d%d%d",&N,&M,&A,&B);
   int i,j;
   for (i=1; i<=N; i++) scanf("%lf",KejoviL+i);
   for (i=1; i<=M; i++) scanf("%lf",KejoviR+i);
   for (i=1; i<=M; i++) scanf("%lf",DuzineR+i);
   sort(KejoviL+1,KejoviL+N+1);
}

int binarna(double x){
   //prvi manji npr za (1,2,4,6) i x=2.22 vraca o=2
   int l,r,m,o;
   o=0;
   l=1;
   r=N;
   while (l<=r){
      m = (l+r)/2;
      //printf("%d %lf\n",m,x);
      if (KejoviL[m] < x){
         o = m;
         l = m+1;
      } else {
         r = m-1;
      }
   }
   //printf("%lf %d\n",x,o);
   //printf("%lf %lf %lf\n",KejoviL[1],KejoviL[2],KejoviL[3]);
   return o;
}

double mn(double a,double b){
   if (a<b) return a; else return b;
}

double kv(double a){
   return a*a;
}

void resi(){
   int i,j,k,l,is,js;
   double best = 1e15,tgt,b0;
   for (i=1; i<=M; i++){
      tgt = (double)A / (double)B * KejoviR[i];
      j = binarna(tgt);
      if (j>0){
         b0 = best;
         best = mn(best, sqrt(kv(A) + kv(KejoviL[j])) + sqrt(kv(B-A) + kv(KejoviR[i]-KejoviL[j])) + DuzineR[i]);
         if (best < b0){
            is=i;
            js=j;
         }
      }
      if (j<N){
         b0 = best;
         best = mn(best, sqrt(kv(A) + kv(KejoviL[j+1])) + sqrt(kv(B-A) + kv(KejoviR[i]-KejoviL[j+1])) + DuzineR[i]);
         if (best < b0){
            is=i;
            js=j+1;
         }
      }
   }
   printf("%d %d\n",js,is);
}

int main(){
   ucitaj();
   resi();
   return 0;
}