#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
int n, b, a[65];
ll dp[11][65][1 << 10];
ll dfs(int n, int S, int lim, int zo) {
	if(n == 0) return zo == 0 && S == 0;
	if(!lim && !zo && ~ dp[b][n][S]) return dp[b][n][S];
	ll res = 0;
	int up = lim ? a[n] : b - 1;
	for(int i = 0; i <= up; i ++) {
		if(zo && i == 0) {
			res += dfs(n - 1, S, lim && i == up, 1);
		} else {
			res += dfs(n - 1, S ^ (1 << i), lim && i == up, 0);
		}
	}
	if(!lim && !zo) dp[b][n][S] = res;
	return res;
}
ll solve(ll x) {
	if(x == 0) return 0ll;
	for(n = 0; x; x /= b) a[++ n] = x % b;
	return dfs(n, 0, 1, 1);
}
int main() {
	memset(dp, -1, sizeof dp);
	int test; scanf("%d", &test);
	while(test --) {
		ll l, r;
		scanf("%d%I64d%I64d", &b, &l, &r);
		printf("%I64d\n", solve(r) - solve(l - 1));
	}
	return 0;
}