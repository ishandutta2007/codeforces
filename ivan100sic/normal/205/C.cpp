#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long a,b,c,d,e,f;

bool prop(long long x){
   //printf("%I64d\n",x);
   int a,b;
   a = x%10;
   while (x>=10) x/=10;
   b = x;
   return a==b;
}

int main(){
   scanf("%I64d%I64d",&a,&b);
   if (b-a<=100){
      for (c=a; c<=b; c++) if (prop(c)) d++;
   } else {
      while (a%10!=0){
         d+=prop(a);
         a++;
      }
      while (b%10!=9){
         d+=prop(b);
         b--;
      }
      d+=(b-a+1)/10;
   }
   printf("%I64d\n",d);
   return 0;
}