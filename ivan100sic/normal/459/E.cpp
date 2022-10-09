#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dp[300005], n, m;
basic_string<tuple<int, int, int>> e;
basic_string<pair<int, int>> promene;

void operi() {
	for (auto [x, y] : promene)
		dp[x] = max(dp[x], y);
	promene = {};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e += {w, u, v};
	}
	sort(e.begin(), e.end());
	int last_w = -1;
	for (auto [w, u, v] : e) {
		if (w != last_w)
			operi();
		promene += {v, max(dp[v], dp[u]+1)};
		last_w = w;
	}
	operi();
	cout << *max_element(dp+1, dp+n+1) << '\n';
}