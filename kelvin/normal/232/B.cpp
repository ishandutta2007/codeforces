#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 105
#define MAXK (MAXN*MAXN)

using namespace std;

const int mod=1000000007;

int rn,k;
long long cn;
int coef[MAXN];

int cm[MAXN][MAXN];
int dp[MAXN][MAXK];
int basepow;
int cmpw[MAXN][MAXN][2];

inline int power(int x,int p) {
   int r=1,m=x;
   while(p) {
      if(p&1) r=(long long)r*m%mod;
      m=(long long)m*m%mod;
      p>>=1;
   }
   return r;
}

void pre() {
   for(int i=0;i<=rn;i++) {
      cm[i][0]=cm[i][i]=1;
      for(int j=1;j<i;j++)
         cm[i][j]=(cm[i-1][j-1]+cm[i-1][j])%mod;
   }
   for(int i=0;i<rn;i++)
      coef[i]=(cn+rn-1-i)/rn%(mod-1);
   basepow=coef[0];
   for(int i=0;i<=rn;i++) {
      for(int j=0;j<=i;j++) {
         cmpw[i][j][0]=power(cm[i][j],basepow);
         cmpw[i][j][1]=power(cm[i][j],basepow-1);
      }
   }
}

inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }

int solve() {
   pre();
   dp[0][0]=1;
   for(int i=0;i<rn;i++) {
      //printf("<%d>\n",i);
      for(int s=0;s<=k&&s<=i*rn;s++) {
         if(!dp[i][s]) continue;
         for(int j=0;j<=rn&&s+j<=k;j++) {
            dp[i+1][s+j]=add(dp[i+1][s+j],(long long)dp[i][s]*cmpw[rn][j][coef[i]==coef[0]?0:1]%mod);
         }
      }
   }
   return dp[rn][k];
}

int main(void)
{
   cin >> rn >> cn >> k;
   printf("%d\n",solve());
   return 0;
}