#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a,b,c,i,j,k;

int main(){
   scanf("%d%d%d",&a,&b,&c);
   for (i=1; i<=7000000; i++){
      if ((i+c)*b >= a*c){
         printf("%d\n",i);
         return 0;
      }
   }
}