#include <stdio.h>
#define MAXN 1000050
#define MAXL 5020
#define MAXLSUM 10000050

int cm[MAXL];
int arr[MAXL];
int gar[MAXL+1][MAXL+1];

int n,m,mod;
int len[MAXN],maxl[MAXN];
int *dp[MAXN];

//int gar[MAXL],below[MAXL];

inline int min(int a,int b) { return a<b?a:b; }
inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
inline int minus(int a,int b) { return a-b<0?a-b+mod:a-b; }

inline int gcd(int a,int b) {
   while(b) {
      int t=b;
      b=a%b;
      a=t;
   }
   return a;
}

inline void gen() {
   cm[0]=1;
   for(int i=1;i<MAXL&&i<=m;i++) {
      // calculate C(m,i);
      arr[i]=m-i+1;
      int d=i;
      for(int j=1;j<=i&&d>1;j++) {
         int g=gcd(arr[j],d);
         arr[j]/=g;
         d/=g;
      }
      cm[i]=1;
      for(int j=1;j<=i;j++)
         cm[i]=(long long)cm[i]*arr[j]%mod;
   }
   //for(int i=0;i<=m;i++)
      //printf("%d: %d\n",i,cm[i]);
}

inline void gen2() {
   // gar[l][c]
   for(int l=1;l<MAXL;l++) {
      gar[l][1]=(l==1?1:0);
      gar[l][l+1]=0;
      for(int c=2;c<=l;c++) {
         gar[l][c]=add((long long)c*gar[l-1][c-1]%mod,(long long)(c-1)*gar[l-1][c]%mod);
      }
   }
   /*for(int i=1; i<=10; i++) {
      for(int c=1; c<=i; c++) {
         printf("%d %d: %d\n",i,c,gar[i][c]);
      }
   }*/
}

inline int power(int x,int p) {
   int m=x%mod,s=1;
   while(p) {
      if(p&1) s=(long long)s*m%mod;
      m=(long long)m*m%mod;
      p>>=1;
   }
   return s;
}

inline int calc(int l,int c) {
   return (long long)c*power(c-1,l-1)%mod;
}

inline int solve() {
   //printf("<%d %d>\n",m,len[0]);
   maxl[0]=min(m,len[0]);
   /*for(int c=1;c<=maxl[0];c++) {
      below[c]=calc(len[0],c);
      gar[c]=minus(below[c],below[c-1]);
      gar[c]=minus(calc(len[0],c),);
   }*/
   //printf("[%d]\n",maxl[0]);
   for(int c=1;c<=maxl[0];c++) {
      dp[0][c]=gar[len[0]][c];
      //printf("0 %d: %d, %d\n",c,maxl[0],dp[0][c]);
   }
   for(int i=1;i<n;i++) {
      int l=len[i];
      int ps=0;
      int pmc=maxl[i-1];
      maxl[i]=min(m,l);
      for(int c=1;c<=pmc;c++)
         ps=add(ps,(long long)dp[i-1][c]*cm[c]%mod);
      /*gar[0]=below[0]=0;
      for(int c=1;c<=maxl[i];c++) {
         below[c]=calc(l,c);
         gar[c]=minus(below[c],below[c-1]);
      }*/
      for(int c=1;c<=maxl[i];c++) {
         int way=gar[len[i]][c];
         int samec=(c<=pmc?dp[i-1][c]:0);
         dp[i][c]=(long long)minus(ps,samec)*way%mod;
         //printf("%d %d: %d\n",i,c,dp[i][c]);
      }
   }
   int sol=0;
   for(int c=1;c<=maxl[n-1];c++)
      sol=add(sol,(long long)dp[n-1][c]*cm[c]%mod);
   return sol;
}

int main(void)
{
   scanf("%d %d %d",&n,&m,&mod);
   gen();
   gen2();
   for(int i=0;i<n;i++) {
      scanf("%d",len+i);
      dp[i]=new int[len[i]+2];
   }
   printf("%d\n",solve());
   for(int i=0;i<n;i++)
      delete [] dp[i];
   return 0;
}