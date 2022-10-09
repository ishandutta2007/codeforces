// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d, x, y, x1, y1, x2, y2;
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;

		bool ok = true;

		int u = x + b - a;
		int v = y + d - c;
		ok &= clamp(u, x1, x2) == u;
		ok &= clamp(v, y1, y2) == v;

		if (x1 == x2)
			ok &= a + b == 0;
		if (y1 == y2)
			ok &= c + d == 0;

		cout << (ok ? "Yes\n" : "No\n");
	}
}

// I will still practice daily...