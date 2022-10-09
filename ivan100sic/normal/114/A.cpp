#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long M,N,n0;
char S[100000];

int main(){
   long i=0,j,k;
   cin >> N >> M;
   n0=N;
   while (N<M) {
      N*=n0;
      i++;
   }
   if (N==M) printf("YES\n%ld\n",i); else printf("NO\n");
   return 0;
}