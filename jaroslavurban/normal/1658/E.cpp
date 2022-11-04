#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, k; cin >> n >> k;
	vector<tuple<int, int, int>> a(n * n);
	for (int v, i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v, a[n * i + j] = {v, i, j};
	sort(a.rbegin(), a.rend());
	array<int, 4> r = {0, n + n, -n, n};
	vector<string> res(n, string(n, 'G'));
	auto chck = [&] (int i, int j) {
		if (i + j < r[0] || i + j > r[1] || i - j < r[2] || i - j > r[3]) return false;
		r[0] = max(r[0], i + j - k);
		r[1] = min(r[1], i + j + k);
		r[2] = max(r[2], i - j - k);
		r[3] = min(r[3], i - j + k);
		return true;
	};
	for (auto [v, i, j] : a) if (chck(i, j)) res[i][j] = 'M';
	for (auto s : res) cout << s << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}