#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;
const int maxN = 2234;

int n, a[maxN][maxN], pused[maxN], cused[maxN];
i64 way[maxN][maxN], fact[maxN];

struct fenwick {
	int c[maxN], all;
	void init() {
		for (int i = 1; i <= n; i++)
			c[i] = 0;
		all = 0;
	}
	void modify(int x, int s) {
		for (; x <= n; x += x & -x) {
			c[x] += s;
		}
		all += s;
	}
	int query(int x) {
		int s = 0;
		for (; x; x -= x & -x) {
			s += c[x];
		}
		return s;
	}
} cnt[2];

void modify(int key, int p1, int p2) {
	if (cused[key] == 0)
		cnt[pused[key]].modify(key, -1);
	if (p1 == -1) p1 = pused[key];
	if (p2 == -1) p2 = cused[key];
	pused[key] = p1;
	cused[key] = p2;
	if (cused[key] == 0)
		cnt[pused[key]].modify(key, 1);
}

int main() {
	scanf("%d", &n);
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = fact[i - 1] * i % mod;
	for (int i = 0; i <= n; i++) {
		way[i][0] = fact[i];
		for (int j = 1; j <= i; j++) {
			way[i][j] = way[i][j - 1] - way[i - 1][j - 1];
			if (way[i][j] < 0) way[i][j] += mod;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			pused[k] = (i != 1);
			cused[k] = 0;
		}
		for (int p1 = 0; p1 <= 1; p1++) cnt[p1].init();
		for (int k = 1; k <= n; k++) cnt[pused[k]].modify(k, 1);
		i64 cway = 1, rowans = 0;
		for (int j = 0; j < n - i; j++) cway = cway * way[n][n] % mod;
		for (int j = 1; j <= n; j++) {
			if (i > 1) modify(a[i - 1][j], 0, -1);
			int z1 = cnt[1].query(a[i][j] - 1);
			rowans = (rowans + z1 * way[n - j][cnt[1].all - 1]) % mod;
			int z2 = cnt[0].query(a[i][j] - 1);
			if (i > 1 && a[i - 1][j] < a[i][j] && cused[a[i - 1][j]] == 0) --z2;
			rowans = (rowans + z2 * way[n - j][cnt[1].all]) % mod;
			modify(a[i][j], -1, 1);
//			printf("%d %d %d %d %lld\n", i, j, z1, z2, rowans);
		}
//		printf("%d %lld\n", i, rowans);
		ans = (ans + rowans * cway) % mod;
	}
	ans = (ans + mod) % mod;
	printf("%lld\n", ans);
}