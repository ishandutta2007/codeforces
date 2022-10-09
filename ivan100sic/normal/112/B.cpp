#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

long A[200][200],B[200][200],N,i,j,k,x,y;
long long Rez;
char S[110000],C;

int main(){
   scanf("%ld%ld%ld",&N,&x,&y);
   A[x][y]=1;
   A[x-1][y]=1;
   A[x][y-1]=1;
   A[x+1][y]=1;
   A[x][y+1]=1;
   for (i=1; i<=N; i++){
      for (j=1; j<=N; j++){
         B[i][j] = A[N-i+1][N-j+1];
      }
   }
   bool moze=true;
   for (i=1; i<=N; i++){
      for (j=1; j<=N; j++){
         if (A[i][j]*B[i][j]==1) moze=false;
      }
   }
   if (moze) printf("YES\n"); else printf("NO\n");
   return 0;
}