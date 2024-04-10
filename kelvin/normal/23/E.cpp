#include <stdio.h>
#define MAXN 705
#define MAXL 30

const int bigmod=10000;
const char prtstr[]="%04d";
// 2^350 = 1000^35 = 10^105 = 10000^27

class Bignum {
   public:
      int len;
      int s[MAXL];
      Bignum() { len=0; }
      Bignum(int x) {
         for(len=0;x;len++) {
            s[len]=x%bigmod;
            x/=bigmod;
         }
      }
      void print() const {
         if(len) {
            printf("%d",s[len-1]);
            for(int i=len-2;i>=0;i--)
               printf(prtstr,s[i]);
            puts("");
         } else puts("0");
      }
      Bignum& operator+=(const Bignum &b) {
         int i,carry=0;
         for(i=0;i<len||i<b.len||carry;i++) {
            s[i]=(i<len?s[i]:0)+(i<b.len?b.s[i]:0)+carry;
            if(s[i]>=bigmod) {
               s[i]-=bigmod;
               carry=1;
            } else carry=0;
         }
         len=i;
         return *this;
      }
      Bignum& operator*=(const int b) {
         int i,carry=0;
         for(i=0;i<len||carry;i++) {
            s[i]=(i<len?s[i]:0)*b+carry;
            carry=s[i]/bigmod;
            s[i]%=bigmod;
         }
         len=i;
         return *this;
      }
      const Bignum operator*(const int b) const {
         return (Bignum)*this*=b;
      }
      const Bignum operator*(const Bignum b) const {
         Bignum c(0);
         for(int i=b.len-1;i>=0;i--) {
            c.leftshift();
            c+=(*this)*b.s[i];
         }
         return c;
      }
      void leftshift() {
         if(!len) return;
         for(int i=len-1;i>=0;i--)
            s[i+1]=s[i];
         s[0]=0;
         len++;
      }
      const bool operator<(const Bignum &b) const {
         if(len!=b.len) return len<b.len;
         for(int i=len-1;i>=0;i--)
            if(s[i]!=b.s[i]) return s[i]<b.s[i];
         return 0;
      }
};

int n;
int deg[MAXN]={0},adj[MAXN][MAXN];

int order[MAXN],oid=0;
int pred[MAXN],subsz[MAXN];
Bignum opt[MAXN][MAXN];
Bignum dp[MAXN][MAXN];

inline void relax(Bignum &x,const Bignum &val) { if(x<val) x=val; }

void dfs(int v,int p) {
   subsz[v]=1;
   for(int i=0;i<deg[v];i++) {
      int u=adj[v][i];
      if(u==p) {
         adj[v][i--]=adj[v][--deg[v]];
         continue;
      }
      dfs(u,v);
      subsz[v]+=subsz[u];
   }
   order[oid++]=v;
}

inline void process(int v) {
   int cursz=1;
   dp[0][1]=1;
   for(int i=0;i<deg[v];i++) {
      int u=adj[v][i];
      int nxtsz=cursz+subsz[u];
      for(int j=1;j<=nxtsz;j++)
         dp[i+1][j]=0;
      for(int j=1;j<=cursz;j++)
         for(int k=0;k<=subsz[u];k++)
            relax(dp[i+1][j+k],dp[i][j]*opt[u][k]);
      cursz=nxtsz;
   }
   opt[v][0]=0;
   for(int i=1;i<=subsz[v];i++) {
      opt[v][i]=dp[deg[v]][i];
      relax(opt[v][0],opt[v][i]*i);
   }
}


inline Bignum solve() {
   dfs(1,0);
   for(int i=0;i<n;i++)
      process(order[i]);
   return opt[1][0];
}

int main(void)
{
   int i;
   scanf("%d",&n);
   for(int i=0;i<n-1;i++) {
      int v,u;
      scanf("%d %d",&v,&u);
      adj[v][deg[v]++]=u;
      adj[u][deg[u]++]=v;
   }
   solve().print();
   return 0;
}