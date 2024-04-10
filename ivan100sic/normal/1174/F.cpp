#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
set<int> e[200005];

void finish(int x) {
	cout << "! " << x << '\n' << flush;
	exit(0);
}

int ask_dist(int x) {
	cout << "d " << x << '\n' << flush;
	int y;
	cin >> y;
	if (y == 0)
		finish(x);
	return y;
}

int ask_next(int x) {
	cout << "s " << x << '\n' << flush;
	cin >> x;
	return x;
}

int d0[200005], dub;

void dfs0(int x, int p) {
	for (int y : e[x]) {
		if (y != p) {
			d0[y] = d0[x] + 1;
			dfs0(y, x);
		}
	}
}

void rmnode(int x) {
	for (int y : e[x])
		e[y].erase(x);
	e[x].clear();
}

int h[200005], parent[200005];
int dfsh(int x, int p) {
	h[x] = 0;
	parent[x] = p;
	int val = 0, tot = 0;
	for (int y : e[x]) {
		if (y != p) {
			int t = dfsh(y, x);
			if (t > val) {
				h[x] = y;
				val = t;
			}
			tot += t;
		}
	}
	return tot + (d0[x] == dub);
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
		e[x].insert(y);
		e[y].insert(x);
	}

	dfs0(1, 1);
	dub = ask_dist(1);
	for (int i=1; i<=n; i++) {
		if (d0[i] > dub) {
			rmnode(i);
		}
	}

	int root = 1;
	while (1) {
		dfsh(root, root);
		cerr << "heavy grana roota " << root << " je " << h[root] << '\n';
		// nije u rootu
		int nx = ask_next(root);
		if (nx == h[root]) {
			// eee...
			int x = root;
			while (h[x])
				x = h[x];

			int w = ask_dist(x) >> 1;
			int p = x, q = parent[x];
			while (--w) {
				p = parent[p];
				q = parent[q];
			}
			cerr << "discarding heavy edge " << p << ' ' << q << '\n';
			rmnode(p);
			root = q;
		} else {
			rmnode(root);
			root = nx;
			ask_dist(root);
		}
	}
}