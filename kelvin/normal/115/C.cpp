#include <stdio.h>
#define MAXL 500050

const int mod = 1000003;

int rn,cn;
char *g[MAXL];

inline bool rtype(char x) {
   if(x=='1'||x=='2') return 0;
   else return 1;
}
inline bool ctype(char x) {
   if(x=='1'||x=='4') return 0;
   else return 1;
}

inline int power(int p) {
   int m=2,x=1;
   while(p) {
      if(p&1) x=(long long)x*m%mod;
      p>>=1;
      m=(long long)m*m%mod;
   }
   return x;
}

inline int solve() {
   int ro=0,co=0;
   for(int i=0;i<rn;i++) {
      bool flag=0,x;
      for(int j=0;j<cn;j++) {
         if(g[i][j]=='.') continue;
         int xx=(j&1)^rtype(g[i][j]);
         if(flag) {
            if(x!=xx) return 0;
         } else {
            flag=1;
            x=xx;
         }
      }
      if(flag) ro++;
   }
   for(int j=0;j<cn;j++) {
      bool flag=0,x;
      for(int i=0;i<rn;i++) {
         if(g[i][j]=='.') continue;
         int xx=(i&1)^ctype(g[i][j]);
         if(flag) {
            if(x!=xx) return 0;
         } else {
            flag=1;
            x=xx;
         }
      }
      if(flag) co++;
   }
   return (long long)power(rn-ro)*power(cn-co)%mod;
}

int main(void)
{
   scanf("%d %d",&rn,&cn);
   for(int i=0;i<rn;i++)
      g[i]=new char[cn+1];
   for(int i=0;i<rn;i++)
      scanf("%s",g[i]);
   printf("%d\n",solve());
   for(int i=0;i<rn;i++)
      delete [] g[i];
   return 0;
}