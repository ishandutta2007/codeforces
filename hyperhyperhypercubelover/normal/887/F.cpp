#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

pair<int, int> a[500005];
int d[500005];

void upd(int x, int y) {
	while (x <= 500000) {
		d[x] += y;
		x += x & -x;
	}
}

int qry(int x) {
	int r = 0;
	while (x) {
		r += d[x];
		x &= x - 1;
	}
	return r;
}

int main() {
	int L, R;
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	upd(1, 1);
	upd(m + 1, -1);
	L = -1e9;
	R = 1e9;
	j = n;
	for (i = 0; i < n; i++) {
		a[i].second = n - a[i].second;
		if (!qry(a[i].second)) {
			if (j == n) j = i;
			if (L < a[i].second - m) L = a[i].second - m;
			if (R > a[i].second) R = a[i].second;
		}
		upd(a[i].second, 1);
		upd(a[i].second + m + 1, -1);
	}
	if (L > R) {
		puts("NO");
		return 0;
	}
	if (j == n) {
		puts("YES");
		return 0;
	}
	for (i = 0; i <= 500000; i++) d[i] = 0;
	upd(1, 1);
	upd(m + 1, -1);
	for (i = 0; i < j; i++) {
		if (a[i].second < L && qry(L)) {
			puts("YES");
			return 0;
		}
		upd(a[i].second, 1);
		upd(a[i].second + m + 1, -1);
	}
	puts("NO");
	return 0;
}