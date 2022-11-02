#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = (int)1e9 + 7;
const long long INFF = (long long) 1e18;
const int N = (int)1e6 + 7;
long long a[ N ];
long long r[5];
long long dp[ N ][ 2 ][ 2 ];
int main() {
	int n; long long d; scanf("%d %lld %lld %lld %lld", &n, r + 1, r + 2, r + 3, &d);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = INFF;
	dp[0][0][1] = 0;
	for (int i = 1; i <= n; i++) {
		// used type2
		// to left
		long long v1 = min(r[2], r[1] * (a[i] + 1))  + 2 * d + r[1];
		if (i != 1) {
			dp[i][0][0] = min(dp[i][0][0], dp[i-1][1][0] + v1 + d + r[1]);
			dp[i][0][0] = min(dp[i][0][0], dp[i-1][1][1] + v1 + r[1]);
			dp[i][0][0] = min(dp[i][0][0], dp[i-1][0][0] + v1 + d);
			dp[i][0][0] = min(dp[i][0][0], dp[i-1][0][1] + v1);
		}
		// to right
		if (i != n) {
			v1 = min(r[2], r[1] * (a[i] + 1)) + d;
			dp[i][1][1] = min(dp[i][1][1], dp[i-1][0][0] + v1 + d);
			dp[i][1][1] = min(dp[i][1][1], dp[i-1][0][1] + v1);
		}
		// used type1 + type3
		v1 = r[1] * a[i] + r[3];
		dp[i][0][0] = min(dp[i][0][0], dp[i-1][0][0] + v1 + d);
		dp[i][0][0] = min(dp[i][0][0], dp[i-1][0][1] + v1);
		if (i != n)
			dp[i][0][0] = min(dp[i][0][0], dp[i-1][1][0] + v1 + d + 2*d + r[1]);
		else 
			dp[i][0][0] = min(dp[i][0][0], dp[i-1][1][0] + v1 + d + d + r[1]);
		if (i != n)
			dp[i][0][0] = min(dp[i][0][0], dp[i-1][1][1] + v1 + 2*d + r[1]);
		else 
			dp[i][0][0] = min(dp[i][0][0], dp[i-1][1][1] + v1 + d + r[1]);
	}
	printf("%lld\n", dp[n][0][0]);
	return 0;
}