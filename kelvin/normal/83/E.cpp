#include <stdio.h>
#include <string.h>
#define MAXN 200050
#define MAXL 20

const int inf = 1000000000;

int tp[MAXL+1];

int n,len;
int s[MAXN];
int *dp[MAXL+1],dparr[1<<MAXL+1];

inline void relax(int &x,int val) { if(val<x) x=val; }

inline int concatenate(int a,int b) {
   int d,aa,bb;
   for(d=len;;d--) {
      aa=a&tp[d]-1;
      bb=b>>len-d;
      if(aa==bb) return len-d;
   }
}

inline int solve() {
   int i,d,b,cc,add,opt;
   if(n<=1) return len;
   for(d=0;d<=len;d++)
      for(b=0;b<tp[d];b++)
         dp[d][b]=inf;
   dp[0][0]=0;
   add=len;
   for(i=1;i<n;i++) {
      cc=concatenate(s[i-1],s[i]);
      opt=inf;
      for(d=0;d<=len;d++)
         relax(opt,dp[d][s[i]>>len-d]+add+len-d);
      // append to prev
      add+=cc;
      // append to before
      for(d=0;d<=len;d++)
         relax(dp[d][s[i-1]&tp[d]-1],opt-add);
   }
   return dp[0][0]+add;
}

int main(void)
{
   int i,j,b;
   char str[MAXL+1];
   for(i=0;i<=MAXL;i++)
      tp[i]=1<<i;
   for(i=0;i<=MAXL;i++)
      dp[i]=dparr+tp[i]-1;
   while(scanf("%d",&n)==1) {
      for(i=0;i<n;i++) {
         scanf("%s",str);
         if(!i) len=strlen(str);
         b=0;
         for(j=0;j<len;j++)
            b=b*2+str[j]-'0';
         s[i]=b;
      }
      printf("%d\n",solve());
   }
   return 0;
}