#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int p[100005], s[100005], n;

int ep(int x) {
	while (x != p[x])
		x = p[x];
	return x;
}

void spoji(int x, int y) {
	x = ep(x);
	y = ep(y);
	if (x == y)
		return;
	if (s[x] > s[y])
		swap(x, y);
	p[x] = y;
	s[y] += s[x];
}

bool lucky(int x) {
	while (x > 0) {
		int y = x % 10;
		if (y != 4 && y != 7)
			return false;
		x /= 10;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	iota(p, p+n+1, 0);
	fill(s+1, s+n+1, 1);

	for (int i=1; i<n; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		if (!lucky(l)) {
			spoji(u, v);
		}
	}

	ll sol = 0;
	for (int i=1; i<=n; i++) {
		ll t = s[ep(i)];
		sol += (n-t)*(n-t-1);
	}

	cout << sol << '\n';
}