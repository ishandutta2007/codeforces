#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[15],Nov[15],Naj[15];
int N,M,i,j,k,l,x,y;
bool ok;

int main(){
   scanf("%s",S);
   N = strlen(S);
   for (x=1; x<(1<<N); x++){
      l=0;
      memset(Nov,0,sizeof(Nov));
      for (i=0; i<N; i++) if (x&(1<<i)){
         Nov[l] = S[i];
         l++;
      }
      ok = true;
     // printf("%d %s\n",l,Nov);
      for (i=0; i<l; i++) if (Nov[i]!=Nov[l-i-1]){
         ok=false;
         //printf("%d %d %c %c\n",i,l-i,Nov[i],Nov[l-i]);
      }
      //printf("%d %s\n",l,i,Nov);
      if (ok){
         j=0;
         while (Nov[j]==Naj[j]) j++;
         if (Nov[j]>Naj[j]) memcpy(Naj,Nov,15);
      }
   }
   printf("%s\n",Naj);
   return 0;
}