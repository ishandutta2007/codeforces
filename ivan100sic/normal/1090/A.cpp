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

	ll n;
	cin >> n;
	vector<pair<ll, ll>> a(n);
	for (int i=0; i<n; i++) {
		ll x, z = 0;
		cin >> x;
		for (int j=0; j<x; j++) {
			ll y;
			cin >> y;
			z = max(z, y);
		}
		a[i] = {z, x};
	}
	ll h = max_element(a.begin(), a.end())->first;
	ll s = 0;
	for (int i=0; i<n; i++) {
		s += a[i].second * (h - a[i].first);
	}
	cout << s << '\n';
}