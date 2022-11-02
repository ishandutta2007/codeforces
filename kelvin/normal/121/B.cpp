#include <stdio.h>
#define MAXL 100050

int n,k;
char s[MAXL];

inline bool ff(int a,int b) {
   return a==4&&b==7;
}

inline void solve() {
   int i=0,pi=-1;
   while(k--) {
      if(i<0) i=0;
      for(;i<n-1;i++)
         if(ff(s[i],s[i+1])) break;
      if(i>=n-1) return;
      if(!(i&1)) s[i]=s[i+1]=4;
      else s[i]=s[i+1]=7;
      if(i<pi) k=k&1;
      pi=i;
      i--;
   }
}

int main(void)
{
   scanf("%d %d",&n,&k);
   scanf("%s",s);
   for(int i=0;i<n;i++)
      s[i]-='0';
   solve();
   for(int i=0;i<n;i++)
      printf("%d",s[i]);puts("");
   return 0;
}