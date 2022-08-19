#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL INF = 6E18;
void solve() {
	int n;
	cin >> n;
	vector<LL> x(n), y(n), z(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i] >> z[i];
	LL l = 0, r = 3E18;
	auto check = [&](LL d) {
		LL a = -INF, A = INF, b = -INF, B = INF, c = -INF, C = INF, s = -INF, S = INF;
		for (int i = 0; i < n; ++i) {
			a = max(a, -x[i] + y[i] + z[i] - d);
			A = min(A, -x[i] + y[i] + z[i] + d);
			b = max(b, x[i] - y[i] + z[i] - d);
			B = min(B, x[i] - y[i] + z[i] + d);
			c = max(c, x[i] + y[i] - z[i] - d);
			C = min(C, x[i] + y[i] - z[i] + d);
			s = max(s, x[i] + y[i] + z[i] - d);
			S = min(S, x[i] + y[i] + z[i] + d);
		}
		for (int r = 0; r < 2; ++r) {
			LL a0 = (a - r + 1) >> 1, A0 = (A - r) >> 1, b0 = (b - r + 1) >> 1, B0 = (B - r) >> 1, c0 = (c - r + 1) >> 1, C0 = (C - r) >> 1, s0 = (s - 3 * r + 1) >> 1, S0 = (S - 3 * r) >> 1;
			if (a0 <= A0 && b0 <= B0 && c0 <= C0 && s0 <= S0 && A0 + B0 + C0 >= s0 && S0 >= a0 + b0 + c0) {
				LL a = a0, b = b0, c = c0;
				LL res = max(0LL, s0 - a - b - c);
				LL d = min(A0 - a, res);
				a += d;
				res -= d;
				d = min(B0 - b, res);
				b += d;
				res -= d;
				d = min(C0 - c, res);
				c += d;
				res -= d;
				return make_tuple(true, b + c + r, a + c + r, a + b + r);
			}
		}
		return make_tuple(false, 0LL, 0LL, 0LL);
	};
	while (l < r) {
		LL d = (l + r) / 2;
		if (get<0>(check(d)))
			r = d;
		else
			l = d + 1;
	}
	bool tmp;
	LL x0, y0, z0;
	tie(tmp, x0, y0, z0) = check(l);
	cout << x0 << " " << y0 << " " << z0 << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}