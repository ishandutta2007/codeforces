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
		ll x, y, n;
		cin >> x >> y >> n;
		n -= (n - y) % x;
		cout << n << '\n';
	}
}