// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
basic_string<int> e[500005], d;

void dfs(int x, int p, int w=0) {
	if (e[x].size() == 1)
		d += w;
	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x, w+1);
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	int z = 0;

	for (int y : e[1]) {
		d = {};
		dfs(y, 1);
		sort(begin(d), end(d));
		int sol = -123;
		for (int x : d)
			sol = max(sol+1, x);
		z = max(sol, z);
	}

	cout << z + 1 << '\n';
}