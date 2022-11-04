#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int l, r, n; cin >> l >> r; n = r - l + 1;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	auto oa = a;
	int myboi = -1;
	for (int j = 1; j <= 18; ++j) {
		map<int, vector<int>> xd;
		for (int v : a) xd[v >> j].push_back(v);
		a.clear();
		for (auto [x, y] : xd) if (y.size() < 2) myboi = y[0];
		else a.push_back(y[0]);
		if (~myboi) break;
	}
	assert(~myboi);
	function<bool(int)> tr = [&] (int x) {
		vector<int> na(oa);
		for (int& v : na) v ^= x;
		sort(na.begin(), na.end());
		for (int i = l; i <= r; ++i) {
			if (na[i - l] != i) return false;
		}
		return true;
	};
	if (tr(l ^ myboi)) cout << (l ^ myboi) << "\n";
	else if (tr(r ^ myboi)) cout << (r ^ myboi) << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}