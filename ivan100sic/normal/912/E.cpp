#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, p[16];
ll k;

ll ofmul(ll a, ll b) {
	if (a * 1.0 * b > 4e18) {
		return 3e18;
	}
	return a*b;
}

void generisi(vector<int> p, vector<ll>& a) {
	set<ll> sk;

	sk.insert(1);

	ll last = -1;

	while (last < 1.1e18) {
		last = *sk.begin();
		sk.erase(last);
		a.push_back(last);

		for (int pr : p) {
			sk.insert(ofmul(last, pr));
		}
	}
}

vector<int> p1, p2;
vector<ll> a, b;

ll soll(ll x) {

	ll sol = 0;

	for (ll y : a) {
		sol += upper_bound(b.begin(), b.end(), x/y) - b.begin();
	}

	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> p[i];
	}
	cin >> k;

	for (int i=0; i<n; i++) {
		if (__builtin_popcount(i) % 2) {
			p1.push_back(p[i]);
		} else {
			p2.push_back(p[i]);
		}
	}

	generisi(p1, a);
	generisi(p2, b);

	ll l = 0, r = 1.1e18, m, o = -1;

	while (l <= r) {
		m = (l+r) / 2;

		ll vr = soll(m);

		cerr << m << ' ' << vr << '\n';

		if (vr < k) {
			l = m+1;
		} else {
			r = m-1;
			o = m;
		}
	}

	cout << o;
}