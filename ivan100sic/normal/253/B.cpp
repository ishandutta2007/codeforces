#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[100005],N,i,j,k,l,r;

int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   scanf("%d",&N);
   for (i=1; i<=N; i++) scanf("%d",A+i);
   sort(A+1,A+N+1);
   r=1;
   for (l=1; l<=N; l++){
      while (2*A[l] >= A[r+1] && r<N) r++;
      //printf("%d %d\n",l,r);
      j = max(j,r-l+1);
   }
   printf("%d\n",N-j);
   return 0;
}