#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
basic_string<int> e[100005];

int d[100005], p[100005];

bool ok = true;

void bfs(int x) {
	fill(d+1, d+n+1, 1123123123);
	d[x] = 0;
	p[x] = x;
	queue<int> q;
	q.push(x);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (d[y] == 1123123123) {
				q.push(y);
				d[y] = d[x] + 1;
				p[y] = x;
			}
		}
	}
}

void dfs(int x, int p, int k) {
	if (k < 0) {
		ok = false;
		return;
	} else if (k == 0) {
		for (int y : e[x])
			if (y != p)
				ok = false;
		return;
	} else {
		int z = 0;
		for (int y : e[x])
			if (y != p) {
				z++;
				dfs(y, x, k-1);
			}
		if (z < 3)
			ok = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	bfs(1);
	int U = max_element(d+1, d+n+1) - d;
	bfs(U);
	int V = max_element(d+1, d+n+1) - d;
	int diam = d[V];
	if (diam % 2)
		return cout << "No\n", 0;
	int steps = diam / 2;
	int c = V;
	while (steps--)
		c = p[c];

	dfs(c, c, k);
	cout << (ok ? "Yes\n" : "No\n");
}