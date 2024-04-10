#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void wht(vector<ll>& a, int n) {
	for (int mask=1; mask<(1 << n); mask<<=1) {
		for (int i=0; i<(1 << n); i++) {
			if (i & mask) {
				int j = i - mask;
				ll u = a[j], v = a[i];
				a[j] = u + v;
				a[i] = u - v;
			}
		}
	}
}

void wht_i(vector<ll>& a, int n) {
	for (int mask=1; mask<(1 << n); mask<<=1) {
		for (int i=0; i<(1 << n); i++) {
			if (i & mask) {
				int j = i - mask;
				ll u = a[j], v = a[i];
				a[j] = (u + v) >> 1;
				a[i] = (u - v) >> 1;
			}
		}
	}
}

int n, m;
string s[20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];

	vector<ll> a(1 << n, 0);

	for (int i=0; i<m; i++) {
		int mask = 0;
		for (int j=0; j<n; j++)
			mask += (int)(s[j][i] == '1') << j;
		a[mask]++;
	}

	wht(a, n);

	vector<vector<ll>> b(n + 1);

	for (int i=0; i<=n; i++)
		b[i].resize(1 << n);

	for (int i=0; i<(1<<n); i++)
		b[__builtin_popcount(i)][i]++;

	for (int i=0; i<=n; i++) {
		wht(b[i], n);
		for (int j=0; j<(1<<n); j++)
			b[i][j] *= a[j];
		wht_i(b[i], n);
	}

	ll sol = 1123123123123123123ll;

	for (int i=0; i<(1<<n); i++) {
		ll z = 0;
		for (int j=0; j<=n; j++) {
			ll x = min(j, n-j);
			z += x * b[j][i];
		}
		sol = min(sol, z);
	}

	cout << sol << '\n';
}