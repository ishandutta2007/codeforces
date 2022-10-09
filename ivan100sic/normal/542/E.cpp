#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[1005];
int vis[1005], no;

void dfs(int x, int c) {
	if (vis[x]) {
		if (vis[x] != c)
			no = 1;
		return;
	}
	vis[x] = c;
	for (int y : e[x])
		dfs(y, 3-c);
}

int d[1005];
void bfs(int x) {
	fill(d+1, d+n+1, -1);
	basic_string<int> q;
	size_t qs = 0;
	q += x;
	d[x] = 0;
	while (qs != q.size()) {
		x = q[qs++];
		for (int y : e[x]) {
			if (d[y] == -1) {
				d[y] = d[x] + 1;
				q += y;
			}
		}
	}
}

bool v2[1005];

void dfs2(int x, basic_string<int>& k) {
	k += x;
	v2[x] = 1;
	for (int y : e[x])
		if (!v2[y])
			dfs2(y, k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			dfs(i, 1);
		}
	}

	if (no)
		return cout << "-1\n", 0;

	int z = 0;
	for (int i=1; i<=n; i++) {
		if (!v2[i]) {
			basic_string<int> komp;
			dfs2(i, komp);
			int w = 0;
			for (int x : komp) {
				bfs(x);
				w = max(w, *max_element(d+1, d+n+1));
			}
			z += w;
		}
	}
	cout << z << '\n';
}