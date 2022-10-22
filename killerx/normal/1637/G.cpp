#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

std::vector <std::pair <int, int> > op;

inline void D(int &a, int &b) {
	op.push_back({a, b});
	int x = a + b;
	int y = std::abs(a - b);
	a = x, b = y;
}

inline void E(int a, int b) {
	op.push_back({a, b});
}

const int mxn = 1 << 16;
int a[mxn];

inline void solve(int l, int r) {
	const int n = r - l;
	if (n <= 2) return ;
	int k = 0; while (1 << k < n) ++ k;
	if (n == 1 << k) {
		for (int i = 1; i < n - i; ++ i) D(a[l + i - 1], a[l + n - i - 1]);
		solve(l + (1 << (k - 1)), r - 1);
		return ;
	}
	for (int i = n; i > 1 << (k - 1); -- i) D(a[l + i - 1], a[l + (1 << k) - i - 1]);
	std::reverse(a + l + (1 << k) - n - 1, a + l + (1 << (k - 1)) - 1);
	solve(l, l + (1 << k) - n - 1);
	solve(l + (1 << k) - n - 1, l + (1 << (k - 1)) - 1);
}

inline void Main() {
	int n; scanf("%d", &n);
	if (n == 2) { puts("-1"); return ; }
	op.clear();
	rep(i, n) a[i] = i + 1;
	solve(0, n);
	static int cnt[20];
	memset(cnt, 0, sizeof(cnt));
	rep(i, n) cnt[__builtin_ctz(a[i])] += 1;
	int k = 0; while (1 << k < n) ++ k;
	for (int i = 0; i < k; ++ i) {
		if (cnt[i] >= 2) {
			E(1 << i, 1 << i);
			rep(j, cnt[i] - 2) E(1 << i, 0), E(1 << i, 1 << i);
			E(2 << i, 0);
			cnt[i + 1] += cnt[i], cnt[i] = 0;
			continue;
		}
		if (cnt[i] == 1) {
			assert(cnt[i + 1]);
			E(1 << i, 2 << i), E(1 << i, 3 << i), -- cnt[i], ++ cnt[i + 2];
		}
	}
	assert(cnt[k] == n);
	printf("%d\n", (int) op.size());
	rep(i, op.size()) printf("%d %d\n", op[i].first, op[i].second);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}