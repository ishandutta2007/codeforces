#include <bits/stdc++.h>
using namespace std;
int mod;
inline int add(int a, int b){
	a += b;
	if(a >= mod)
		a -= mod;
	return a;
}

const int N = 505;
int dp[N][N], dp2[N][N], a[N];

int main(){
	int n, M, B;
	scanf("%d %d %d %d", &n, &M, &B, &mod);
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		memcpy(dp2, dp, sizeof dp2);
		memset(dp, 0, sizeof dp);
		for(int m = 0; m <= M; m++){
			for(int b = 0; b <= B; b++){
				dp[m][b] = dp2[m][b];
				if(b >= a[i] && m > 0) dp[m][b] = add(dp[m][b], dp[m - 1][b - a[i]]);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i <= B; i++){
		ans = add(ans, dp[M][i]);
	}
	printf("%d\n", ans);
}