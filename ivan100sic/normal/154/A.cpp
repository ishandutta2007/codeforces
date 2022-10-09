#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[100005],Other[128];
char R[16],state;
int A[100005],B[100005],N,i,j,k,P,c1,c2;
bool bidden;

int main(){
   scanf("%s%d",S+1,&P);
   for (i=1; i<=P; i++){
      scanf("%s",R);
      Other[R[0]] = R[1];
      Other[R[1]] = R[0];
   }
   N = strlen(S+1);
   S[N+1] = '.';
   for (i=1; i<=N+1; i++){
      //printf("%d %d\n",c1,c2);
      if (Other[S[i]]==0){
         state=0;
         k+=min(c1,c2);
         c1=0;
         c2=0;
      } else
      if (Other[S[i]]!=state && S[i]!=state){
         state=S[i];
         k+=min(c1,c2);
         c1=1;
         c2=0;
      } else {
         if (state==0) state=S[i];
         if (S[i]==Other[state]) c2++; else
         if (S[i]==state) c1++;
      }
   }
   printf("%d\n",k);
   return 0;
}