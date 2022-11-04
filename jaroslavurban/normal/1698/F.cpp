#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void op(vector<int>& a, int l, int r, vector<pair<int, int>>& ops) {
	reverse(a.begin() + l, a.begin() + r + 1);
	ops.push_back({l, r});
}

void step(vector<int>& a, int& i, vector<pair<int, int>>& ops) {
	int n = a.size();
	int pi = i;
	do {
		pi = i;
		while (i + 1 < n && a[i + 1] == a[i]) ++i;
		for (int k = i + 2; k + 1 < n; ++k) if (a[k] == a[i] && a[k + 1] == a[i]) {
			op(a, i, k + 1, ops);
			++i;
			break;
		}
	} while (pi != i);
}

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int& v : a) cin >> v;
	for (int& v : b) cin >> v;
	vector<pair<int, int>> ops, opsr;
	int i = 0, j = 0;
	while (i < n && j < n) {
		step(a, i, ops);
		step(b, j, opsr);
		if (i != j || a[i] != b[j]) { cout << "NO\n"; return; }
		if (i + 1 == n) break;
		vector<pair<int, int>> an, bn;
		an.push_back({a[i + 1], i + 1});
		bn.push_back({b[j + 1], j + 1});
		for (int k = i + 2; k + 1 < n; ++k) if (a[k + 1] == a[i]) an.push_back({a[k], k});
		for (int k = j + 2; k + 1 < n; ++k) if (b[k + 1] == b[j]) bn.push_back({b[k], k});
		int want = -1;
		for (auto [v, p] : an)
			for (auto [v2, p2] : bn)
				if (v == v2)
					want = v;
		if (want == -1) { cout << "NO\n"; return; }
		if (a[i + 1] != want) {
			for (auto [v, p] : an) if (v == want) {
				op(a, i, p + 1, ops);
				break;
			}
		}
		if (b[j + 1] != want) {
			for (auto [v, p] : bn) if (v == want) {
				op(b, j, p + 1, opsr);
				break;
			}
		}
		++i, ++j;
	}
	cout << "YES\n";
	ops.insert(ops.end(), opsr.rbegin(), opsr.rend());
	assert(ops.size() <= n * n);
	cout << ops.size() << '\n';
	for (auto [l, r] : ops) cout << l + 1 << ' ' << r + 1 << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}