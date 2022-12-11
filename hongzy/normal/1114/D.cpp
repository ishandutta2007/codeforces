#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 5010; 

int n, a[N], dp[N][N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		if(a[i] == a[i - 1]) {
			i --; n --;
		}
	}
	for(int i = 1; i <= n; i ++) dp[i][i] = 0;
	for(int i = n; i >= 1; i --) {
		for(int j = i + 1; j <= n; j ++) {
			if(a[i] == a[j]) dp[i][j] = dp[i + 1][j - 1] + 1;
			else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
		}
	}
	printf("%d\n", dp[1][n]);
	return 0;
}