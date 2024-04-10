#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll a[200010];

bool works(ll m, ll p) {
	ll sum = 0;
	for(ll i = !(m % 2); i < m; i += 2) sum += a[i];
	return sum <= p;
}

ll bSearch(ll l, ll r, ll p) {
	if(l == r) return l;
	ll m = (l + r + 1) / 2;
	return works(m, p) ? bSearch(m, r, p) : bSearch(l, m - 1, p);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll T; cin >> T;
	while(T--) {
		ll n, p, k, ans = 0;
		cin >> n >> p >> k;
		for(ll i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		cout << (a[0] > p ? 0 : bSearch(1, n, p)) << endl;
	}
}