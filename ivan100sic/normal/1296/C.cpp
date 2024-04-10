// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

pair<int, int> p(char c) {
	if (c == 'L') return {-1, 0};
	if (c == 'R') return {+1, 0};
	if (c == 'U') return {0, +1};
	if (c == 'D') return {0, -1};
	return {0, 0};
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string st;
		cin >> st;

		map<pair<int, int>, int> f;
		f[{0, 0}] = 0;
		int x=0, y=0, s=123123123, l=0, xl, xr;
		for (char c : st) {
			auto [u, v] = p(c);
			x += u;
			y += v;
			l++;
			if (f.count({x, y})) {
				int k = l - f[{x, y}];
				if (k < s) {
					s = k;
					xl = f[{x, y}];
					xr = l;
				}
			}
			f[{x, y}] = l;
		}

		if (s == 123123123) {
			cout << "-1\n";
		} else {
			cout << xl+1 << ' ' << xr << '\n';
		}
	}
}