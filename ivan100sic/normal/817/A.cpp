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

	ll a, b, c, d, x, y;
	cin >> a >> b >> c >> d >> x >> y;
	if ((a-c) % x == 0 && (b-d) % y == 0) {
		ll p = (a-c) / x;
		ll q = (b-d) / y;
		if ((p+q) % 2 == 0) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
}