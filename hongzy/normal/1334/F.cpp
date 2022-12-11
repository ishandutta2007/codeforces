#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
const ll INF = 1e18;
int n, m, a[N], b[N], c[N], pre[N];
ll sum, dp[N], x[N], y[N];

ll bit[N];
void bitadd(int u, ll v) {
	for(; u <= n; u += u & (-u)) {
		bit[u] += v;
	}
}
ll bitqry(int u) {
	ll ans = 0;
	for(; u >= 1; u &= u - 1) {
		ans += bit[u];
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) { scanf("%d", a + i); pre[a[i]] = -1; }
	for(int i = 1; i <= n; i ++) { scanf("%d", c + i); sum += c[i]; }
	scanf("%d", &m);
	for(int i = 1; i <= m; i ++) { scanf("%d", b + i); pre[b[i]] = b[i - 1]; }
	for(int i = n; i >= 1; i --) {
		if(~ pre[a[i]]) {
 			x[i] = bitqry(a[i]);
			y[i] = bitqry(pre[a[i]]);
		}
		if(c[i] > 0) bitadd(a[i], c[i]);
	}
	dp[0] = 0; fill(dp + 1, dp + n + 1, -INF);
	for(int i = 1; i <= n; i ++) {
		if(~ pre[a[i]] && dp[pre[a[i]]] != -INF) {
			dp[a[i]] = max(dp[a[i]], dp[pre[a[i]]] - y[i] + x[i] + c[i]);
		}
	}
	if(dp[b[m]] == -INF) { puts("NO"); return 0; }
	printf("YES\n%lld\n", sum - dp[b[m]]);
	return 0;
}