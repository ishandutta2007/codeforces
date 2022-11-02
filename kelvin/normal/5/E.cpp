#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 1005000

using namespace std;

class Unit {
   public:
      int x,h,lb;
      Unit() {}
      Unit(int xi,int hi,int li):x(xi),h(hi),lb(li) { }
};

int n;
int ht[MAXN*2];

int ql,qr;
Unit que[MAXN*2];

inline int max(int a,int b) { return a>b?a:b; }

inline void flip() {
   for(int i=0;i<2*n-i-1;i++)
      swap(ht[i],ht[2*n-i-1]);
}

inline long long count() {
   long long sol=0;
   ql=qr=0;
   for(int i=0;i<2*n;i++) {
      while(ql<qr&&que[ql].x<=i-n) ql++;
      while(ql<qr&&que[qr-1].h<ht[i]) {
         qr--;
         if(i>=n) sol++;
      }
      if(ql<qr&&que[qr-1].h==ht[i]) {
         int lb=max(que[qr-1].lb,ql);
         if(i>=n) sol+=qr-lb;
         if(i>=n&&lb>ql) sol++;
         que[qr++]=Unit(i,ht[i],lb);
      } else {
         if(i>=n&&ql<qr) sol++;
         que[qr]=Unit(i,ht[i],qr);
         qr++;
      }
   }
   return sol;
}

inline long long sub() {
   int lar,sec,c=0;
   lar=sec=-1;
   for(int i=0;i<n;i++) {
      if(ht[i]>=lar) {
         sec=lar;
         lar=ht[i];
      } else if(ht[i]>=sec) {
         sec=ht[i];
      }
   }
   if(lar==sec) {
      for(int i=0;i<n;i++)
         if(ht[i]==lar) c++;
      return (long long)c*(c-1)/2;
   } else {
      for(int i=0;i<n;i++)
         if(ht[i]==sec) c++;
      return c;
   }
}

inline long long solve() {
   long long sol=0;
   sol=count();
   sol-=sub();
   return sol;
}

int main(void)
{
   while(scanf("%d",&n)==1) {
      for(int i=0;i<n;i++) {
         scanf("%d",ht+i);
         ht[n+i]=ht[i];
      }
      cout << solve() << endl;
   }
   return 0;
}