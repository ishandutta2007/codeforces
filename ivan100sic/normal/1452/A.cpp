// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll f(ll x) {
	x = abs(x);
	if (x <= 1) return 0;
	return x-1;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		cout << x + y + f(x-y) << '\n';
	}
}