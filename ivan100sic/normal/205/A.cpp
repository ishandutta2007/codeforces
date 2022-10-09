#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,A[100005],m,mc,mp,i;

int main(){
   scanf("%d",&N);
   m = 1112223334;
   for (i=1; i<=N; i++) scanf("%d",A+i);
   for (i=1; i<=N; i++){
      if (A[i]<m){
         m=A[i];
         mp=i;
         mc=1;
      } else if (A[i]==m) mc++;
   }
   if (mc==1) printf("%d\n",mp); else printf("Still Rozdil\n");
   return 0;
}