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
	pr<int, int> a[m];
	bool nach[n];
	int b[n];
	int ans = 10000000;
	for (int i = 0; i < m; i++) {
		cin >> a[i].fs >> a[i].sc;
		ans = min(ans, a[i].sc - a[i].fs + 1);
	}
	for (int i = 0; i < n; i++) {
		nach[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		nach[a[i].fs] = 1;
	}
	for (int i = 0; i < n;) {
		for (int j = ans; j >= 1 && i < n; i++, j--) {
			b[i] = j - 1;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}
}