#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;

main() {
	ios_base::sync_with_stdio(0);
	int n, x;
	cin >> n >> x;
	int a[n];
	map<int, int> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		k[a[i]]++;
	}
	if (x == 0) {
		int ans = 0;
		for (auto v : k) {
			ans += v.sc * (v.sc - 1) / 2;
		}
		cout << ans;
		return 0;
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += k[a[i] ^ x];
	}
	cout << ans / 2;
}