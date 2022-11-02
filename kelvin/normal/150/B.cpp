#include <stdio.h>
#include <stdlib.h>
#define MAXN 2050

const int mod=1000000007;

class DisjointSet {
   public:
      int sz;
      int r[MAXN];
      DisjointSet(int _sz):sz(_sz) {
         for(int i=0;i<sz;i++)
            r[i]=i;
      }
      int rep(int x) {
         if(r[x]!=x) r[x]=rep(r[x]);
         return r[x];
      }
      bool merge(int x,int y) {
         x=rep(x);
         y=rep(y);
         if(x==y) return 0;
         if(rand()&1) r[x]=y;
         else r[y]=x;
         return 1;
      }
};

int n,m,k;

inline int gcd(int a,int b) {
   while(b) {
      int t=b;
      b=a%b;
      a=t;
   }
   return a;
}

inline int power(int x,int p ){
   int m=x,s=1;
   while(p) {
      if(p&1) s=(long long)s*m%mod;
      m=(long long)m*m%mod;
      p>>=1;
   }
   return s;
}

inline int solve() {
   /*if(k>n||k==1) return power(m,n);
   if(k==n) return power(m,(n+1)/2);
   return m%mod;*/
   DisjointSet djs(n);
   int c=0;
   for(int i=0;i+k<=n;i++) {
      for(int j=0;j*2<k;j++)
         if(djs.merge(i+j,i+k-j-1)) c++;
   }
   return power(m,n-c);
}

int main(void)
{
   while(scanf("%d %d %d",&n,&m,&k)==3)
      printf("%d\n",solve());
   return 0;
}