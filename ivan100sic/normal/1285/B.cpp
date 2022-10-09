#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[100005];

ll resi(vector<ll> a) {
	ll h = -1e18, d = 0, c = 0;
	for (ll x : a) {
		h = max(h, x);
		c = max(0ll, c+x);
		d = max(d, c);
	}
	if (h < 0)
		return h;
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> a[i];
		ll u = accumulate(a, a+n, 0ll);
		ll v = max(resi(vector<ll>(a, a+n-1)), resi(vector<ll>(a+1, a+n)));
		cout << (u > v ? "YES\n" : "NO\n");
	}
}