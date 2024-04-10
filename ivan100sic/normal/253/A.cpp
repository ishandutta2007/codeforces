#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,i,j,k;

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   scanf("%d%d",&N,&M);
   if (N==M){
      for (i=1; i<=N; i++) printf("BG");
   } else
   if (N<M){
      for (i=1; i<=N; i++) printf("GB");
      for (i=1; i<=M-N; i++) printf("G");
   } else {
      for (i=1; i<=M; i++) printf("BG");
      for (i=1; i<=N-M; i++) printf("B");
   }
   puts("");
   return 0;
}