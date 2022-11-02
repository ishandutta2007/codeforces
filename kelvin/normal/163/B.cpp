#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 100050

const int epow=14;
long double eps=1.0;
const int iter=80;

class Lemming {
   public:
      int w,v,id;
      const bool operator<(const Lemming &b) const {
         return w<b.w||w==b.w&&v<b.v;
      }
};

int n,k,h;
Lemming s[MAXN];
bool selected[MAXN];

inline bool valid(long double t) {
   int c=1;
   for(int i=0;i<n;i++) {
      if(c<=k&&(long long)c<=t*s[i].v) {
         selected[i]=1;
         c++;
      } else selected[i]=0;
   }
   return c>k;
}

inline void solve() {
   long double l=0.0,r=(long double)k,m;
   for(int t=0;t<iter;t++) {
      m=(l+r)/2;
      if(valid(m)) r=m;
      else l=m;
   }
   valid(r);
   //std::cout << r << std::endl;
   for(int i=0;i<n;i++)
      if(selected[i]) printf("%d ",s[i].id);
   puts("");
}

int main(void)
{
   for(int i=0;i<epow;i++)
      eps/=10;
   scanf("%d %d %d",&n,&k,&h);
   for(int i=0;i<n;i++) {
      scanf("%d",&s[i].w);
      s[i].id=i+1;
   }
   for(int i=0;i<n;i++)
      scanf("%d",&s[i].v);
   std::sort(s,s+n);
   solve();
   return 0;
}