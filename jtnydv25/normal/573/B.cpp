#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int H[N], dp[2][N];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", H + i);

		dp[0][i] = min(dp[0][i - 1] + 1, H[i]);
	}
	int ans = 0;
	for(int i = n; i >= 1; i--){
		dp[1][i] = min(dp[1][i + 1] + 1, H[i]);
		ans = max(ans, min(dp[0][i], dp[1][i]));
	}

	printf("%d\n", ans);;

}