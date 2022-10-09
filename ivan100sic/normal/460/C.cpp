#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, w;
ll a[100005];
ll z[100005];

bool moze(ll x) {
	ll cost = 0;
	memset(z, 0, sizeof(z));
	for (int i=0; i<n; i++) {
		ll h = a[i] + z[i];
		ll r = max(x - h, 0ll);
		cost += r;
		z[i] += r;
		if (i+w <= n)
			z[i+w] -= r;
		z[i+1] += z[i];
	}
	return cost <= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> w;
	for (int i=0; i<n; i++)
		cin >> a[i];

	int l = 0, r = 1e9 + 1e6, o = -1;
	while (l <= r) {
		int x = (l+r) >> 1;
		if (moze(x)) {
			o = x;
			l = x + 1;
		} else {
			r = x - 1;
		}
	}
	cout << o << '\n';
}