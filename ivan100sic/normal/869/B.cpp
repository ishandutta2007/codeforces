#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll leg(ll x, ll p) {
	ll sol = 0;
	while (x > 0) {
		sol += (x /= p);
	}
	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b;
	cin >> a >> b;

	ll f2 = leg(b, 2) - leg(a, 2);
	ll f5 = leg(b, 5) - leg(a, 5);

	if (f2 && f5) {
		cout << 0;
	} else {
		ll sol = 1;
		for (ll x=a+1; x<=b; x++) {
			sol *= x % 10;
			sol %= 10;
		}
		cout << sol;
	}

}