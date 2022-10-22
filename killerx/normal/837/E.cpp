#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll a, b; cin >> a >> b;
	ll ans = 0;
	while (b) {
		ll d = __gcd(a, b);
		a /= d; b /= d;
		if (a == 1) {
			ans += b;
			break;
		}
		vector <ll> v;
		ll x = a;
		for (ll i = 2; i * i <= x; ++ i) {
			if (x % i == 0) {
				v.push_back(i);
				while (x % i == 0) x /= i;
			}
		}
		if (x > 1) v.push_back(x);
		ll mn = 0x3f3f3f3f3f3f3f3f;
		for (int i = 0; i < v.size(); ++ i) {
			mn = min(mn, b % v[i]);
		}
		ans += mn;
		b -= mn;
	}
	printf("%lld\n", ans);
	return 0;
}