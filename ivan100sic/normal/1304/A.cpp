// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll x, y, a, b;
		cin >> x >> y >> a >> b;

		y -= x;
		a += b;

		if (y % a == 0) {
			cout << y/a << '\n';
		} else {
			cout << "-1\n";
		}
	}
}