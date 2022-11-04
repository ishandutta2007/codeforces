#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

int ask(int u) {
	cout << "? " << u + 1 << endl;
	int res; cin >> res;
	return res - 1;
}

void ProGamerMove() {
	int n; cin >> n;
	vector<pair<int, int>> degs(n);
	for (int i = 0; i < n; ++i) cin >> degs[i].first, degs[i].second = i;
	sort(degs.rbegin(), degs.rend());
	vector<int> c(n, -1);
	int cc = 1;
	for (auto [d, u] : degs) if (c[u] == -1) {
		vector<int> g;
		while (d--) {
			g.push_back(ask(u));
			if (c[g.back()] != -1) break;
		}
		for (int v : g) c[v] = g.size() && ~d ? c[g.back()] : cc;
		c[u] = g.size() && ~d ? c[g.back()] : cc;
		cc += !(g.size() && ~d);
	}
	cout << '!';
	for (int r : c) cout << ' ' << r; cout << endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}