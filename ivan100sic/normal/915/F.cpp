#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int p[1000005], sz[1000005];

void reset() {
	iota(p, p+n, 0);
	fill(sz, sz+n, 1);
}

int endp(int x) {
	if (x == p[x])
		return x;
	return x = endp(p[x]);
}

ll spoji(int x, int y) {
	x = endp(x);
	y = endp(y);
	if (x == y)
		return 0;
	if (sz[x] > sz[y])
		swap(x, y);
	ll parova = sz[x] * 1ll * sz[y];
	p[x] = y;
	sz[y] += sz[x];
	return parova;
}

int a[1000005];
basic_string<int> e[1000005];
basic_string<pair<int, int>> asrt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		asrt += {a[i], i};
	}

	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		e[x] += y;
		e[y] += x;
	}

	ll sol = 0;

	sort(asrt.begin(), asrt.end());
	reset();
	for (auto [v, x] : asrt) {
		for (int y : e[x]) {
			if (a[y] > a[x])
				continue;
			ll sp = spoji(x, y);
			sol += sp * v;
		}
	}

	reverse(asrt.begin(), asrt.end());
	reset();
	for (auto [v, x] : asrt) {
		for (int y : e[x]) {
			if (a[y] < a[x])
				continue;
			ll sp = spoji(x, y);
			sol -= sp * v;
		}
	}

	cout << sol << '\n';
}