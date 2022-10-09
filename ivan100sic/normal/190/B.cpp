#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll sq(ll x) { return x*x; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	cout.precision(20);
	cout << fixed;

	ll d2 = sq(x1-x2) + sq(y1-y2);

	if (d2 > sq(r1 + r2)) {
		// ne dodiruju se
		cout << (sqrt(d2) - r1 - r2) / 2;
	} else if (r1 < r2 && d2 < sq(r2-r1)) { // prvi je u drugom
		cout << ((r2 - r1) - sqrt(d2)) / 2;
	} else if (r2 < r1 && d2 < sq(r1-r2)) { // drugi je u prvom
		cout << ((r1 - r2) - sqrt(d2)) / 2;
	} else {
		// seku se
		cout << "0\n";
	}
}