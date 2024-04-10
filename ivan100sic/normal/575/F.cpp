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

	ll n, x, z = 0;
	cin >> n >> x;
	ll l = x, r = x;
	while (n--) {
		ll u, v;
		cin >> u >> v;
		if (u > r) {
			z += u-r;
			l = r;
			r = u;
		} else if (l > v) {
			z += l-v;
			r = l;
			l = v;
		} else {
			l = max(l, u);
			r = min(r, v);
		}
	}
	cout << z << '\n';
}