#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;
basic_string<int> e[300005];
int sol[300005];
int sz[300005];

void dfs1(int x) {
	for (int y : e[x]) {
		dfs1(y);
		sz[x] += sz[y];
	}
	sz[x] += 1;
}

set<pair<int, int>> s;

void dfs2(int x) {
	s.insert({sz[x], x});
	int lb = 0;
	for (int y : e[x])
		lb = max(lb, 2*sz[y]);
	int ub = 2*sz[x];
	while (1) {
		auto it = s.lower_bound({lb, -1});
		if (it != s.end() && it->first <= ub) {
			sol[it->second] = x;
			s.erase(it);
		} else
			break;
	}
	for (int y : e[x])
		dfs2(y);
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> q;
	for (int i=2; i<=n; i++) {
		int p;
		cin >> p;
		e[p] += i;
	}

	dfs1(1);
	dfs2(1);

	while (q--) {
		int x;
		cin >> x;
		cout << sol[x] << '\n';
	}
}