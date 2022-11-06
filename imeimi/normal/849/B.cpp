#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llong;

struct frac {
	int b, a;
	bool operator==(const frac &p) const {
		return (llong)a * p.b == (llong)b * p.a;
	}
	bool operator<(const frac &p) const {
		return (llong)a * p.b > (llong)b * p.a;
	}
	frac() {}
	frac(int b, int a) : b(b), a(a) {}
};

int n;
int y[1000];
frac fs[1000];

bool ccw(llong x1, llong y1, llong x2, llong y2, llong x3, llong y3) {
	return x1 * y2 + x2 * y3 + x3 * y1 == y1 * x2 + y2 * x3 + y3 * x1;
}

bool check(frac m) {
	int cnt = 0, i;
	int x1, x2, y1, y2;
	for (i = 0; i < n; ++i) {
		if (fs[i] == m) continue;
		if (cnt == 0) {
			x1 = i;
			y1 = y[i];
			cnt = 1;
		}
		else if (cnt == 1) {
			if (!(frac(y[i] - y1, i - x1) == m)) return false;
		}
	}
	return true;
}

bool check2() {
	for (int i = 3; i < n; ++i) {
		if (!ccw(1, y[1], 2, y[2], i, y[i])) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; ++i) cin >> y[i];
	frac M, m;
	bool ch = true;
	for (i = 1; i < n; ++i) {
		fs[i] = { y[i] - y[0] , i };
		if (i > 1 && !(fs[i] == fs[i - 1])) ch = false;
	}
	if (ch) {
		printf("No\n");
		return 0;
	}
	M = m = fs[1];
	for (i = 2; i < n; ++i) {
		M = max(M, fs[i]);
		m = min(m, fs[i]);
	}
	if (check(M) || check(m) || check2()) printf("Yes\n");
	else printf("No\n");
	return 0;
}