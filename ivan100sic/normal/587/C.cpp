#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct minimumi {
	basic_string<int> a;

	minimumi operator+ (const minimumi& b) const {
		basic_string<int> tmp(a.size() + b.a.size(), 0);
		merge(a.begin(), a.end(), b.a.begin(), b.a.end(), tmp.begin());
		tmp.resize(min((int)tmp.size(), 10));
		return {tmp};
	}
};

minimumi v[100005][18];
int p[100005][18], d[100005], n;
basic_string<int> e[100005];

void dfs(int x, int par) {
	p[x][0] = par;
	for (int i=1; i<18; i++) {
		int y = p[x][i-1];
		p[x][i] = p[y][i-1];
		v[x][i] = v[x][i-1] + v[y][i-1];
	}

	for (int y : e[x]) {
		if (y == par)
			continue;
		d[y] = d[x] + 1;
		dfs(y, x);
	}
}

int dizi(int x, int k) {
	for (int i=0; i<18; i++)
		if (k & (1 << i))
			x = p[x][i];
	return x;
}

minimumi racunaj(int x, int k) {
	minimumi w;
	for (int i=0; i<18; i++)
		if (k & (1 << i)) {
			w = w + v[x][i];
			x = p[x][i];
		}
	return w;
}

int lca(int x, int y) {
	if (d[x] > d[y])
		swap(x, y);
	y = dizi(y, d[y] - d[x]);
	if (x == y)
		return x;
	for (int i=17; i>=0; i--) {
		int xx = p[x][i];
		int yy = p[y][i];
		if (xx != yy) {
			x = xx;
			y = yy;
		}
	}
	return p[x][0];
}

void ans(int x, int y, int a) {
	int z = lca(x, y);
	auto w = racunaj(x, d[x]-d[z]) + racunaj(y, d[y] - d[z]) + v[z][0];
	a = min(a, (int)w.a.size());
	w.a.resize(a);
	cout << a;
	for (int x : w.a)
		cout << ' ' << x;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int m, q;
	cin >> n >> m >> q;

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	for (int i=1; i<=m; i++) {
		int x;
		cin >> x;
		v[x][0] = v[x][0] + minimumi{{i}};
	}

	dfs(1, 1);
	while (q--) {
		int x, y, a;
		cin >> x >> y >> a;
		ans(x, y, a);
	}
}