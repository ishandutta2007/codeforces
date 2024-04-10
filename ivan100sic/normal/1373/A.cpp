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
		ll a, b, c;
		cin >> a >> b >> c;
		if (a < c) {
			cout << "1 ";
		} else {
			cout << "-1 ";
		}

		if (c < a*b) {
			cout << b << '\n';
		} else {
			cout << "-1\n";
		}
	}
}