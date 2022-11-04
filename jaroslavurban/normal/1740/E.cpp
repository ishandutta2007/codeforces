#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<vector<int>> g(n);
	for (int u, i = 0; i < n - 1; ++i) {
		cin >> u, --u;
		g[u].push_back(i + 1);
	}
	auto solve = [&] (int u, auto&& rec) -> pair<int, int> {
		int mxd = 0, tot = 0;
		for (int v : g[u]) {
			auto [a, b] = rec(v, rec);
			mxd = max(mxd, a);
			tot += max(a, b);
		}
		return make_pair(mxd + 1, tot);
	};
	auto [a, b] = solve(0, solve);
	cout << max(a, b) << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}