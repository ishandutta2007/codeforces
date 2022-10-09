#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	while (a) {
		ll t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());
	ll gore = a[0];
	for (int i=1; i<n; i++) {
		gore += a[i];
		gore += (a[i] - a[i-1]) * i * 2ll * (n - i);
	}
	ll g = gcd(gore, n);
	cout << gore/g << ' ' << n/g << '\n';
}