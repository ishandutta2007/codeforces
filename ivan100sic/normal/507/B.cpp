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

	ll r, x, y, xt, yt;
	cin >> r >> x >> y >> xt >> yt;
	x -= xt;
	y -= yt;

	// 0?
	if (x*x + y*y == 0) {
		cout << "0\n";
		return 0;
	}

	cerr << r << ' ' << x << ' ' << y << '\n';

	// 1?
	if (x*x+y*y <= 4*r*r) {
		cout << "1\n";
		return 0;
	}

	// greedy
	for (ll t=1; t<=400000; t++) {
		if (x*x+y*y <= 4*t*t*r*r) {
			cout << t << '\n';
			return 0;
		}
	}
		
}