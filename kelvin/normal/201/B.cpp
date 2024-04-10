#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 1050

using namespace std;

int rn,cn;
int co[MAXN][MAXN];

inline long long sqr(long long x) {
   return x*x;
}
inline long long dist2(int r,int c,int i,int j) {
   // r*4,c*4; i*4-2,j*4-2
   return sqr(r*4-(i*4+2))+sqr(c*4-(j*4+2));
}

inline long long calc(int r,int c) {
   long long s=0;
   for(int i=0;i<rn;i++)
      for(int j=0;j<cn;j++)
         s+=dist2(r,c,i,j)*co[i][j];
   return s;
}

inline int getrow() {
   int l=-1,r=rn+1;
   while(l<r-2) {
      int m1=(l*2+r)/3;
      int m2=(l+r*2)/3;
      long long val1=calc(m1,0);
      long long val2=calc(m2,0);
      if(val1<=val2) r=m2;
      else l=m1;
   }
   return (l+r)/2;
}
inline int getcol() {
   int l=-1,r=cn+1;
   while(l<r-2) {
      int m1=(l*2+r)/3;
      int m2=(l+r*2)/3;
      long long val1=calc(0,m1);
      long long val2=calc(0,m2);
      if(val1<=val2) r=m2;
      else l=m1;
   }
   return (l+r)/2;
}

void solve() {
   int r=getrow();
   int c=getcol();
   long long val=calc(r,c);
   cout << val << endl;
   cout << r << " " << c << endl;
}

int main(void)
{
   scanf("%d %d",&rn,&cn);
   for(int i=0;i<rn;i++)
      for(int j=0;j<cn;j++)
         scanf("%d",co[i]+j);
   solve();
   return 0;
}