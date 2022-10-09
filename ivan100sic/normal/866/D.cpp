#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

multiset<tuple<ll, ll, bool>> s;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		ll x;
		cin >> x;

		if (s.empty()) {
			s.insert({x, x, true});
			continue;
		}

		auto it = *s.begin();

		if (get<0>(it) < x) {
			s.erase(s.begin());
			s.insert({x, get<1>(it), false});

			if (!get<2>(it)) {
				s.insert({get<0>(it), get<0>(it), true});
			}
		} else {
			s.insert({x, x, true});
		}
	}

	ll sol = 0;
	for (auto p : s) {
		// cerr << p.first << ' ' << p.second << '\n';
		sol += get<0>(p) - get<1>(p);
	}

	cout << sol;
}