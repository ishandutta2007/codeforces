#include <bits/stdc++.h>
using namespace std;

int u[200005], v[200005];
bool used[200005];
vector<int> e[200005];
int n, m;

bool visited[200005];
vector<pair<int, int>> sol;

void dfs(int x, int backedge) {
	visited[x] = true;

	vector<int> edges;

	for (int eid : e[x]) {
		int y = x ^ u[eid] ^ v[eid];
		if (!visited[y]) {
			dfs(y, eid);
		}

		if (!used[eid] && eid != backedge) {
			edges.push_back(eid);
		}
	}

	if (backedge && !used[backedge]) {
		edges.push_back(backedge);
	}

	for (int i=0; i+1<(int)edges.size(); i+=2) {
		used[edges[i]] = true;
		used[edges[i+1]] = true;
		sol.push_back({edges[i], edges[i+1]});
	}
}

void prnt(int e1, int e2) {
	int a = u[e1], b = v[e1], c = u[e2], d = v[e2];
	if (a == c) {
		cout << b << ' ' << a << ' ' << d << '\n';
	} else if (a == d) {
		cout << b << ' ' << a << ' ' << c << '\n';
	} else if (b == c) {
		cout << a << ' ' << b << ' ' << d << '\n';
	} else if (b == d) {
		cout << a << ' ' << b << ' ' << c << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> u[i] >> v[i];
		e[u[i]].push_back(i);
		e[v[i]].push_back(i);
	}

	for (int i=1; i<=n; i++) {
		if (!visited[i]) {
			dfs(i, 0);
		}
	}

	cout << sol.size() << '\n';
	for (auto p : sol) {
		prnt(p.first, p.second);
	}

}