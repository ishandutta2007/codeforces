#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 1000050

using namespace std;

const int mod = 1000000007;

int n;
int dp[MAXN];

inline int add(int a,int b) {
   return a+b<mod?a+b:a+b-mod;
}

int main(void)
{
   scanf("%d",&n);
   int a[2],sol=0;
   a[0]=a[1]=0;
   for(int i=0;i<n;i++) {
      dp[i]=add(a[!(i&1)],1);
      a[i&1]=add(a[i&1],dp[i]);
      sol=add(sol,dp[i]);
   }
   printf("%d\n",sol);
   return 0;
}