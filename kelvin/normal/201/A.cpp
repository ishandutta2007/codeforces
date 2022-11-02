#include <cstdio>
#include <algorithm>

using namespace std;

inline int sqr(int x) { return x*x; }
inline int sharp(int n) {
   if(n&1) return sqr(n/2)+sqr((n+1)/2);
   else return 4*((sqr(n/2-1)+1)/2);
}
inline bool ok(int n,int x){
   if(sharp(n)<x) return 0;
   if(n&1) {
      return 1;
   } else {
      if((x&3)!=0) return 0;
      return 1;
   }
}

inline int solve(int x) {
   if(x==1) return 1;
   if(x==2) return 3;
   if(x==3) return 5;
   if(x==4) return 3;
   if(x==5) return 3;
   for(int n=4;;n++)
      if(ok(n,x)) return n;
}

int main(void)
{
   int x;
   scanf("%d",&x);
   printf("%d\n",solve(x));
   return 0;
}