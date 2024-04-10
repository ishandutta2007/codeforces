#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define MAXN 100050

using namespace std;

const int mod=1000000007;

const int maxl=11;
const int fac6=720;

int m;
int digit[maxl+1];
int dp[maxl+1][2][maxl+1];
int way[maxl+1];
int sel[maxl+2][maxl+1][7];

inline int modit(int x) {
   if(x<0) x+=mod;
   if(x>=mod) x-=mod;
   return x;
}

inline bool lucky(int x) {
   return x==4||x==7;
}

inline int inverse(int x,int p) {
   int q,tmp,a=x,b=p;
   int a0=1,a1=0,b0=0,b1=1;
   while(b) {
      q=a/b; tmp=b; b=a-b*q; a=tmp;
      tmp=b0; b0=a0-b0*q; a0=tmp;
      tmp=b1; b1=a1-b1*q; a1=tmp;
   }
   if(a0<0) a0+=p;
   return a0;
}
inline int p6(int x) {
   if(x<6) return 0;
   int ret=1;
   for(int i=0;i<6;i++)
      ret=(long long)ret*(x-i)%mod/**inverse(i+1,mod)%mod*/;
   return ret;
}
inline int cm(int x,int y) {
   if(x<y) return 0;
   int ret=1;
   for(int i=0;i<y;i++)
      ret=(long long)ret*(x-i)%mod*inverse(i+1,mod)%mod;
   return ret;
}

int solve() {
   for(int i=0,tmp=m;i<=maxl;i++) {
      digit[i]=tmp%10;
      tmp/=10;
      //printf("%d -- %d\n",i,digit[i]);
   }
   dp[maxl][1][0]=1;
   for(int i=maxl;i>0;i--) {
      int dg=digit[i-1];
      for(int c=0;c<=maxl;c++) {
         // loose 0
         for(int x=0;x<10;x++)
            if(dp[i][0][c]) dp[i-1][0][c+(lucky(x)?1:0)]=modit(dp[i-1][0][c+(lucky(x)?1:0)]+dp[i][0][c]);
         for(int x=0;x<dg;x++)
            if(dp[i][1][c]) dp[i-1][0][c+(lucky(x)?1:0)]=modit(dp[i-1][0][c+(lucky(x)?1:0)]+dp[i][1][c]);
         // tight 1
         dp[i-1][1][c+(lucky(dg)?1:0)]=modit(dp[i-1][1][c+(lucky(dg)?1:0)]+dp[i][1][c]);
      }
   }
   int sw=0;//,sol=0;
   for(int i=0;i<=maxl;i++) {
      way[i]=modit(dp[0][0][i]+dp[0][1][i]);
      if(i==0) way[i]=modit(way[i]-1);
      /*//printf("%d %d\n",i,way[i]);
      sol=(sol+(long long)way[i]*p6(sw))%mod;
      sw=modit(sw+way[i]);*/
   }
   sel[0][0][0]=1;
   for(int i=0;i<maxl;i++) {
      for(int j=0;j<maxl;j++) {
         for(int c=0;c<=6;c++) {
            for(int a=0;c+a<=6&&j+a*i<maxl&&a<=way[i];a++) {
               sel[i+1][j+i*a][c+a]=(sel[i+1][j+i*a][c+a]+(long long)sel[i][j][c]*cm(way[i],a))%mod;
            }
         }
      }
   }
   int sol=0;
   int sss=0;
   for(int i=0;i<maxl;i++) {
      sss=modit(sss+sel[maxl][i][6]);
      //printf("%d: %d*%d\n",i,sss,way[i+1]);
      sol=(sol+(long long)sss*way[i+1])%mod;
   }
   //printf("<%d>\n",sol);
   sol=sol*(long long)fac6%mod;
   return sol;
}

int main(void)
{
   scanf("%d",&m);
   printf("%d\n",solve());
   return 0;
}