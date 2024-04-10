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

	ll n, l, r;
	cin >> n >> l >> r;

	ll p = 0, q = 0;
	for (ll i=0; i<n; i++) {
		p += i < l ? 1 << i : 1;
		q += 1 << min(r-1, i);
	}
	cout << p << ' ' << q << '\n';
}