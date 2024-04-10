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
		ll x, y, k;
		cin >> x >> y >> k;

		ll tsticks = y*k + k;
		ll c = (tsticks - 1 + (x - 2)) / (x - 1);
		cout << c + k << '\n';
	}
}