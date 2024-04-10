#include <stdio.h>

inline int max(int a,int b) { return a>b?a:b; }

int main(void)
{
   int qn,m,rd,si;
   scanf("%d %d",&qn,&m);
   rd=2*(m-1);
   si=m-1;
   while(qn--) {
      int s,f,t,ts,tf,j1,j2;
      scanf("%d %d %d",&s,&f,&t);
      if(s==f) {
         printf("%d\n",t);
         continue;
      }
      s--;
      f--;
      j1=rd-2*s;
      j2=2*s;
      ts=t/rd*rd+s;
      while(1) {
         if(ts<t) ts+=j1;
         else break;
         if(ts<t) ts+=j2;
         else break;
      }
      t=ts;
      j1=rd-2*f;
      j2=2*f;
      tf=t/rd*rd+f;
      while(1) {
         if(tf<t) tf+=j1;
         else break;
         if(tf<t) tf+=j2;
         else break;
      }
      printf("%d\n",tf);
   }
   return 0;
}