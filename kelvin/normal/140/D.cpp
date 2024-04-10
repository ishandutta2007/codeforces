#include <stdio.h>
#include <algorithm>
#define MAXN 105

int n,t[MAXN],s[MAXN];

inline void solve() {
   int b=0,a=0,was,pen;
   std::sort(t,t+n);
   s[0]=0;
   for(int i=0;i<n;i++) {
      s[i+1]=s[i]+t[i];
      if(s[i+1]<=350) b=i+1;
      if(s[i+1]<=710) a=i+1;
   }
   was=s[b];
   pen=0;
   for(int i=b;i<a;i++)
      pen+=s[i+1]-350;
   printf("%d %d\n",a,pen);
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",t+i);
   solve();
   return 0;
}