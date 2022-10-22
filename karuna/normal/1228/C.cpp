#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
ll X, N;
vector<ll> p;

ll mypow(ll a, ll x) {
	ll ret = 1;
	while (x) {
		if (x&1) ret = (ret*a)%mod;
		a=(a*a)%mod; x/=2;
	}
	return ret;
}

int main() {
	cin >> X >> N;

	for (ll i=2; i*i<=X; i++) {
		if (X%i) continue;
		while (X%i==0) X/=i;
		p.push_back(i);
	}
	if (X!=1) p.push_back(X);

	ll ans = 1;
	for (ll q : p) {
		ll x = 0, cur = q;

		for (int i=0; i<100; i++) {
			x += N/cur;
			if (N/cur >= q) cur *= q;
			else break;
		}

		ans = ans*mypow(q, x)%mod;
	}

	cout << ans;
}