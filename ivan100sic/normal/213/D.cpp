#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#define PI 3.14159265358979323
using namespace std;

double Px[6],Py[6],shift,rad;
int N,i,j,k,l;

void napravi1(){
   rad = 5.0 / sin(PI/5.0);
   for (i=0; i<5; i++){
      Px[i] = rad * sin(0.4*PI * (double)i);
      Py[i] = rad * cos(0.4*PI * (double)i);
      shift = Px[1] - Px[4];
   }
}

int finish(int x){
   if (x==2) return 2; else return 4*x-5;
}

int main(){
   scanf("%d",&N);
   napravi1();
   printf("%d\n",5+(N-1)*4);
   for (i=0; i<5; i++) printf("%.14lf %.14lf\n",Px[i],Py[i]);
   for (j=2; j<=N; j++){
      for (i=0; i<4; i++) printf("%.14lf %.14lf\n",Px[i]+(j-1.0)*shift,Py[i]);
   }
   printf("1 2 3 4 5\n");
   for (i=2; i<=N; i++) printf("%d %d %d %d %d\n",4*i-2,4*i-1,4*i,4*i+1,finish(i));
   printf("5 3 1 4 2 ");
   for (i=2; i<=N; i++) printf("%d %d %d %d ",4*i,4*i-2,4*i+1,4*i-1);
   for (i=N; i>=2; i--) printf("%d ",finish(i));
   printf("5\n");
   return 0;
}