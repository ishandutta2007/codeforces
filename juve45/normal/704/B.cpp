#include <bits/stdc++.h>

using namespace std;

const long long N = 5005;
long long n, k, dp[N][N], s, e, m, l, a[N], b[N], c[N], d[N], x[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> s >> e;
	for(long long i= 1; i <= n; i++) cin >> x[i];
	for(long long i= 1; i <= n; i++) cin >> a[i];
	for(long long i= 1; i <= n; i++) cin >> b[i];
	for(long long i= 1; i <= n; i++) cin >> c[i];
	for(long long i= 1; i <= n; i++) cin >> d[i];

	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	
	long long k = 0, l = 0;
	for(long long i = 1; i <= n; i++) {
		long long dist = (x[i] - x[i - 1]);
		for(long long j = 1; j <= (i + 1); j++) {
			if(i != s && i != e) {
					if(j > 1 || !l) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (2 * j - k - l) * dist + a[i] + d[i]);
					if(j > 1 || !k) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (2 * j - k - l) * dist + b[i] + c[i]);
					if(!k || !l || j > 2) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (2 * (j - 1) - k - l) * dist + b[i] + d[i]);
					dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + (2 * (j + 1) - k - l) * dist + a[i] + c[i]);
			} else if(i == s) 
					dp[i][j] = min(dp[i - 1][j - 1] + (2 * (j - 1) - k - l) * dist + d[i], dp[i - 1][j] + (2 * j - l) * dist + c[i]); // OK
			else if(i == e) 
					dp[i][j] = min(dp[i - 1][j - 1] + (2 * (j - 1) - k - l) * dist + b[i], dp[i - 1][j] + (2 * j - k) * dist + a[i]); //OK
		}
		if(i == e) l++;
		if(i == s) k++;
	}
	cout << dp[n][1] << '\n';
}