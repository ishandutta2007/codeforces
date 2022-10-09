#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> occ[200005], cyc;
basic_string<pair<int, int>> st;
bool satis[200005];
int sol[200005];
basic_string<pair<int, int>> e[200005];
bool vis[200005], inst[200005];

void postavi(int x) {
	sol[abs(x)] = x > 0;
}

void dfs(int x, int xeid) {
	vis[x] = inst[x] = true;
	st += {x, xeid};
	if (satis[x] && cyc.size() == 0)
		cyc = {x};

	for (auto [y, yeid] : e[x]) {
		if (abs(yeid) == abs(xeid))
			continue;

		if (!vis[y]) {
			dfs(y, yeid);
		} else if (inst[y] && cyc.size() == 0) {
			int it = 0;
			while (st[it].first != y)
				it++;
			for (int i=it; i<(int)st.size(); i++) {
				cyc += st[i].first;
				if (i > it)
					postavi(st[i].second);
			}
			postavi(yeid);
		}
	}
	st.pop_back();
	inst[x] = false;
}

bool bfsvis[200005];

void bfs(basic_string<int> q) {
	for (int x : q)
		bfsvis[x] = true;
	size_t qs = 0;
	while (qs != q.size()) {
		int x = q[qs++];
		for (auto [y, yeid] : e[x]) {
			if (!bfsvis[y]) {
				postavi(-yeid);
				q += y;
				bfsvis[y] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		int t;
		cin >> t;
		while (t--) {
			int x;
			cin >> x;
			if (x < 0)
				occ[-x] += -i;
			else
				occ[x] += i;
		}
	}

	basic_string<int> later;

	for (int i=1; i<=m; i++) {
		if (occ[i].size() == 1) {
			int x = occ[i][0];
			sol[i] = x > 0;
			satis[abs(x)] = 1;
		} else if (occ[i].size() == 2) {
			int x = occ[i][0];
			int y = occ[i][1];
			if ((x < 0) == (y < 0)) {
				sol[i] = x > 0;
				satis[abs(x)] = 1;
				satis[abs(y)] = 1;
			} else {
				e[abs(x)] += {abs(y), x > 0 ? i : -i};
				e[abs(y)] += {abs(x), y > 0 ? i : -i};
				// cerr << "edges " << abs(x) << ' ' << abs(y) << '\n';
				later += i;
			}
		}
	}

	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			st = {};
			cyc = {};
			dfs(i, 0);		
			if (cyc.size() == 0) {
				cout << "NO\n";
				return 0;
			}
			bfs(cyc);
		}
	}

	cout << "YES\n";
	for (int i=1; i<=m; i++)
		cout << sol[i];
	cout << '\n';
}