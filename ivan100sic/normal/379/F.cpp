#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
basic_string<int> e[1000009];
int a[500005];

void ae(int x, int y) {
	e[x] += y;
	e[y] += x;
}

int dub[1000009];
int pr[1000009][20];

void dfs(int x, int p) {
	pr[x][0] = p;
	for (int i=1; i<20; i++)
		pr[x][i] = pr[pr[x][i-1]][i-1];
	for (int y : e[x]) {
		if (y == p)
			continue;
		dub[y] = dub[x] + 1;
		dfs(y, x);
	}
}

int dizi(int x, int k) {
	for (int i=0; i<20; i++)
		if (k & (1 << i))
			x = pr[x][i];
	return x;
}

int lca(int x, int y) {
	if (dub[x] > dub[y])
		swap(x, y);
	y = dizi(y, dub[y] - dub[x]);
	if (x == y)
		return x;
	for (int i=19; i>=0; i--) {
		int xx = pr[x][i];
		int yy = pr[y][i];
		if (xx != yy) {
			x = xx;
			y = yy;
		}
	}
	return pr[x][0];
}

int dist(int x, int y) {
	int z = lca(x, y);
	return dub[x] + dub[y] - 2 * dub[z];
}

int x1 = 2, x2 = 3, d12 = 2;

void av(int x) {
	int d1 = dist(x, x1);
	int d2 = dist(x, x2);
	int h = max({d1, d2, d12});
	if (d1 == h) {
		x2 = x;
	} else if (d2 == h) {
		x1 = x;
	}
	d12 = h;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	n = 4;
	ae(1, 2);
	ae(1, 3);
	ae(1, 4);

	cin >> q;
	for (int i=0; i<q; i++) {
		int x;
		cin >> x;
		ae(x, n+1);
		ae(x, n+2);
		n += 2;		
	}

	dfs(1, 1);

	for (int i=0; i<q; i++) {
		av(2*i + 5);
		av(2*i + 6);
		cout << d12 << '\n';
	}
}