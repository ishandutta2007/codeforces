#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e5 + 10, INF = 0x3f3f3f3f;
int n, a[maxn];

inline int fabs(const int& x) {
	return x < 0 ? -x : x;
}

inline void chkmin(int& x, const int& y) {
	if (x > y) x = y;
}

inline void chkmax(int& x, const int& y) {
	if (x < y) x = y;
}

int main() {
	ll sum = 0;
	bool flg1 = 1, flg2 = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		flg1 &= a[i] >= 0;
		flg2 &= a[i] <= 0;
		sum += a[i];
	}
	if (n == 1) {
		return printf("%d", a[1]), 0;
	}
	if (flg1) {
		int mn = INF;
		for (int i = 1; i <= n; i++) {
			chkmin(mn, a[i]);
		}
		printf("%lld\n", sum - 2ll * mn);
	} else if (flg2) {
		int mx = -INF;
		for (int i = 1; i <= n; i++) {
			chkmax(mx, a[i]);
		}
		printf("%lld\n", 2ll * mx - sum);
	} else {
		ll res = 0;
		for (int i = 1; i <= n; i++) {
			res += fabs(a[i]);
		}
		printf("%lld\n", res);
	}
	return 0;
}