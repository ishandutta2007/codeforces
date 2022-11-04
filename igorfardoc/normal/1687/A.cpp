#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;

ll sum(int l, int r) {
	ll res = (ll)r * (r + 1) / 2;
	res -= (ll)l * (l - 1) / 2;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vi a(n);
		vl pref(n + 1);
		pref[0] = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			pref[i + 1] = pref[i] + a[i];
		}
		if(k >= n) {
			ll ans = pref[n] + (ll)k * n - sum(1, n);
			cout << ans << '\n';
			continue;
		}
		ll ans = 0;
		for(int i = 0; i < n - k + 1; i++) {
			ans = max(ans, pref[i + k] - pref[i]);
		}
		ans += (ll)k * k - sum(1, k);
		cout << ans << '\n';
	}
}