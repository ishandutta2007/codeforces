#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[100005], b[100005];

ll cost(ll x) {
	// povecaj a
	ll z = 0;
	for (int i=0; i<n; i++)
		z += max(0ll, x - a[i]);
	for (int i=0; i<m; i++)
		z += max(0ll, b[i] - x);
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll x = 0, step = 1ll << 32;

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<m; i++)
		cin >> b[i];

	ll xcost = cost(x);

	for (int i=0; i<34; i++) {
		ll l = x - step;
		ll r = x + step;

		ll lcost = cost(l);
		ll rcost = cost(r);

		if (lcost == min({lcost, rcost, xcost})) {
			xcost = lcost;
			x = l;
		} else if (rcost == min({lcost, rcost, xcost})) {
			xcost = rcost;
			x = r;
		}

		step >>= 1;
		if (step == 0)
			step = 1;
	}

	cout << xcost << '\n';
}