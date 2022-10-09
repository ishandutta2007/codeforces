#include <cstdio>
#include <cstring>
#include <algorithm>
#define diff(x,c) (((x)+'A'-1==(c))?0:1)
using namespace std;

int D[500005][30],N,K,i,j,k,l,m,n,r;
char Att[500005][30],start;
char S[500005],chose,Sol[500005];

int main(){
   memset(D,63,sizeof(D));
   scanf("%d%d%s",&N,&K,S+1);
   for (i=1; i<=K; i++) D[0][i] = 0;
   for (i=1; i<=N; i++){
      for (j=1; j<=K; j++){
         for (k=1; k<=K; k++) if (j!=k){
            //printf("%d %d %d %d\n",i,j,k,D[i-1][k]);
            if (D[i-1][k] + diff(j,S[i]) <= D[i][j]){
               D[i][j] = D[i-1][k] + diff(j,S[i]);
               Att[i][j] = k;
            }
         }
      }
   }
   r=1000000;
   start=0;
   for (i=1; i<=K; i++){
      if (D[N][i] < D[N][start]){
         start=i;
         r = D[N][i];
      }
   }
   printf("%d\n",r);
   for (i=N; i; i--){
      Sol[i] = start+'A'-1;
      start = Att[i][start];
   }
   printf("%s\n",Sol+1);
   return 0;
}