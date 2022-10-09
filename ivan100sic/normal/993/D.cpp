#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[55], b[55];
ll c[55];

bool moze() {
	map<int, vector<ll>> cene;
	vector<ll> ol(100, -1e18);
	ol[0] = 0;
	for (int i=0; i<n; i++)
		cene[-a[i]].push_back(c[i]);
	for (auto [p, v] : cene) {
		sort(v.begin(), v.end(), greater<ll>());
		vector<ll> z(v.size() + 1);
		for (int i=0; i<(int)v.size(); i++)
			z[i+1] = z[i] + v[i];
		vector<ll> nu(100, -1e18);
		for (int i=0; i<=(int)v.size(); i++) {
			int j = v.size() - i;
			for (int k=max(0, j-i); k<=min(99, 99-i+j); k++) {
				if (j > k)
					continue;
				nu[k+i-j] = max(nu[k+i-j], ol[k] + z[i]);
			}
		}
		swap(ol, nu);
	}
	for (int i=0; i<100; i++)
		if (ol[i] >= 0)
			return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	ll l = 0, r = 100'000'000'000ll, o = 0;
	while (l <= r) {
		ll m = (l+r) / 2;
		for (int i=0; i<n; i++)
			c[i] = m*b[i] - a[i]*1000ll;
		if (moze()) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	cout << o << '\n';
}