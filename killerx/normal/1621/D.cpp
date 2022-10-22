// what the hell?

#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mxn = 505;

int n;
int val[mxn][mxn];

void Main() {
	scanf("%d", &n);
	rep(i, n * 2) rep(j, n * 2) scanf("%d", &val[i][j]);
	i64 ans = 0;
	rep(i, n) rep(j, n) ans += val[i + n][j + n], val[i + n][j + n] = 0;
	int cur = 1 << 30;
	cur = std::min(cur, std::min(val[0][n], val[0][n * 2 - 1]));
	cur = std::min(cur, std::min(val[n - 1][n], val[n - 1][n * 2 - 1]));
	cur = std::min(cur, std::min(val[n][0], val[n][n - 1]));
	cur = std::min(cur, std::min(val[n * 2 - 1][0], val[n * 2 - 1][n - 1]));
	printf("%lld\n", ans + cur);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}