#include<bits/stdc++.h>
typedef long long ll;
const int MAXN=35;
ll n,h;
ll dp[MAXN+5][MAXN+5];
int main(){
	scanf("%I64d%I64d",&n,&h);
	for(int i=0;i<=n;++i)
		dp[0][i]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=0;k<i;++k)
				dp[i][j]+=dp[k][j-1]*dp[i-k-1][j-1];
	printf("%I64d\n",dp[n][n]-dp[n][h-1]);
	return 0;
}