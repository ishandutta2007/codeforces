// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, m, i, j, a, b;

	cin >> n >> m >> i >> j >> a >> b;

	auto determine = [](int a, int b, int d, int w) {
		if (a < b) return d;
		if (a > b) return -d;
		if (a + d <= w)
			return d;
		return -d;
	};

	auto ok = [&](int x, int y) {
		return clamp(x, 1, n) == x && clamp(y, 1, m) == y;
	};

	const int inf = 1123123;
	int s = inf;

	for (int u : {1, n}) {
		for (int v : {1, m}) {
			int x = i, y = j;
			int t = 0;
			while (x != u || y != v) {
				int dx = determine(x, u, a, n);
				int dy = determine(y, v, b, m);

				x += dx;
				y += dy;

				if (!ok(x, y) || t > inf) {
					t = inf;
					break;
				}

				t++;
			}

			s = min(s, t);
		}
	}

	if (s == inf) {
		cout << "Poor Inna and pony!\n";
	} else {
		cout << s << '\n';
	}
}