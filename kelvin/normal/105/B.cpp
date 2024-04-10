#include <stdio.h>
#define MAXN 10
#define MAXK 10

const int tp[10]={1,2,4,8,16,32,64,128,256,512};

int n,k,sa;
int str[MAXN],prb[MAXN];
double opt;

inline int bitcnt(int x) {
   int c=0;
   while(x) {
      if(x&1) c++;
      x>>=1;
   }
   return c;
}

inline void sub() {
   int i,b,bit,bad;
   double pr=0.0,pt;
   bit=1<<n;
   for(b=0;b<bit;b++) {
      pt=1.0;
      bad=0;
      for(i=0;i<n;i++) {
         if(b&tp[i]) pt*=(double)prb[i]/100;
         else {
            pt*=(double)(100-prb[i])/100;
            bad+=str[i];
         }
      }
      if(bitcnt(b)*2>n) {
         pr+=pt;
      } else {
         pr+=pt*sa/(sa+bad);
      }
   }
   if(pr>opt) opt=pr;
}

void dfs(int x,int rem) {
   int i;
   if(x==n) {
      sub();
      return;
   }
   for(i=0;i<=rem&&prb[x]+i*10<=100;i++) {
      prb[x]+=i*10;
      dfs(x+1,rem-i);
      prb[x]-=i*10;
   }
}

inline double solve() {
   opt=0.0;
   dfs(0,k);
   return opt;
}

int main(void)
{
   int i;
   scanf("%d %d %d",&n,&k,&sa);
   for(i=0;i<n;i++)
      scanf("%d %d",str+i,prb+i);
   printf("%.10lf\n",solve());
   return 0;
}