#include <stdio.h>

inline int gcd(int a,int b) {
   while(b) {
      int t=b;
      b=a%b;
      a=t;
   }
   return a;
}

inline int lcm(int a,int b) {
   return a*b/gcd(a,b);
}

inline int lcm(int a,int b,int c) {
   return lcm(a,lcm(b,c));
}

inline int lcm(int a,int b,int c,int d) {
   return lcm(lcm(a,b),lcm(c,d));
}

int main(void)
{
   int n,a,b,c,d;
   while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&n)==5) {
      int s=n/a+n/b+n/c+n/d
            -(n/lcm(a,b)+n/lcm(a,c)+n/lcm(a,d)+n/lcm(b,c)+n/lcm(b,d)+n/lcm(c,d))
            +(n/lcm(a,b,c)+n/lcm(a,b,d)+n/lcm(a,c,d)+n/lcm(b,c,d))
            -n/lcm(a,b,c,d);
      printf("%d\n",s);
   }
   return 0;
}