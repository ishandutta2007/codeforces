#include <bits/stdc++.h>
#define p 998244353

using namespace std;
typedef long long ll;

ll dp[10][1001][2002];
/* 0 : WW 1 : WB 2 : BW 3 : BB */

ll dyp(int i, int n, int k){
	if (dp[i][n][k] != 0) return dp[i][n][k];
	if (k==0 || k>2*n) return 0;
	if (k==1 && (i==0 || i==3))return 1;
	if (k==1 ) return 0;
	
	if (i==0){
		dp[i][n][k] = dyp(0, n-1, k) + dyp(1, n-1, k) + dyp(2, n-1, k) + dyp(3, n-1, k-1);
		dp[i][n][k] %= p;
	}
	if (i==1){
		dp[i][n][k] = dyp(0, n-1, k-1) + dyp(1, n-1, k) + dyp(2, n-1, k-2) + dyp(3, n-1, k-1);
		dp[i][n][k] %= p;
	}
	if (i==2){
		dp[i][n][k] = dyp(0, n-1, k-1) + dyp(1, n-1, k-2) + dyp(2, n-1, k) + dyp(3, n-1, k-1);
		dp[i][n][k] %= p;
	}
	if (i==3){
		dp[i][n][k] = dyp(0, n-1, k-1) + dyp(1, n-1, k) + dyp(2, n-1, k) + dyp(3, n-1, k);
		dp[i][n][k] %= p;
	}
	return dp[i][n][k] % p;
}
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	dp[0][1][1] = 1;
	dp[1][1][2] = 1;
	dp[2][1][2] = 1;
	dp[3][1][1] = 1;
	
	int i;
	ll sum = 0;
	for(i=0;i<4;i++){
		sum += dyp(i, n, k) % p;
	}
	sum %= p;
	printf("%lld", sum);
	
}