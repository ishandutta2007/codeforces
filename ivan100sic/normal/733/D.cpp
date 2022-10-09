#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<pair<int, int>, pair<int, int>> m;

int min3(int a, int b, int c) {
	return min(a, min(b, c));
}

int main() {
	int n, r0 = 0, i0, j0;
	cin >> n;
	for (int i=1; i<=n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a > b) swap(a, b);
		if (a > c) swap(a, c);
		if (b > c) swap(b, c);

		{
			int r = min3(a, b, c);
			if (r > r0) {
				r0 = r;
				i0 = i;
				j0 = 0;
			}
		}

		{
			int d = m[{a, b}].first;
			if (d > 0) {
				int r = min3(a, b, c+d);
				if (r > r0) {
					r0 = r;
					i0 = m[{a, b}].second;
					j0 = i;
				}
			}
		}

		{
			int d = m[{a, c}].first;
			if (d > 0) {
				int r = min3(a, c, b+d);
				if (r > r0) {
					r0 = r;
					i0 = m[{a, c}].second;
					j0 = i;
				}
			}
		}

		{
			int d = m[{b, c}].first;
			if (d > 0) {
				int r = min3(b, c, a+d);
				if (r > r0) {
					r0 = r;
					i0 = m[{b, c}].second;
					j0 = i;
				}
			}
		}

		if (c > m[{a, b}].first) {
			m[{a, b}] = {c, i};
		}

		if (b > m[{a, c}].first) {
			m[{a, c}] = {b, i};
		}

		if (a > m[{b, c}].first) {
			m[{b, c}] = {a, i};
		}
	}

	if (j0 == 0) {
		cout << "1\n" << i0;
	} else {
		cout << "2\n" << i0 << ' ' << j0 << '\n';
	}
}