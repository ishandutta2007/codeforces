#include <stdio.h>
#define MAXN 1050

inline int gcd(int a,int b) {
   while(b) {
      int t=b;
      b=a%b;
      a=t;
   }
   return a;
}

class Fraction {
   public:
      int c,d;
      void simp() {
         int g=gcd(c,d);
         c/=g; d/=g;
      }
      Fraction(int ci):c(ci),d(1) {}
      Fraction(int ci,int di):c(ci),d(di) {
         simp();
      }
      const bool operator<(const Fraction &b) const {
         return (long long)c*b.d<(long long)b.c*d;
      }
};

int n;
int s[MAXN];
Fraction a1(1,1),a2(2000000,1);

inline Fraction min(Fraction a,Fraction b) { return a<b?a:b; }
inline Fraction max(Fraction a,Fraction b) { return a<b?b:a; }

inline void solve() {
   for(int i=0;i<n;i++) {
      a1=max(a1,Fraction(s[i],i+1));
      a2=min(a2,Fraction(s[i]+1,i+1));
   }
   int x1=(long long)a1.c*(n+1)/a1.d;
   int x2=((long long)a2.c*(n+1)-1)/a2.d;
   if(x1==x2) {
      puts("unique");
      printf("%d\n",x1);
   } else {
      puts("not unique");
   }
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",s+i);
   solve();
   return 0;
}