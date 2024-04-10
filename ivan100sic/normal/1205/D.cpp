#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[1005];

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

int cx, cp;

void dfs4(int x, int p) {
	bool ok = true;
	for (int y : e[x]) {
		int v = y == p ? n - sz[x] : sz[y];
		if (2*v > n) {
			ok = false;
		}
	}
	if (ok) {
		cx = x;
		cp = p;
	}
	for (int y : e[x])
		if (y != p)
			dfs4(y, x);
}

int t;
int d[1005];
void dfs3(int x, int p, int mul) {
	d[x] = ++t;
	cout << x << ' ' << p << ' ' << mul*(t - d[p]) << '\n';
	for (int y : e[x])
		if (y != p)
			dfs3(y, x, mul);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	dfs1(1, 1);
	dfs4(1, 1);
	cerr << "centar " << cx << ' ' << cp << '\n';

	vector<pair<int, int>> s;

	for (int y : e[cx]) {
		int v = y == cp ? n - sz[cx] : sz[y];
		s.emplace_back(v, y);
	}

	sort(s.begin(), s.end(), greater<pair<int, int>>());
	int z = 0;
	vector<int> levi, desni;
	bool stop = false;
	for (auto [v, y] : s) {
		if (!stop) {
			z += v;
			levi.push_back(y);
			if (3*z >= n && 3*z <= 2*n)
				stop = true;
		} else {
			desni.push_back(y);
		}
	}

	cerr << "levi desni " << z << ' ' << n-z << '\n';

	for (int y : levi)
		dfs3(y, cx, 1);
	t = 0;
	for (int y : desni)
		dfs3(y, cx, z);

}