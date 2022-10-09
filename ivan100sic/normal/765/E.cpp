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

int n;
vector<int> e[200005];

int bd, bx;

void dfs_f(int x, int p, int d) {
	if (d > bd) {
		bd = d;
		bx = x;
	}
	for (int y : e[x]) {
		if (y != p) {
			dfs_f(y, x, d+1);
		}
	}
}

int mid;

int dfs_c(int x, int p, int t, int d, int td) {
	int q = x == t;
	for (int y : e[x]) {
		if (y != p) {
			q += dfs_c(y, x, t, d+1, td);
		}
	}
	if (q && d == td) {
		mid = x;
	}
	return q;
}

set<int> ds;

int dfs_d(int x, int p, int d) {
	if (x == p) {
		for (int y : e[x]) {
			int r = dfs_d(y, x, d+1);
			ds.insert(r);
			if (r == -1) {
				ds.insert(-2);
				ds.insert(-3);
			}
		}
		return 0;
	} else {
		// list?
		if (e[x].size() == 1) {
			return d;
		}

		// nije list
		int dom = 0;
		for (int y : e[x]) {
			if (y != p) {
				int r = dfs_d(y, x, d+1);
				if (r == -1) {
					dom = -1;
				} else if (dom == 0) {
					dom = r;
				} else if (dom != r) {
					dom = -1;
				}
			}
		}
		return dom;
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
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs_f(1, 1, 0);
	bd = 0;
	int a = bx;
	dfs_f(a, a, 0);
	int diam = bd;
	int b = bx;

	dfs_c(a, a, b, 0, diam / 2);
	int c = mid;

	dfs_d(c, c, 0);

	/*
	
	cerr << ds.size() << '\n';
	for (int x : ds) {
		cerr << x << ' ';
	}
	cerr << '\n';
	*/

	if (ds.size() >= 3) {
		cout << -1;
		return 0;
	}

	int d;

	if (ds.size() == 2) {
		d = *ds.begin() + *ds.rbegin();
	} else {
		d = *ds.begin();
	}

	while (d % 2 == 0) {
		d /= 2;
	}
	cout << d;
	
		
	return 0;
}