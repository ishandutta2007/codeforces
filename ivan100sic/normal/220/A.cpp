#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[100005],B[100005],N,i,j,k,d;

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++){
      scanf("%d",A+i);
      B[i] = A[i];
   }
   sort(A+1,A+N+1);
   for (i=1; i<=N; i++) if (A[i]!=B[i]) d++;
   if (d==0 || d==2) printf("YES\n"); else printf("NO\n");
   return 0;
}