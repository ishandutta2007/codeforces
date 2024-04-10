#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> e[1005], f[1005];
bool v1[1005], v2[1005], g[1005];
int n, m;
int u[5005], v[5005], p[1005];

void bfs(basic_string<int>* e, int x, bool* v) {
	basic_string<int> q = {x};
	v[x] = 1;
	size_t qs = 0;
	while (qs != q.size()) {
		x = q[qs++];
		for (int y : e[x]) {
			if (!v[y]) {
				v[y] = 1;
				q += y;				
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
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i];
		e[u[i]] += v[i];
		f[v[i]] += u[i];
	}

	bfs(e, 1, v1);
	bfs(f, n, v2);

	for (int i=1; i<=n; i++)
		g[i] = v1[i] && v2[i];

	for (int i=1; i<=n; i++) {
		bool ch = false;
		for (int i=0; i<m; i++) {
			int x = u[i], y = v[i];
			if (!g[x] || !g[y])
				continue;
			int oy = p[y], ox = p[x];
			p[y] = min(p[y], p[x] + 2);
			p[x] = min(p[x], p[y] - 1);
			if (oy != p[y] || ox != p[x])
				ch = true;
		}
		if (i == n && ch)
			return cout << "No\n", 0;
	}

	cout << "Yes\n";
	for (int i=0; i<m; i++) {
		int x = u[i], y = v[i];
		if (!g[x] || !g[y]) {
			cout << "1\n";
		} else {
			cout << p[y] - p[x] << '\n';
		}
	}
}