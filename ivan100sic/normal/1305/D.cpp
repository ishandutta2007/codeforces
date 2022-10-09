// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[1005];

int ask(int x, int y) {
	cout << "? " << x << ' ' << y << '\n' << flush;
	int z;
	cin >> z;
	return z;
}

int sz[1005];

void dfs1(int x, int p) {
	sz[x] = 1;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs1(y, x);
		sz[x] += sz[y];
	}
}

void dfs2(int x, int p, int& c) {
	bool ok = 2*sz[x] >= n;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs2(y, x, c);
		if (sz[y]*2 > n)
			ok = false;
	}
	if (ok)
		c = x;
}

vector<int> v;
int d[1005];

void dfs3(int x, int p) {
	for (int y : e[x]) {
		if (y == p)
			continue;
		d[y] = d[x] + 1;
		dfs3(y, x);
	}
	v.push_back(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1, u, v; i<n; i++, cin >> u >> v, e[u] += v, e[v] += u); // pozdravite mi Sebeza

	dfs1(1, 1);
	int c = 0;
	dfs2(1, 1, c);	

	dfs3(c, c);

	int sol = c;

	for (int i=0; i<n/2; i++) {
		int x = v[i], y = v[min(n-1, i + n/2)];
		int z = ask(x, y);
		if (d[z] > d[sol])
			sol = z;
	}

	cout << "! " << sol << '\n' << flush;
}

// I will still practice daily...