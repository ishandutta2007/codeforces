#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> cnt(m);
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		cnt[t - 1]++;
	}
	ll ans = n * (n - 1) / 2;
	for (int i = 0; i < m; ++i) ans -= cnt[i] * (cnt[i] - 1) / 2;
	cout << ans << '\n';
}