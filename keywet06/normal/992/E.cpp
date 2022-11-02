#include <bits/stdc++.h>

using int64 = long long;

const int N = 300005;
const int M = 1 << 18;
const int INF = 0x3f3f3f3f;

int n;

int64 bit[N], in[N];

void update(int p, int64 v) {
	int64 dv = v - in[p];
	in[p] = v;
	for (; p <= M; p += p & (-p)) bit[p] += dv;
}

int64 getsum(int p) {
	int64 rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}

int largerpos(int64 v) {
	if (bit[M] <= v) return INF;
	int64 p = 0, s = 0;
	for (int i = 17; i >= 0; i--) {
		if (s + bit[p + (1 << i)] <= v) {
			s += bit[p + (1 << i)];
			p |= (1 << i);
		}
	}
	return p + 1;
}

int main() {
	int n, q, i, j;
	std::cin >> n >> q;
	for (i = 1; i <= n; i++) {
		int t;
		std::cin >> t;
		update(i, t);
	}
	while (q--) {
		int p, v;
		std::cin >> p >> v;
		update(p, v);
		if (in[1] == 0) {
			std::cout << 1 << '\n';
			continue;
		}
		int ans = -1;
		int64 cur = in[1];
		while (1) {
			int p = largerpos(2 * cur - 1);
			if (p == INF) break;
			int64 v = getsum(p - 1);
			if (v == in[p]) {
				ans = p;
				break;
			}
			cur = v + in[p];
		}
		std::cout << ans << '\n';
	}
	return 0;
}