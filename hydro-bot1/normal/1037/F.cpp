// Hydro submission #6204c8c43bf2009cb933f388@1644480708448
#include <bits/stdc++.h>
using namespace std;

#define int long long

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}

#define N 1000010
#define P 1000000007

int n, k, res, a[N], mx[N], s[N];

void Solve(int l, int r) {
	if (r - l + 1 < k) return;
	int m = l + r >> 1; mx[m] = a[m], s[m] = 0, s[l - 1] = 0;
	for (int i = m - 1; i >= l; i --) {
		mx[i] = max(mx[i + 1], a[i]), s[i] = 0;
	}
	for (int i = l; i <= m; i ++) {
		int x = i - k + 1;
		if (x >= l) s[i] = s[x];
		(s[i] += mx[i]) %= P;
	}
	int Mx = a[m + 1];
	for (int i = m + 1, j = m; i <= r; i ++, Mx = max(Mx, a[i])) {
		if (i - l + 1 < k) continue;
		while (j >= l && mx[j] < Mx) j --;
		int x = i - j, t = (x - 1) / (k - 1), u = t + 1;
		t -= (i - m - 1) / (k - 1);
		(res += Mx * t % P + s[max(i -(u * (k - 1)), l - 1)]) %= P;
    }
	Solve(l, m), Solve(m + 1, r);
}

signed main() {
	n = read(), k = read();
	for (int i = 1; i <= n; i ++) {
		a[i] = read();
	}
	Solve(1, n);
	printf("%lld\n", res);
	return 0;
}