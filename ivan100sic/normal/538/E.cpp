#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int r[200005], s[200005], n;
basic_string<int> e[200005];

auto l = r;

void dfs1(int x, int pl) {
	for (int y : e[x])
		dfs1(y, pl^1), s[x] += s[y];

	if (e[x].size() == 0) {
		s[x] = l[x] = r[x] = 1;
		return;
	}

	if (pl == 0) {
		// igrac maksimizuje

		// raspored-max uzimamo da ima najmanji s-l
		int lo = 1e9;
		r[x] = 0;
		for (int y : e[x])
			lo = min(lo, s[y] - l[y]), r[x] += s[y];
		r[x] -= lo;

	} else {


		// raspored-max uzmimamo idk
		r[x] = 0;
		for (int y : e[x])
			r[x] += r[y] - 1;
		r[x]++;
	}
}

void dfs2(int x, int pl) {
	for (int y : e[x])
		dfs2(y, pl^1), s[x] += s[y];

	if (e[x].size() == 0) {
		s[x] = l[x] = r[x] = 1;
		return;
	}

	if (pl == 0) {
		// igrac maksimizuje


		// raspored-min uzimamo zbir svih r-ova
		l[x] = 0;
		for (int y : e[x])
			l[x] += l[y];
	} else {
		// igrac minimizuje

		// raspored-min uzimamo najmanji broj
		l[x] = 1e9;
		for (int y : e[x])
			l[x] = min(l[x], r[y]);

		
	}
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
	}

	dfs1(1, 0);
	cout << r[1] << ' ';
	dfs2(1, 0);
	cout << r[1] << '\n';
}