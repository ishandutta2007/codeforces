#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n), r;
	for (int& v : a) cin >> v;
	if (n & 1) { cout << "NO\n"; return; }
	sort(a.begin(), a.end());
	for (int i = 0; i < n / 2; ++i) {
		r.push_back(a[i]);
		r.push_back(a[i + n / 2]);
	}
	for (int i = 0; i < n; ++i) {
		int j = (i - 1 + n) % n, k = (i + 1) % n;
		bool good = (r[j] > r[i] && r[i] < r[k]) || (r[j] < r[i] && r[i] > r[k]);
		if (!good) { cout << "NO\n"; return; }
	}
	cout << "YES\n";
	for (int v : r) cout << v << ' '; cout << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}