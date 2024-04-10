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

	ll n, d, z=0;
	cin >> n >> d;
	ll last = 0;
	while (n--) {
		ll x;
		cin >> x;
		if (x <= last) {
			ll t = (last-x) / d + 1;
			z += t;
			x += d*t;
		}
		last = x;
	}
	cout << z << '\n';
}