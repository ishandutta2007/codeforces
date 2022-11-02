#include <stdio.h>

int a,b,n;

inline int gcd(int a,int b) {
   int t;
   while(b) {
      //printf("<%d %d>\n",a,b);
      t=b;
      b=a%b;
      a=t;
   }
   return a;
}

inline bool solve() {
   int t;
   while(1) {
      //printf("<%d %d %d>\n",n,a,b);
      if(!n) return 1;
      t=gcd(n,a);
      n-=t;
      if(!n) return 0;
      t=gcd(n,b);
      n-=t;
   }
}

int main(void)
{
   scanf("%d %d %d",&a,&b,&n);
   puts(solve()?"1":"0");
}