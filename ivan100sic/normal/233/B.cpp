#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll s(ll x) {
	ll y = 0;
	while (x > 0) {
		y += x % 10;
		x /= 10;
	}
	return y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n;
	cin >> n;
	ll r = sqrt(n) + 3;
	for (ll x=max(0ll, r-10000); x<=r; x++) {
		if (x*x + x*s(x) == n) {
			cout << x << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}