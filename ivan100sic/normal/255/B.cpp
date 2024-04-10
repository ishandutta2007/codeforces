#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[1000005];
int N,x,y,k,i,j;

int main(){
   scanf("%s",S+1);
   N = strlen(S+1);
   for (i=1; i<=N; i++) if (S[i]=='x') x++; else y++;
   k = min(x,y);
   x-=k;
   y-=k;
   for (i=1; i<=x; i++) putchar('x');
   for (i=1; i<=y; i++) putchar('y');
   puts("");
   return 0;
}