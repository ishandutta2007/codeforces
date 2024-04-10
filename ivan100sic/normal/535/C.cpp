#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a, b, n;

bool moze(ll l, ll r, ll t, ll m) {
	ll sum = (r-l+1) * (2*a + b*(r+l-2)) / 2;
	ld sum_real = (r-l+(ld)1) * ((ld)2*a + b*(r+l-(ld)2)) / 2;

	return sum_real <= m*t*1.01 && sum <= m*t && a+(r-1)*b <= t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b >> n;
	while (n--) {
		ll l, t, m;
		cin >> l >> t >> m;

		ll lo = l, hi = 1e13, o = -1;
		while (lo <= hi) {
			ll mid = (lo + hi) >> 1;
			if (moze(l, mid, t, m)) {
				o = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		cout << o << '\n';
	}	
}