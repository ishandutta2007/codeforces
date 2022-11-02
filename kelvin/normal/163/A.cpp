#include <stdio.h>
#include <string.h>
#define MAXL 5050

const int mod=1000000007;

int sl,tl;
char s[MAXL],t[MAXL];
int dp[MAXL][MAXL]={0};

inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }

int main(void)
{
   gets(s);
   gets(t);
   sl=strlen(s);
   tl=strlen(t);
   int sol=0;
   for(int i=0;i<sl;i++) {
      for(int j=0;j<tl;j++) {
         if(s[i]==t[j]) {
            dp[i][j]=add(dp[i][j],1);
            if(i&&j) dp[i][j]=add(dp[i][j],dp[i-1][j-1]);
         }
         if(j) dp[i][j]=add(dp[i][j],dp[i][j-1]);
      }
   }
   for(int i=0;i<sl;i++)
      sol=add(sol,dp[i][tl-1]);
   printf("%d\n",sol);
   return 0;
}