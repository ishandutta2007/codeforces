#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;

	ll parovi = n - 2*m;
	if (parovi < 0)
		parovi = 0;

	ll maxv = -1;
	for (ll i=0; i<n; i++) {
		if (m > 0) {
			m -= min(m, i);
			maxv = max(maxv, i);
		}
	}

	cout << parovi << ' ' << n - maxv - 1 << '\n';
}