#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)104;
int N;
int A[NS], B[NS];
int dp[NS][NS * NS][2];

int main(){
	scanf("%d", &N);
	int sum = 0;
	for(int i = 1; i <= N; ++i){
		scanf("%d %d", A + i, B + i);
		sum += B[i];
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	for(int i = 1; i <= N; ++i){
		for(int k = 0; k <= N; ++k){
			for(int j = 0; j < NS * NS; ++j){
				if(dp[k][j][0] == -1){
					continue;
				}
				dp[k][j][1] = max(dp[k][j][1], dp[k][j][0]);
				if(j + A[i] < NS * NS){
					dp[k + 1][j + A[i]][1] = max(dp[k + 1][j + A[i]][1], dp[k][j][0] + B[i]);
				}
			}
		}
		for(int k = 0; k <= N; ++k){
			for(int j = 0; j < NS * NS; ++j){
				dp[k][j][0] = dp[k][j][1];
				dp[k][j][1] = -1;
			}
		}
		dp[0][0][0] = 0;
	}
	for(int i = 1; i <= N; ++i){
		double ans = 0;
		for(int j = 0; j < NS * NS; ++j){
			 if(dp[i][j][0] != -1) ans = max(ans, min((double)j, dp[i][j][0] + (double)(sum - dp[i][j][0]) / 2));
		}
		printf("%f ", ans);
	}
	return 0;
}