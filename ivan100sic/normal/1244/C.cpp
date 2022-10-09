// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

	ll n, p, w, d;
	cin >> n >> p >> w >> d;

	for (ll y=0; y<=1234567; y++) {
		ll x = (p - y*d) / w;
		ll z = n - x - y;
		if (min(x, z) >= 0 && ld(x)*w + ld(y)*d == p) {
			cout << x << ' ' << y << ' ' << z << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}

// I will still practice daily...