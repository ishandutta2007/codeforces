#include<iostream>
#include<algorithm>
#include<cstdio>
#include<deque>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,a) for(int i=a;i<(int)m;++i)
using namespace std;
int n;
int dp[10000005][4];
const int mod=1000000007;
int main(){
	scanf("%d",&n);
	dp[0][0]=1;
	REP(i,n) REP(j,4) REP(k,4) if(j!=k) dp[i+1][k]+=dp[i][j],dp[i+1][k]%=mod;
	printf("%d\n",dp[n][0]);
	return 0;
}