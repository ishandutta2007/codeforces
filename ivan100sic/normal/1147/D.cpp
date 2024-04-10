#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int mod = 998244353;

void ad(int& x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

string s;
int m, sol;

int n;
basic_string<pair<int, int>> e[2005];
int vis[2005];

void ae(int x, int y, int r) {
	e[x] += {y, r};
	e[y] += {x, r};
}

const int INCONSISTENT = 1;
const int CONSTANT = 2;

void dfs(int x, int cl, int& status) {
	if (x == n-1)
		status |= CONSTANT;

	if (vis[x] != -1) {
		if (vis[x] != cl)
			status |= INCONSISTENT;
		return;
	}

	vis[x] = cl;
	for (auto [y, w] : e[x]) {
		dfs(y, w^cl, status);
	}
}

void resi(int l) {
	// cvorovi ce da budu 0..m-1 za string a (duzi)
	// i to little-endian
	// m..m+l-1 za string b, isto little-endian
	// m+l-1 mora da bude jednak kecu
	// svi posle toga mora da budu jednaki nuli (postoje)
	// nula je 2m (konstanta)
	n = 2*m + 1;
	fill(e, e+n, basic_string<pair<int, int>>());
	fill(vis, vis+n, -1);
	// duzi string, palindromske jednakosti
	for (int i=0, j=m-1; i<j; i++, j--)
		ae(i, j, 0);
	// kraci string, palindromske jednakosti
	for (int i=m, j=m+l-1; i<j; i++, j--)
		ae(i, j, 0);
	// xor stringova
	for (int i=0; i<m; i++)
		if (s[i] != '?')
			ae(i, i+m, s[i] - '0');
	// dodatne jednakosti za drugi string
	ae(m+l-1, 2*m, 1);
	for (int i=m+l; i<2*m; i++)
		ae(i, 2*m, 0);


	int sol = 1;

	for (int i=0; i<n; i++) {
		if (vis[i] == -1) {
			int status = 0;
			dfs(i, 0, status);

			if (status & INCONSISTENT)
				sol = 0;
			else if (status & CONSTANT)
				sol = sol;
			else
				ad(sol, sol);

			// cerr << "komponenta " << l << ' ' << i << '\n';
		}
	}

	ad(::sol, sol);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	m = s.size();
	reverse(s.begin(), s.end());
	for (int l=1; l<m; l++) {
		resi(l);
	}
	cout << sol << '\n';
}