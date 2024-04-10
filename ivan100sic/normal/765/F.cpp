#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <cmath>
using namespace std;

int n, m;
int a[100005], sol[300005];

struct upit {
	int l, r, id;
};

upit u[300005];

vector<int> e[300005];

const int MAXN = 131072;

struct tree {
	int a[2*MAXN], lazy[2*MAXN];

	void init() {
		for (int i=1; i<2*MAXN; i++) {
			a[i] = 2'000'000'000;
			lazy[i] = 2'000'000'000;
		}
	}

	void push(int x) {
		a[x] = min(a[x], lazy[x]);
		if (x < MAXN) {
			lazy[2*x] = min(lazy[2*x], lazy[x]);
			lazy[2*x+1] = min(lazy[2*x+1], lazy[x]);
		}
		lazy[x] = 2'000'000'000;
	}	

	void add(int l, int r, int val, int node=1, int nl=1, int nr=MAXN) {
		push(node);
		if (nr < l || r < nl) {
			return;
		}
		if (l <= nl && nr <= r) {
			lazy[node] = min(lazy[node], val);
			push(node);
			return;
		}

		int nm = (nl + nr) >> 1;
		add(l, r, val, 2*node, nl, nm);
		add(l, r, val, 2*node+1, nm+1, nr);

		a[node] = min(a[2*node], a[2*node+1]);
	}

	int get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		push(node);
		if (nr < l || r < nl) {
			return 2'000'000'000;
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		int v1 = get(l, r, 2*node, nl, nm);
		int v2 = get(l, r, 2*node+1, nm+1, nr);
		return min(v1, v2);
	}
};

tree dp, pos;

int b[100005], bb;

void doit() {

	dp.init();
	pos.init();

	for (int i=1; i<=n; i++) {
		// update
		int x = a[i];
		int y;
		int lx = lower_bound(b+1, b+bb+1, x) - b;

		int j = -pos.get(lx, bb);

		if (j == -2'000'000'000) {
			goto sols;
		}

		y = a[j];

		dp.add(1, j, y - x);

		while (1) {

			// cerr << x << ' ' << y << '\n';

			int bl = upper_bound(b+1, b+bb+1, (x+y)/2) - b - 1;

			if (bl < lx) {
				break;
			}

			int jp = -pos.get(lx, bl);

			if (jp == -2'000'000'000) {
				break;
			}

			int yp = a[jp];

			dp.add(1, jp, yp-x);

			if (yp == x) {
				break;
			}

			y = yp;
			j = jp;
		}

	sols:

		pos.add(lx, lx, -i);

		for (int qid : e[i]) {
			sol[qid] = min(sol[qid], dp.get(u[qid].l, i));
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
		cin >> a[i];
	}

	copy(a+1, a+n+1, b+1);
	sort(b+1, b+n+1);
	bb = unique(b+1, b+n+1) - (b+1);

	cin >> m;
	for (int i=1; i<=m; i++) {
		cin >> u[i].l >> u[i].r;
		u[i].id = i;
		e[u[i].r].push_back(i);
		sol[i] = 2'000'000'000;
	}

	fill(sol+1, sol+m+1, 2'000'000'000);

	doit();

	/*
	for (int i=1; i<=m; i++) {
		cerr << sol[i] << ' ';
	}
	cerr << '\n';
	*/
	
	for (int i=1; i<=n; i++) {
		a[i] = 1'000'000'000 - a[i];
	}
	for (int i=1; i<=bb; i++) {
		b[i] = 1'000'000'000 - b[i];
	}
	reverse(b+1, b+bb+1);

	doit();

	for (int i=1; i<=m; i++) {
		cout << sol[i] << '\n';
	}
}