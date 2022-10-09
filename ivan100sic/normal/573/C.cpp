#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[100005], f[100005];
bool krak[100005], dole[100005], gore[100005], ceo[100005];

void dfs1(int x, int p) {
	for (int y : e[x]) {
		if (y == p)
			continue;
		f[x] += y;
		dfs1(y, x);
	}
}

void dfs2(int x) {
	for (int y : f[x])
		dfs2(y);

	// krak = ako imas najvise jedno dete i ono je krak
	krak[x] = !f[x].size() || (f[x].size() == 1 && krak[f[x][0]]);

	// dole = ako imas najvise dvoje dece i sva deca su kraci
	dole[x] = f[x].size() <= 2;
	for (int y : f[x])
		dole[x] &= krak[y];

	// gore = ako imas najvise 1 dete koje nije dole a gore je
	int c = 0, z = 1;
	for (int y : f[x])
		c += !dole[y], z = z && gore[y];
	gore[x] = c <= 1 && z;

	// ceo = ako imas najvise 2 deteta koja nisu dole a jesu gore
	ceo[x] = c <= 2 && z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	int r = 1;
	for (int i=1; i<=n; i++)
		if (e[i].size() >= e[r].size())
			r = i;

	cerr << "r = " << r << '\n';

	dfs1(r, r);
	dfs2(r);

	if (!ceo[r]) {
		fill(f+1, f+n+1, basic_string<int>());
		for (int i=1; i<=n; i++)
			if (gore[i] && !dole[i])
				r = i;
		cerr << "r = " << r << '\n';

		dfs1(r, r);
		dfs2(r);
	}

	cout << (ceo[r] ? "Yes\n" : "No\n");
}