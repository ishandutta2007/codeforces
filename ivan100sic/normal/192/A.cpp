#include <cstdio>
#include <cstring>
using namespace std;

int n,i,j,k,l,a,b;
int Svi[1000000];

int main(){
   scanf("%d",&n);
   n*=2;
   for (i=1; i*i+i <= 2000000000; i++) Svi[i] = i*i+i;
   l = i-1;
   j=l;
   for (i=1; i<=l; i++){
      while (Svi[i]+Svi[j] > n) j--;
      if (j<i){
         printf("NO\n");
         return 0;
      }
      if (Svi[i]+Svi[j] == n){
         printf("YES\n");
         return 0;
      }
   }
}