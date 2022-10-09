#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, s, v[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (int i=0; i<n; i++)
		cin >> v[i];

	ll l = 0, r = 1e9, o = -1;
	while (l <= r) {
		ll m = (l+r) >> 1, z = 0, ok = 1;
		for (ll i=0; i<n; i++) {
			if (v[i] - m < 0)
				ok = 0;
			else
				z += v[i] - m;
		}
		if (z >= s && ok) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << o << '\n';
}