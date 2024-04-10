// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
basic_string<int> e[100005];
int c[2], u[100005];

void dfs(int x, int p, int d = 0) {
	u[x] = p;
	c[d] += e[x].size() == 1;
	for (int y : e[x])
		if (y != p)
			dfs(y, x, d^1);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1, u, v; i<n; i++)
		cin >> u >> v, e[u] += v, e[v] += u;

	int r = 1;
	while (e[r].size() == 1)
		r++;

	dfs(r, r);
	cout << 2*!!min(c[0], c[1]) + 1 << ' ';

	int g = n-1;
	for (int i=1; i<=n; i++) {
		if (e[i].size() == 1)
			continue;
		int w = 0;
		for (int y : e[i])
			if (y != u[i] && e[y].size() == 1)
				w++;
		if (w)
			g -= w-1;
	}
	cout << g << '\n';
}