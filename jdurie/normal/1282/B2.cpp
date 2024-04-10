#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll a[200010];

bool works(ll m, ll k, ll p) {
	ll sum = 0;
	for(ll i = 0; i < m % k; i++) sum += a[i];
	for(ll i = m - 1; i >= m % k; i -= k) sum += a[i];
	return sum <= p;
}

ll bSearch(ll l, ll r, ll k, ll p) {
	if(l == r) return l;
	ll m = (l + r + 1) / 2;
	return works(m, k, p) ? bSearch(m, r, k, p) : bSearch(l, m - 1, k, p);
}

vector<ll> anss;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll T; cin >> T;
	while(T--) {
		ll n, p, k, c, j;
		cin >> n >> p >> k;
		c = p;
		for(ll i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		for(j = 0; (j + 1) * k <= n; j++) {
			if(a[k * (j + 1) - 1] > c) break;
			c -= a[k * (j + 1) - 1];
		}
		anss.push_back(a[0] > p ? 0 : bSearch(k * j, min(k * (j + 1) - 1, n), k, p));
	}
	for(ll ans : anss) cout << ans << endl;
}