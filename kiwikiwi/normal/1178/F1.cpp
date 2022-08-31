#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 P = 998244353;
#define maxN 1234

i64 dp[maxN][maxN];
int a[1234567], n, m, t, posl[maxN], posr[maxN];


i64 solve(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l > r) return 1;
	i64 &val = dp[l][r];
	val = 0;
	int minc = a[l];
	for (int j = l; j <= r; j++) {
		minc = min(minc, a[j]);
	}
	int prepos = -1;
	i64 tmpval = 1;
	for (int j = l; j <= r; j++) {
		if (a[j] == minc) {
			if (prepos != -1) {
				tmpval = tmpval * solve(prepos + 1, j - 1) % P;
			}
			prepos = j;
		}
	}
	i64 lval = 0;
	for (int j = l; j <= posl[minc]; j++) {
		lval = (lval + solve(l, j - 1) * solve(j, posl[minc] - 1)) % P;
	}
	i64 rval = 0;
	for (int j = posr[minc]; j <= r; j++) {
		rval = (rval + solve(posr[minc] + 1, j) * solve(j + 1, r)) % P;
	}
	return val = tmpval * lval % P * rval % P;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
	int c = 0;
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		if (x != c) a[++t] = x;
		c = x;
	}
	if (t >= 2 * n) {
		printf("%d\n", 0);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int l = t + 1, r = 0;
		for (int j = 1; j <= t; j++) {
			if (a[j] == i) {
				l = min(l, j);
				r = max(r, j);
			}
		}
		for (int j = l; j <= r; j++) if (a[j] < i) {
				printf("%d\n", 0);
				return 0;
			}
		posl[i] = l;
		posr[i] = r;
	}
	printf("%lld\n", solve(1, t));
}