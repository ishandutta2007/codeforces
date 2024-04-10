#include <stdio.h>
#define MAXN 10050

const int inf=100000000;

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

int s[MAXN];

int main(void)
{
   int n,m,t,i;
   int cst,per,most;
   while(scanf("%d %d %d",&n,&m,&t)==3) {
      for(i=0;i<n;i++)
         scanf("%d",s+i);
      if(n&1) {
         cst=(n+1)/2;
         per=m/cst;
         most=inf;
         for(i=0;i<n;i+=2)
            most=min(most,s[i]);
         if((long long)per*t<most) most=per*t;
         printf("%d\n",most);
      } else {
         printf("%d\n",0);
      }
   }
   return 0;
}