#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 55

using namespace std;

int n,sum,len;
int s[MAXN];
long double cm[MAXN][MAXN];
long long dp[MAXN][MAXN];

long double sub() {
   long double e=0.0;
   for(int i=0;i<=n;i++)
      for(int j=0;j<=len;j++)
         dp[i][j]=0;
   dp[0][0]=1;
   for(int x=0;x<n-1;x++)
      for(int i=x;i>=0;i--)
         for(int j=0;j<=len;j++)
            if(j+s[x]<=len) dp[i+1][j+s[x]]+=dp[i][j];
   for(int i=0;i<=n-1;i++) {
      for(int j=max(len-s[n-1]+1,0);j<=len;j++) {
         e+=dp[i][j]*i/cm[n-1][i];
      }
   }
   return e;
}

double solve() {
   if(sum<=len) return n;
   for(int i=0;i<MAXN;i++) {
      cm[i][0]=cm[i][i]=1.0;
      for(int j=1;j<i;j++)
         cm[i][j]=cm[i-1][j]+cm[i-1][j-1];
   }
   long double e=0.0;
   for(int i=0;i<n;i++) {
      swap(s[n-1],s[n-i-1]);
      e+=sub();
   }
   return e/n;
}

int main(void)
{
   scanf("%d",&n);
   sum=0;
   for(int i=0;i<n;i++) {
      scanf("%d",s+i);
      sum+=s[i];
   }
   scanf("%d",&len);
   sort(s,s+n);
   printf("%.8lf\n",solve());
   return 0;
}