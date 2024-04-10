#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[100005];
int N,i,j,k,l;

int main(){
   scanf("%s",S+1);
   N = strlen(S+1);
   for (i=1; i<=N; i++) if (S[i]=='0') break;
   if (i<=N){
      for (j=1; j<=N; j++) if (i!=j) putchar(S[j]);
      puts("");
   } else {
      for (j=1; j<N; j++) putchar('1');
      puts("");
   }
   return 0;
}