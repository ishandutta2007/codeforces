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
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		int summ = 0;
		for (int i1 = l - 1; i1 < r; i1++) {
			summ += a[i1];
		}
		if (summ >= 0) {
			ans += summ;
		}
	}
	cout << ans;
}