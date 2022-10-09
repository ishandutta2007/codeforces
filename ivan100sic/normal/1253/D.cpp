#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int p[200005], sz[200005], lo[200005], hi[200005];
int n, m;

int e(int x) {
	if (x == p[x])
		return x;
	return p[x] = e(p[x]);
}

void spoji(int x, int y) {
	x = e(x);
	y = e(y);
	if (x == y)
		return;
	p[x] = y;
	sz[y] += sz[x];
	lo[y] = min(lo[y], lo[x]);
	hi[y] = max(hi[y], hi[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		p[i] = lo[i] = hi[i] = i;
		sz[i] = 1;
	}

	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		spoji(u, v);
	}

	int sol = 0;
	
	for (int i=1; i<=n; i++) {
		int j = i+1;
		while (sz[e(i)] != hi[e(i)] - lo[e(i)] + 1) {
			while (e(j) == e(i))
				j++;
			sol++;
			spoji(i, j);
		}
	}

	cout << sol << '\n';
}