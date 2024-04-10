#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
int a[200005];
int z[200005];
int dp[2005];
int best[2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	partial_sum(a, a+k, z+1);
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> y >> x;
		if (y <= k) {
			best[y] = max(best[y], x);
		}
	}
	memset(dp, 63, sizeof(dp));
	dp[0] = 0;
	for (int j=1; j<=k; j++) {
		for (int w=1; w<=j; w++) {
			dp[j] = min(dp[j], dp[j-w] + z[j] - z[j - w + best[w]]);
		}
	}
	cout << dp[k] << '\n';
}