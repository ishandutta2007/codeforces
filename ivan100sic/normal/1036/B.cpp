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

	int q;
	cin >> q;
	while (q--) {
		ll x, y, k;
		cin >> x >> y >> k;
		if (max(x, y) > k) {
			cout << "-1\n";
			continue;
		}

		if (x%2 == y%2) {
			if (x%2 == k%2)
				cout << k << '\n';
			else
				cout << k-2 << '\n';
		} else {
			cout << k-1 << '\n';
		}
	}
}