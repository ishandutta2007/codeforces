#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long x1,x2,a,b,d,t,drange,dest;

int main(){
   scanf("%I64d%I64d%I64d%I64d",&x1,&x2,&a,&b);
   d=x2-x1;
   if (d<0){
      a=-a;
      b=-b;
      d=-d;
      t=a;
      a=b;
      b=t;
   }
   if (a<=0){ //in this situation, first can either win or force a draw
      if (d<=b){
         if (x2-x1 < 0) t=-d; else t=d;
         printf("FIRST\n%I64d\n",x1+t);
      } else printf("DRAW\n");
   } else {
      drange = a+b;
      if (a>d) printf("DRAW\n"); else {
         t = d%drange;
         // t=0 loss
         // t<a draw
         // a<=t<=b win (play t)
         // else draw
         if (t==0) printf("SECOND\n"); else
         if (t<a || t>b) printf("DRAW\n"); else {
            if (x2-x1 < 0) dest = x1 - t; else dest = x1 + t;
            printf("FIRST\n%I64d\n",dest);
         }
      }
   }
   return 0;
}