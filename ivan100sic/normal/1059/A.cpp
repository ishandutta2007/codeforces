#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, l, a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> l >> a;
	ll kraj = 0, sol = 0;
	for (ll i=0; i<n; i++) {
		ll t, w;
		cin >> t >> w;
		sol += (t - kraj) / a;
		kraj = t + w;
	}
	sol += (l - kraj) / a;
	cout << sol;
}