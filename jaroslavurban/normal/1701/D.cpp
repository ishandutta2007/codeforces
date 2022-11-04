#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

void ProGamerMove() {
	int n; cin >> n;
	vector<vector<pair<int, int>>> add(n + 1);
	vector<int> a(n);
	for (int v, i = 1; i <= n; ++i) {
		cin >> v;
		add[i / (v + 1) + 1].push_back({v ? i / v : n, i});
	}
	set<pair<int, int>> available;
	for (int i = 1; i <= n; ++i) {
		for (auto p : add[i])
			available.insert(p);
		assert(available.size());
		a[available.begin()->second - 1] = i;
		available.erase(available.begin());
	}
	for (int v : a) cout << v << ' '; cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}