#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, k, p;
ll a[1005], b[2005];

bool moze(ll x) {
	ll h = 0;
	for (ll i=0; i<n; i++) {
		if (h == k)
			return false;
		bool sat = false;
		while (h < k) {
			ll d = abs(a[i] - b[h]) + abs(b[h] - p);
			h++;
			if (d <= x) {
				sat = true;
				break;
			}
		}
		if (!sat)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> p;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<k; i++)
		cin >> b[i];

	sort(a, a+n);
	sort(b, b+k);

	ll l = 0, r = 4e9, o = -1;
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (moze(m)) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << o << '\n';
}