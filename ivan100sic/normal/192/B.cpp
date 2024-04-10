#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct tile{
   int x,t;
};

bool cmptiles(tile a,tile b){
   return a.t < b.t;
}

tile A[1005];
int N,i,j,k,l;
bool Des[1005];

int main(){
   scanf("%d",&N);
   Des[0] = true;
   Des[N+1] = true;
   for (i=1; i<=N; i++){
      scanf("%d",&A[i].t);
      A[i].x = i;
   }
   sort(A+1,A+N+1,cmptiles);
   for (i=1; i<=N; i++){
      k = A[i].x;
      Des[k] = true;
      if (Des[k-1] || Des[k+1]){
         printf("%d\n",A[i].t);
         return 0;
      }
   }
}