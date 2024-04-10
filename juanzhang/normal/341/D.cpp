#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1010;
int n, m, a[maxn][maxn]; ll c[4][maxn][maxn];

inline void upd(int x, int y, ll val) {
	int p = (x & 1) + ((y & 1) << 1);
	for (int i = x; i <= n; i += i & -i) {
		for (int j = y; j <= n; j += j & -j) {
			c[p][i][j] ^= val;
		}
	}
}

inline ll query(int x, int y) {
	ll res = 0;
	int p = (x & 1) + ((y & 1) << 1);
	for (int i = x; i; i &= i - 1) {
		for (int j = y; j; j &= j - 1) {
			res ^= c[p][i][j];
		}
	}
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	int op, x1, y1, x2, y2; ll x;
	while (m--) {
		scanf("%d %d %d %d %d", &op, &x1, &y1, &x2, &y2);
		if (op == 1) {
			printf("%lld\n", query(x2, y2) ^ query(x1 - 1, y2) ^ query(x2, y1 - 1) ^ query(x1 - 1, y1 - 1));
		} else {
			scanf("%lld", &x);
			upd(x1, y1, x), upd(x2 + 1, y1, x), upd(x1, y2 + 1, x), upd(x2 + 1, y2 + 1, x);
		}
	}
	return 0;
}