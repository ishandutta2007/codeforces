#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int D[28][28],N,i,j,k,l,m,x,y,a,strle;
char S[15];

int maks(int a,int b){
   if (a>b) return a; else return b;
};

int main(){
   scanf("%d",&N);
   for (i=1; i<=N; i++){
      scanf("%s",S);
      x = S[0]-'a';
      strle = strlen(S);
      //printf("%d\n",strle);
      y = S[strle-1]-'a';
      for (a=0; a<26; a++){
         if (D[a][x]!=0){
            D[a][y] = maks(D[a][y] , D[a][x] + strle);
         }
      }
      D[x][y] = maks(D[x][y], strle);
   }
   for (a=0; a<26; a++){
      m = max(m,D[a][a]);
      //printf("%d %d\n",m,a);
   }
   printf("%d\n",m);
   return 0;
}