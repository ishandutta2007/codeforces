#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> divs[40005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=1; i<=40000; i++)
		for (int j=i; j<=40000; j+=i)
			divs[j] += i;

	int t;
	cin >> t;
	while (t--) {
		int a, b, c, sol = 1e9;
		cin >> a >> b >> c;
		tuple<int, int, int> vals;
		for (int x=1; x<=40000; x++) {
			int cost = abs(b - x);
			int my = 1e9, yy=-1;
			for (int y : divs[x]) {
				int my2 = abs(y - a);
				if (my2 < my) {
					my = my2;
					yy = y;
				}
			}

			int c1 = c / x * x;
			int c2 = c1 + x;
			int z = -1;

			if (abs(c1 - c) < abs(c2 - c)) {
				z = c1;
			} else {
				z = c2;
			}

			cost += my + min(abs(c1 - c), abs(c2 - c));

			if (cost < sol) {
				sol = cost;
				vals = {x, yy, z};
			}
		}
		cout << sol << '\n';
		auto [y, x, z] = vals;
		cout << x << ' ' << y << ' ' << z << '\n';
	}
}