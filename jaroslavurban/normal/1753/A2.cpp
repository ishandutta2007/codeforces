#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	int sm = accumulate(a.begin(), a.end(), 0);
	vector<pair<int, int>> res;
	int l = 0, i = 1;
	while (sm != 0 && i < n) {
		if (abs(sm - 2 * a[i]) < abs(sm)) {
			while (l < i - 1) { res.push_back({l, l}); ++l; }
			res.push_back({l, i});
			sm -= 2 * a[i];
			l += 2;
			i += 2;
		} else ++i;
	}
	while (l < n) { res.push_back({l, l}); ++l; }
	if (sm == 0) {
		cout << res.size() << '\n';
		for (auto [l, r] : res) cout << l + 1 << ' ' << r + 1 << '\n';
	} else cout << "-1\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}