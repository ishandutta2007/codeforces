#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
int v[100005];
int c[100005];

ll mx[100005];
int h1, h2;

ll resi(ll a, ll b) {
	fill(mx+1, mx+n+1, -123123123123123123ll);
	h1 = 1;
	h2 = 2;
	ll sol = 0;
	for (int i=1; i<=n; i++) {
		ll drugi;
		if (c[i] == h1) {
			drugi = mx[h2];
		} else {
			drugi = mx[h1];
		}

		ll w = max({b * v[i], mx[c[i]] + a * v[i], drugi + b * v[i]});
		sol = max(sol, w);

		if (c[i] == h1) {
			// nista
		} else if (c[i] == h2) {
			// preskace h1?
			if (w > mx[h1]) {
				swap(h1, h2);
			}
		} else {
			if (w > mx[h1]) {
				h2 = h1;
				h1 = c[i];
			} else if (w > mx[h2]) {
				h2 = c[i];
			}
		}

		mx[c[i]] = max(mx[c[i]], w);
	}
	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> v[i];
	for (int i=1; i<=n; i++)
		cin >> c[i];

	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << resi(a, b) << '\n';
	}
}