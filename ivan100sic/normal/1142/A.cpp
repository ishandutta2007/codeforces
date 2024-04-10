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

	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	set<ll> ra, rb;

	ra.insert(a);
	ra.insert((k-a) % k);

	rb.insert(b);
	rb.insert((k-b) % k);

	ll lo = 123123123123ll, hi = -123123123123ll;

	for (ll l=-2; l<=n+3; l++) {
		for (ll ar : ra) {
			for (ll br : rb) {
				ll d = l*k + br-ar;
				if (d > 0) {
					ll w = n*k / gcd(n*k, d);
					lo = min(lo, w);
					hi = max(hi, w);
				}
			}
		}
	}

	cout << lo << ' ' << hi << '\n';
}