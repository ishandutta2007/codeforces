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
		ll a, b;
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}

		if (b % a) {
			cout << "-1\n";
			continue;
		}

		ll w = b / a;
		ll z = 0;
		while (w % 2 == 0) {
			w >>= 1;
			z++;
		}

		if (w != 1) {
			cout << "-1\n";
			continue;
		}

		cout << (z+2)/3 << '\n';
	}
}