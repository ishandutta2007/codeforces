#include <bits/stdc++.h>

template<typename _Func>
int get_ans(int L, int R, _Func chk) {
	int l = 0, r = (R - L) / 2, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (chk(L + mid * 2)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	return ans + 1;
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	std::vector<long long> pre(n + 1), suf(n + 1), sum(n + 1);
	pre[0] = 0;
	for (int i = 0; i < n; ++i) {
		pre[i + 1] = pre[i] + a[i];
	}
	suf[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = suf[i + 1] + a[i];
	}
	sum[0] = 0;
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = a[i] - sum[i];
	}

	long long ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans += get_ans(i, n, [&](int x) {
			return suf[x] + sum[i] - sum[x] - pre[i] > 0;
		});
	}
	for (int i = 3; i <= n; ++i) {
		ans += get_ans(i, n, [&](int x) {
			return suf[x] + sum[i] - sum[x] - pre[i] + 2 * a[0] > 0;
		});
	}
	for (int i = 0; i <= n - 3; ++i) {
		ans += get_ans(i, n - 3, [&](int x) {
			return suf[x] + sum[i] - sum[x] - pre[i] - 2 * a[n - 1] > 0;
		});
	}
	for (int i = 3; i <= n - 3; ++i) {
		ans += get_ans(i, n - 3, [&](int x) {
			return suf[x] + sum[i] - sum[x] - pre[i] + 2 * a[0] - 2 * a[n - 1] > 0;
		});
	}
	for (int i = 2; i <= n - 2; ++i) {
		if (pre[i] > suf[i]) {
			++ans;
		}
	}
	std::cout << ans % 998244353 << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}