#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int l, r, n; cin >> l >> r; n = r - l + 1;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	int res = 0;
	for (int j = 0; j < 17; ++j) {
		int odd = 0, eodd = 0;
		for (int i = 0; i < n; ++i) odd += !!(a[i] & (1 << j));
		for (int i = l; i <= r; ++i) eodd += !!(i & (1 << j));
		if (odd != eodd) res ^= 1 << j;
	}
	cout << res << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}