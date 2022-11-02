#include <stdio.h>
#define MAXN 100050

int n;
int s[MAXN];

inline bool check(int *s,int n) {
   if(n==1) return 1;
   if(!s[n-2]&&s[n-1]) return 0;
   for(int i=1;i<n-1;i++)
      if(s[i]*s[i]!=s[i-1]*s[i+1]) return 0;
   return 1;
}

inline int solve() {
   if(check(s,n)) return 0;
   if(check(s+1,n-1)) return 1;
   int t=s[1];
   s[1]=s[0];
   if(check(s+1,n-1)) return 1;
   s[1]=t;
   int c=s[1],d=s[0];
   bool flag=0;
   if(d==0) {
      if(c) return 2;
      for(int i=1;i<n;i++) {
         if(s[i]) {
            if(flag) return 2;
            flag=1;
         }
      }
      return 1;
   }
   int p=s[0];
   for(int i=1;i<n;i++) {
      if(p*c%d||s[i]!=p*c/d) {
         if(flag) return 2;
         flag=1;
         continue;
      }
      p=s[i];
   }
   return 1;
}

int main(void)
{
   while(scanf("%d",&n)==1) {
      for(int i=0;i<n;i++)
         scanf("%d",s+i);
      printf("%d\n",solve());
   }
   return 0;
}