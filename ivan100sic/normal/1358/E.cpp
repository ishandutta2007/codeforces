// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll a[500005], n, h, x;
ll bad[500005];

void ans(ll x) {
	cout << x << '\n';
	exit(0);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	h = (n+1) / 2;
	for (int i=0; i<h; i++)
		cin >> a[i];
	cin >> x;

	bad[1]++;
	bad[n/2+1]--;

	ll z = 0;
	for (int i=h-1; i>=0; i--) {
		z += a[i];

		ll klo = n/2 + 1;
		ll khi = n - i;

		auto vr = [&](ll k) {
			return z + (k - (h - i)) * x > 0;
		};

		if (vr(klo) && vr(khi)) {
			//
		} else if (!vr(klo) && !vr(khi)) {
			bad[klo]++;
			bad[khi+1]--;
		} else {
			ll lo = klo + 1, hi = khi, o = klo;
			while (lo <= hi) {
				ll mid = (lo + hi) / 2;
				if (vr(mid) == vr(klo)) {
					o = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			if (vr(klo)) {
				bad[o+1]++;
				bad[khi+1]--;
				khi = o;
			} else {
				bad[klo]++;
				bad[o+1]--;
			}
		}
	}

	for (ll i=1, t=0; i<=n; i++) {
		t += bad[i];
		if (!t) {
			ans(i);
		}
	}

	ans(-1);
}