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
	int n, s;
	cin >> n >> s;
	s--;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0 && i != s) {
			a[i] = n;
		}
	}
	int kon = n;
	int tek = 0;
	int ans = 0;
	if (a[s] != 0) {
		ans++;
		a[s] = 0;
	}
	sort(a, a + n);
	for (int i = 1; i < kon; i++) {
		if (a[i] - tek > 1) {
			for (; tek < a[i] - 1 && kon > i; kon--, tek++, ans++) {
			}
		}
			tek = a[i];
	}
	cout << ans;
}