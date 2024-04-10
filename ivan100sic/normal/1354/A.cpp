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
		ll a, b, c, d;
		cin >> a >> b >> c >> d;

		if (a <= b) {
			cout << b << '\n';
		} else {
			a -= b;
			ll t = b;
			if (d >= c) {
				cout << "-1\n";
			} else {
				ll q = (a + (c-d) - 1) / (c - d);
				t += q * c;
				cout << t << '\n';
			}
		}
	}
}