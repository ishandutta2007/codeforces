#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXL 20

using namespace std;

long long all[MAXL];

long long l,r;
long long dp[MAXL][2];
char dig[MAXL];

long long below(long long ub) {
   if(ub<10) return ub;
   all[0]=0;
   all[1]=9;
   long long tmp=9;
   for(int i=2;i<MAXL;i++) {
      all[i]=all[i-1]+tmp;
      tmp*=10;
   }
   sprintf(dig,"%I64d",ub);
   int len=strlen(dig);
   memset(dp,0,sizeof(dp));
   dp[0][0]=0;
   dp[0][1]=1; // tight
   for(int i=0;i<len;i++) {
      int x=dig[i]-'0';
      for(int y=0;y<10;y++) {
         if(i==0&&y==0) continue;
         dp[i+1][0]+=dp[i][0];
         if(y==x) dp[i+1][1]+=dp[i][1];
         if(y<x) dp[i+1][0]+=dp[i][1];
      }
   }
   return dp[len-1][0]+dp[len-1][1]*(dig[0]<=dig[len-1]?1:0)+all[len-1];
}

int main(void)
{
   cin >> l >> r;
   long long sol=below(r)-below(l-1);
   cout << sol << endl;
   return 0;
}