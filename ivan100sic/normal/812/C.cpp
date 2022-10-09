#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, s, suma;
ll a[100005];

bool moze(ll k) {
	vector<ll> b;
	for (ll i=0; i<n; i++) {
		b.push_back(a[i] + (i + 1) * k);
	}
	sort(b.begin(), b.end());
	suma = accumulate(b.begin(), b.begin() + k, 0ll);

	return suma <= s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	ll lo = 0, hi = n, o = 0;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (moze(mid)) {
			o = mid;
			lo = mid + 1;
		} else { 
			hi = mid-1;
		}
	}

	/*
	for (ll i=0; i<=n; i++) {
		moze(i);
		cerr << i << ' ' << suma << '\n';
	}*/

	moze(o);

	cout << o << ' ' << suma;
}