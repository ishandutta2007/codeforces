#include <stdio.h>
#define MAXN 100020

int nn;
int nim[MAXN];
int nimsum[MAXN];
int minpile[MAXN];

int arr[MAXN]={0},visid=0;

inline int getseg(int l,int r) {
   return nimsum[r]^nimsum[l-1];
}
inline void gen() {
   int n,k,a,i,x;
   nim[0]=nimsum[0]=0;
   nim[1]=nimsum[1]=0;
   minpile[1]=-1;
   for(n=2;n<MAXN;n++) {
      ++visid;
      minpile[n]=-1;
      for(k=2;k*k<2*n;k++) {
         if((2*n)%k) continue;
         int c=2*n/k+1-k;
         if(c<=0||(c&1)) continue;
         a=c>>1;
         x=getseg(a,a+k-1);
         arr[x]=visid;
         if(!x&&minpile[n]==-1) minpile[n]=k;
      }
      for(i=0;arr[i]==visid;i++);
      nim[n]=i;
      nimsum[n]=nimsum[n-1]^nim[n];
   }
}

int main(void)
{
   int i;
   gen();
   while(scanf("%d",&nn)==1)
      printf("%d\n",minpile[nn]);
   return 0;
}