#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,K,i,j,k,dt;

struct pie{
   int x,y;
};

pie A[105];

int main(){
   scanf("%d%d%d",&N,&M,&K);
   for (i=1; i<=K; i++) scanf("%d%d",&A[i].x,&A[i].y);
   for (i=1; i<=K; i++){
      if (A[i].y>=M-4 || A[i].y<=5 || A[i].x<=5 || A[i].x>=N-4
          //(A[i].x==3 && A[i].y==3) ||
          //(A[i].x==N-2 && A[i].y==M-2) ||
          //(A[i].x==3 && A[i].y==M-2) ||
          //(A[i].x==N-2 && A[i].y==3)
          //A[i].y == A[i].x ||
         // A[i].y == N+1 - A[i].x ||
          //M+1 - A[i].y == N+1 - A[i].x ||
          //M+1 - A[i].y == A[i].x


          ){
         printf("YES\n");
         return 0;
      }
   }
   printf("NO\n");
   return 0;
}