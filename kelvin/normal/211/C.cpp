#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXL 105

using namespace std;

int n;
char s[MAXL];
long long dp[MAXL][2];

long long solve() {
   long long sol=0;
   for(int f=0;f<2;f++) {
      for(int i=0;i<=n;i++)
         dp[i][0]=dp[i][1]=0;
      dp[0][f]=1;
      for(int i=1;i<n;i++) {
         if(s[i]==0) {
            dp[i][0]+=dp[i-1][1];
            if(s[i-1]==0) dp[i][0]+=dp[i-1][0];
            if(s[i-1]==1) dp[i][1]+=dp[i-1][0];
         } else {
            dp[i][0]+=dp[i-1][1];
            if(s[i-1]==0) dp[i][0]+=dp[i-1][0];
            dp[i][1]+=dp[i-1][1];
         }
      }
      if(f==0) {
         sol+=dp[n-1][1];
         if(s[n-1]==0) sol+=dp[n-1][0];
      } else {
         if(s[0]==0&&s[n-1]==1) sol+=dp[n-1][0];
         if(s[0]==1) sol+=dp[n-1][1];
      }
   }
   return sol;
}

int main(void)
{
   scanf("%s",s);
   n=strlen(s);
   for(int i=0;i<n;i++)
      s[i]-='A';
   cout << solve() << endl;
   return 0;
}