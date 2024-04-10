#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m; cin >> n >> m;
	vector<bool> have(m + 1);
	for (int v, i = 0; i < n; ++i) cin >> v, have[v] = true;
	int nhave = accumulate(have.begin(), have.end(), 0);
	vector<int> mx(m + 1);
	int res = INT_MAX;
	multiset<int> mxs;
	if (have[1]) {
		mxs.insert(1);
		if (nhave == 1) res = 0;
	}
	auto upd = [&] (int i, int v) {
		if (mx[i] >= v) return;
		if (have[i] && mx[i]) mxs.erase(mxs.find(mx[i]));
		if (have[i]) mxs.insert(v);
		mx[i] = v;
	};
	for (int d = 2; d <= m; ++d) {
		upd(d, d);
		for (int i = 2; i * d <= m; ++i) upd(i * d, mx[i]);
		if (mxs.size() == nhave) res = min(res, d - *mxs.begin());
	}
	cout << res << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}