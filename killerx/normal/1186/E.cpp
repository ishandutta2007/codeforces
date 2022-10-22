#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n, m, q;
int c[1005][1005];
ll sum[1005][1005];
char tmp[1005];
int get(int x, int y) {
	if (x == 1 && y == 1) return 0;
	int s = max(x, y) - 1;
	while (__builtin_popcount(s) > 1) s -= s & -s;
	if (x > s && y > s) {
		return get(x - s, y - s);
	} else if (x > s) {
		return get(x - s, y) ^ 1;
	} else if (y > s) {
		return get(x, y - s) ^ 1;
	}
}
ll Sum(int x, int y) {
	if (!x || !y) return 0;
	int x1 = x / n, y1 = y / m;
	// eprintf("q %d %d %d %d\n", x, y, x1, y1);
	ll ans = 0;
	// (1)
	ans += 1LL * n * m * (1LL * x1 * y1 / 2);
	if ((x1 & 1) && (y1 & 1)) {
		int f = get(x1, y1);
		ll s = sum[n][m];
		// eprintf("1 %d %lld\n", f, s);
		if (f) ans += 1LL * n * m - s;
		else ans += s;
	}
	// eprintf("ans %d\n", ans);
	// (2)
	ans += 1LL * n * (y - y1 * m) * (x1 / 2);
	if (x1 & 1) {
		int f = get(x1, y1 + 1);
		ll s = sum[n][y - y1 * m];
		// eprintf("2 %d %lld\n", f, s);
		if (f) ans += 1LL * n * (y - y1 * m) - s;
		else ans += s;
	}
	// eprintf("ans %d\n", ans);
	// (3)
	ans += 1LL * (x - x1 * n) * m * (y1 / 2);
	if (y1 & 1) {
		int f = get(x1 + 1, y1);
		ll s = sum[x - x1 * n][m];
		// eprintf("3 %d %lld\n", f, s);
		if (f) ans += 1LL * (x - x1 * n) * m - s;
		else ans += s;
	}
	// eprintf("ans %d\n", ans);
	// (4)
	int f = get(x1 + 1, y1 + 1);
	ll s = sum[x - x1 * n][y - y1 * m];
	// eprintf("4 %d %lld\n", f, s);
	if (f) ans += 1LL * (x - x1 * n) * (y - y1 * m) - s;
	else ans += s;
	// eprintf("ans %lld\n", ans);
	return ans;
}
int main() {
	n = read(), m = read(), q = read();
	rep(i, n) {
		scanf("%s", tmp);
		rep(j, m) c[i + 1][j + 1] = tmp[j] - '0';
	}
	rep(i, n) rep(j, m) {
		sum[i + 1][j + 1] = c[i + 1][j + 1] + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
	}
	while (q --) {
		int x1 = read(), y1 = read(), x2 = read(), y2 = read();
		printf("%lld\n", Sum(x2, y2) - Sum(x1 - 1, y2) - Sum(x2, y1 - 1) + Sum(x1 - 1, y1 - 1));
	}
	return 0;
}