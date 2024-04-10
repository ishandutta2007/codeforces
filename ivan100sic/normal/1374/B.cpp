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
		ll x;
		int m = 0;
		cin >> x;
		while (x % 3 == 0) {
			if (x % 6 == 0) {
				x /= 6;
			} else {
				x *= 2;
			}
			m++;
		}

		if (x != 1)
			m = -1;

		cout << m << '\n';
	}
}