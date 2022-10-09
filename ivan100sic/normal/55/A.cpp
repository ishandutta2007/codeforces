#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,K,i,j,k;
bool X[1005];

int main(){
   scanf("%d",&N);
   //0..N-1
   for (i=0; i<=N; i++){
      j+=i;
      X[j%N]=true;
   }
   for (i=0; i<N; i++) if (X[i]) k++;
   if (k==N) printf("YES\n"); else printf("NO\n");
   return 0;
}