#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll phi(ll x) {
	ll ret = 1, t = x;
	for (ll i=2; i*i<=x; i++) {
		if (t%i) continue;
		ret = ret*(i-1), t /= i;
		while (t%i==0) ret = ret*i, t /= i;
	}
	if (t != 1) ret = ret * (t-1);
	return ret;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		ll x, y; cin >> x >> y;
		ll g = __gcd(x, y);
		cout << phi(y/g) << '\n';
	}
}