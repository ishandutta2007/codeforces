#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<ll> gen(ll n, ll l, ll r, ll x, ll y, ll z, ll b1, ll b2) {
	vector<ll> b(n);
	b[0] = b1;
	b[1] = b2;
	for (int i=2; i<n; i++) {
		b[i] = (b[i-2] * x + b[i-1] * y + z) & 0xffffffffll;
	}
	for (int i=0; i<n; i++) {
		b[i] = (b[i] % (r-l+1)) + l;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		ll n, l, r, x, y, z, b1, b2;
		cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
		auto a = gen(n, l, r, x, y, z, b1, b2);

		const ll INF = 8123123123123123123ll;

		ll sol = INF;
		ll low_svih = INF;

		// sva resenja gde je desni broj pozitivan
		for (ll i=0; i<n; i++) {
			if (a[i] >= 0 && low_svih < a[i]) {
				sol = min(sol, low_svih * a[i]);
			}
			low_svih = min(low_svih, a[i]);
		}

		// sva resenja gde su oba broja negativna
		vector<ll> b;
		b.reserve(n);
		for (ll i=0; i<n; i++) {
			if (a[i] < 0)
				b.push_back(-a[i]);
		}
		reverse(b.begin(), b.end());
		// sad resi zadatak normalno opet

		low_svih = INF;

		// sva resenja gde je desni broj pozitivan
		for (ll i=0; i<(ll)b.size(); i++) {
			if (b[i] >= 0 && low_svih < b[i]) {
				sol = min(sol, low_svih * b[i]);
			}
			low_svih = min(low_svih, b[i]);
		}

		if (sol == INF) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << sol << '\n';
		}
	}
}