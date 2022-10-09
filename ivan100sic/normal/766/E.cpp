#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

const int MAXN = 131072;

int n;
int l[100005], r[100005], t;
int vals[100005];

struct tree {

	int lazy[2*MAXN];
	int z[2*MAXN][20];
	int c[2*MAXN];

	void init() {
		for (int i=1; i<=n; i++) {
			int p = l[i];

			// cerr << p << ' ' << vals[i] << '\n';

			for (int j=0; j<20; j++) {
				z[p + MAXN - 1][j] = 1 & (vals[i] >> j);
			}
			c[p + MAXN - 1] = 1;
		}

		for (int i=MAXN-1; i>=1; i--) {
			for (int j=0; j<20; j++) {
				z[i][j] = z[2*i][j] + z[2*i+1][j];
			}
			c[i] = c[2*i] + c[2*i+1];
		}
	}

	void push(int x) {
		if (!lazy[x]) {
			return;
		}
		for (int i=0; i<20; i++) {
			if (lazy[x] & (1<<i)) {
				z[x][i] = c[x] - z[x][i];
			}
		}
		if (x < MAXN) {
			lazy[2*x] ^= lazy[x];
			lazy[2*x+1] ^= lazy[x];
		}
		lazy[x] = 0;
	}

	void add(int l, int r, int val, int node=1, int nl=1, int nr=MAXN) {
		push(node);
		if (r < nl || nr < l) {
			return;
		}

		if (l <= nl && nr <= r) {
			lazy[node] ^= val;
			push(node);
			return;
		}

		int nm = (nl + nr) >> 1;

		add(l, r, val, 2*node, nl, nm);
		add(l, r, val, 2*node+1, nm+1, nr);

		for (int i=0; i<20; i++) {
			z[node][i] = z[2*node][i] + z[2*node+1][i];
		}
		c[node] = c[2*node] + c[2*node+1];
	}

	long long eval(int x) {
		long long t = 0;
		for (int i=0; i<20; i++) {
			t += (1ll << i) * z[x][i];
		}
		return t;
	}

	long long sum(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		push(node);
		if (r < nl || nr < l) {
			return 0;
		}

		if (l <= nl && nr <= r) {
			return eval(node);
		}

		int nm = (nl + nr) >> 1;
		return sum(l, r, 2*node, nl, nm) + sum(l, r, 2*node+1, nm+1, nr);
	}
};

tree drvo;

vector<int> e[100005];
int val[100005];

void dfs(int x, int p, int xorr) {
	xorr ^= val[x];
	vals[x] = xorr;
	l[x] = ++t;

	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x, xorr);
		}
	}

	r[x] = t;
}

long long sol = 0;

void solve(int x, int p) {
	sol += drvo.sum(1, MAXN);

	/*
	for (int i=1; i<=n; i++) {
		cerr << drvo.sum(i, i) << ' ';
	}
	cerr << '\n';
	*/

	for (int y : e[x]) {
		if (y != p) {
			drvo.add(l[y], r[y], val[x] ^ val[y]);
			drvo.add(1, MAXN, val[y]);

			solve(y, x);

			drvo.add(1, MAXN, val[y]);
			drvo.add(l[y], r[y], val[x] ^ val[y]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> val[i];
	}

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs(1, 1, 0);
	drvo.init();
	solve(1, 1);

	cout << (sol + accumulate(val+1, val+n+1, 0ll)) / 2 << '\n';



}