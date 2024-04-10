// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		basic_string<ll> a(n, 0);
		iota(begin(a), end(a), 1);

		vector<pair<ll, ll>> sol;

		while (a.size() > 1) {
			ll x = a.back();
			ll y = a[a.size() - 2];
			sol.emplace_back(x, y);
			a.pop_back();
			a.back() = (x+y+1) / 2;
		}

		cout << a[0] << '\n';
		for (auto [x, y] : sol) {
			cout << x << ' ' << y << '\n';
		}
	}
}