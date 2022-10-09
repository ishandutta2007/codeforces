// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, k;
ll a[100005], b[100005], c[100005], d[100005], e[100005];

ll take_grad(ll a, ll g) {
	ll l = 1, r = a, o = 0;
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (-1+a+3*m-3*m*m >= g) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return o;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];

	ll l = -4e18, r = 4e18;
	copy(a, a+n, d);
	while (l <= r) {
		ll m = (l+r) / 2;
		// najvisi gradijent koji cemo da dozvolimo
		ll took = 0;
		for (int i=0; i<n; i++) {
			took += (b[i] = take_grad(a[i], m));
		}
		if (took <= k) {
			copy(b, b+n, c);
			r = m - 1;
		} else {
			copy(b, b+n, d);
			l = m + 1;
		}
	}

	ll rem = k;
	for (int i=0; i<n; i++) {
		e[i] = c[i];
		rem -= e[i];
	}

	for (int i=0; i<n; i++) {
		ll f = min(rem, d[i] - c[i]);
		rem -= f;
		cout << e[i] + f << " \n"[i == n-1];
	}

}