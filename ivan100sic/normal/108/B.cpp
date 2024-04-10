#include <cstdio>
#include <algorithm>
using namespace std;

long A[110000],N,i;
bool moze=true;

bool staje(long a,long b){
   if (a==1) return true;
   if (a==b) return true;
   if (a*2>b) return false;
   return true;
}

int main(){
   scanf("%ld",&N);
   for (i=0; i<N; i++) scanf("%ld",&A[i]);
   sort(A,A+N);
   for (i=1; i<N; i++) if (!staje(A[i-1],A[i])) moze=false;
   if (moze) printf("NO\n"); else printf("YES\n");
   return 0;
}