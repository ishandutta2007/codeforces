// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[200005], b[200005], c[200005];
basic_string<int> e[200005];

void dfs1(int x, int p) {
	for (int y : e[x]) {
		if (y == p)
			continue;
		a[y] = min(a[y], a[x]);
		dfs1(y, x);
	}
}

ll sol = 0;

int dfs2(int x, int p) {
	int bm=0, bp=0, bt=0;

	auto proc = [&](int b) {
		if (b < 0)
			bm += -b;
		else
			bp += b;
		bt += b;
	};

	for (int y : e[x]) {
		if (y == p)
			continue;
		proc(dfs2(y, x));
	}
	proc(b[x] - c[x]);

	int u = min(bm, bp);
	sol += u * 2ll * a[x];
	return bt;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i] >> b[i] >> c[i];
	for (int i=1, u, v; i<n; i++)
		cin >> u >> v, e[u] += v, e[v] += u;

	dfs1(1, 1);
	if (dfs2(1, 1))
		sol = -1;
	cout << sol << '\n';
}