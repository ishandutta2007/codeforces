#include <stdio.h>
#define MAXL 1050

const int mod=1000000007;

int cm[MAXL][MAXL]={0};
int rn,cn,k;

inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
inline void pre() {
   for(int i=0;i<MAXL;i++) {
      cm[i][i]=cm[i][0]=1;
      for(int j=1;j<i;j++)
         cm[i][j]=add(cm[i-1][j],cm[i-1][j-1]);
   }
}

inline int comb(int a,int b) {
   if(b>a||b<0) return 0;
   return cm[a][b];
}

inline int solve() {
   return (int)((long long)comb(rn-1,2*k)*comb(cn-1,2*k)%mod);
}

int main(void)
{
   pre();
   while(scanf("%d %d %d",&rn,&cn,&k)==3) {
      printf("%d\n",solve());
   }
   return 0;
}