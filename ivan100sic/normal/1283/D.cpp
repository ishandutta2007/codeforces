#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	map<int, int> d;
	basic_string<int> q;
	size_t qs = 0;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		d[x] = 0;
		q += x;
	}
	ll sol = 0;
	while ((int)d.size() != n+m) {
		int x = q[qs++];
		auto go = [&](int y) {
			if (d.count(y))
				return;
			d[y] = d[x] + 1;
			sol += d[y];
			q += y;
		};
		go(x-1);
		if ((int)d.size() == n+m)
			break;
		go(x+1);
	}
	cout << sol << '\n';
	for (auto [x, y] : d)
		if (y)
			cout << x << ' ';
	cout << '\n';
}