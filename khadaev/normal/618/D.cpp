#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#undef M_PI
const ld M_PI = 3.1415926535897932384626433;
const ld eps = 1e-8;

int max_tree = 0;
set<int> used;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	vector<set<int>> e(n);
	vector<int> used_degs(n);
	forn(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		e[u].insert(v);
		e[v].insert(u);
	}
	if (x < y) {
		set<int> lists;
		forn(i, 0, n)
			if (e[i].size() == 1)
				lists.insert(i);
		while (!lists.empty()) {
			int from = *(lists.begin());
			lists.erase(lists.begin());
			if (e[from].empty())
				continue;
			int to = *(e[from].begin());
			e[to].erase(from);
			e[from].erase(to);
			if (e[to].size() == 1)
				lists.insert(to);
			if (used_degs[to] < 2 && used_degs[from] < 2) {
				++used_degs[to];
				++used_degs[from];
			}
		}
		int s = 0;
		forn(i, 0, n) s += used_degs[i];
		s /= 2;
		cout << 1ll * s * x + 1ll * (n - s - 1) * y << '\n'; 

	} else {
		forn(i, 0, n) {
			if (e[i].size() == n - 1) {
				cout << x + 1ll * (n - 2) * y << '\n';
				return 0;
			}
		}
		cout << 1ll * (n - 1) * y << '\n';
	}

	return 0;
}