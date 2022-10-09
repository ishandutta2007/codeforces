#include <cstdio>
#include <cstring>
using namespace std;

char S[105];
int N,i,j,k,l;

int main(){
   scanf("%s",S+1);
   l=103;
   while (S[l]==0) l--;
   bool caps;
   caps = true;
   for (i=2; i<=l; i++) if (S[i]>='a') caps=false;
   if (caps){
      for (i=1; i<=l; i++) if (S[i]<95) S[i]+=32; else S[i]-=32;
   }
   printf("%s",S+1);
   return 0;
}