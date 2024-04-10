#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long ax,bx,cx,dx,muls,adds,opt;
char S1[5], S2[5], S3[5];

void r1(long long a){
   if (a<opt) opt=a;
}

void r2(long long a,long long b){
   if (S3[0]=='*'){
      r1(a*b);
   } else {
      r1(a+b);
   }
}

void r3(long long a,long long b,long long c){
   if (S2[0]=='*'){
      r2(a*b,c);
      r2(a*c,b);
      r2(b*c,a);
   } else {
      r2(a+b,c);
      r2(a+c,b);
      r2(b+c,a);
   }
}

void r4(long long a,long long b,long long c,long long d){
   if (S1[0]=='*'){
      r3(a*b,c,d);
      r3(a*c,b,d);
      r3(a*d,b,c);
      r3(b*c,a,d);
      r3(b*d,a,c);
      r3(c*d,a,b);
      muls++;
   } else {
      r3(a+b,c,d);
      r3(a+c,b,d);
      r3(a+d,b,c);
      r3(b+c,a,d);
      r3(b+d,a,c);
      r3(c+d,a,b);
   }
}
int main(){
   scanf("%I64d%I64d%I64d%I64d%s%s%s",&ax,&bx,&cx,&dx,S1,S2,S3);
   opt = 1000000000000000ll;
   r4(ax,bx,cx,dx);
   printf("%I64d\n",opt);
   return 0;
}