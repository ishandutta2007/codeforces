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

	int t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;

		ll f = 0;
		f += (2*l-1) * (l % 2 ? -1 : 1);
		f += (2*r+1) * (r % 2 ? -1 : 1);
		cout << f / 4 << '\n';
	}
}