#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, w;
ll a[500005], b[500005], k;

bool moze(ll m) {
	ll z = 0, rem = k;
	copy(a, a+n, b);
	int l = -w, r = w;
	for (int i=max(0, l); i<=min(n-1, r); i++)
		z += b[i];
	for (int i=0; i<n; i++) {
		if (z < m) {
			ll d = m - z;
			if (d > rem)
				return false;
			rem -= d;
			z += d;
			b[min(r, n-1)] += d;
		}
		if (l >= 0)
			z -= b[l];
		l++;
		r++;
		if (r < n)
			z += b[r];
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> w >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	ll l = 0, r = 1.1e18, o = 0;
	while (l <= r) {
		ll m = (l+r) / 2;
		if (moze(m)) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << o << '\n';
}