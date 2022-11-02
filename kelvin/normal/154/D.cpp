#include <stdio.h>
#include <algorithm>

using namespace std;

int x1,x2,a,b,ds,t;
int xsg;

inline int sign(int x) { return x?(x>0?1:-1):0; }
inline int abs(int x) { return x<0?-x:x; }
inline int between(int l,int r,int x) { return l<=x&&x<=r; }

inline void solve() {
   if(between(x1+a,x1+b,x2)) {
      puts("FIRST");
      printf("%d\n",x2);
      return;
   }
   xsg=sign(x2-x1);
   x1*=xsg; x2*=xsg; a*=xsg; b*=xsg;
   if(a>b) swap(a,b);
   if(a<=0) {
      puts("DRAW");
      return;
   }
   t=a+b;
   ds=x2-x1;
   int m=ds%t;
   if(between(a,b,m)) {
      puts("FIRST");
      printf("%d\n",xsg*(x1+m));
      return;
   } else if (m==0) {
      puts("SECOND");
      return;
   } else {
      puts("DRAW");
      return;
   }
}

int main(void)
{
   while(scanf("%d %d %d %d",&x1,&x2,&a,&b)==4)
      solve();
   return 0;
}