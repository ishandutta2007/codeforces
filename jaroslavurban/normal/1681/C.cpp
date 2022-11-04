#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int& v : a) cin >> v;
	for (int& v : b) cin >> v;
	vector<pair<int, int>> res;
	for (int i = 0; i < n - 1; ++i) {
		int mna = *min_element(a.begin() + i, a.end());
		int mnb = *min_element(b.begin() + i, b.end());
		bool found = false;
		for (int j = i; j < n; ++j) if (a[j] == mna && b[j] == mnb) {
			found = true;
			if (j != i) res.push_back({i, j});
			swap(a[i], a[j]);
			swap(b[i], b[j]);
			break;
		}
		if (!found) { cout << "-1\n"; return; }
	}
	cout << res.size() << '\n';
	for (auto [x, y] : res) cout << x + 1 << ' ' << y + 1 << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}