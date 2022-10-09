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

	ll x, d;
	cin >> x >> d;

	ll prev = 1;
	basic_string<ll> sol;

	while (x > 0) {
		ll k = 1;
		while ((1ll << (k + 1)) - 1 <= x)
			k++;

		x -= (1ll << k) - 1;
		for (int i=1; i<=k; i++)
			sol += prev;
		prev += d+1;
	}

	cout << sol.size() << '\n';
	for (ll x : sol)
		cout << x << ' ';
	cout << "\n";
}