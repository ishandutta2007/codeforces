#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k, p;
ll a[100005], h[100005];
const ll inf = 4e18;

ll pri(ll x, ll i) {
	ll tod = m - x/a[i];
	if (tod <= 0) { // check?
		return -inf + h[i] - (x - m*a[i]);
	} else {
		return tod;
	}
}

bool moze(ll sol) {
	priority_queue<array<ll, 3>> s;
	for (int i=0; i<n; i++) {
		s.push({pri(sol, i), sol, i});
	}
	for (int i=m-1; i>=0; i--) {
		for (int rep=0; rep<k; rep++) {
			auto [t, x, j] = s.top(); s.pop();
			if (t > i)
				return 0;
			x += p;
			s.push({pri(x, j), x, j});
		}
	}

	auto [t, x, j] = s.top();
	return t <= -inf;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k >> p;
	for (int i=0; i<n; i++)
		cin >> h[i] >> a[i];

	ll l = 0, r = 2e18, o = -1;
	while (l <= r) {
		ll m = (l+r) / 2;
		if (moze(m)) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << o << '\n';
}