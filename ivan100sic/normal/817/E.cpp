// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct node {
	node* l = nullptr;
	node* r = nullptr;
	int v = 0;
};

node pool[10'000'000];

node* new_node() {
	static int idx = 0;
	return pool + (idx++);
}

node* dod(int x, int v, node* r, int lvl = 29) {
	if (!r) {
		r = new_node();
	}

	if (lvl >= 0) {
		if (x & (1 << lvl)) {
			r->r = dod(x, v, r->r, lvl-1);
		} else {
			r->l = dod(x, v, r->l, lvl-1);
		}
	}

	r->v += v;
	return r;
}

int cit(int x, int l, node* r, int lvl = 29, int xl = 0, int xr = (1<<30)) {
	if (!r || l <= xl) return 0;
	if (xr <= l) return r->v;

	int xm = (xl+xr) >> 1;

	if (x & (1 << lvl)) {
		return cit(x, l, r->r, lvl-1, xl, xm) + cit(x, l, r->l, lvl-1, xm, xr);
	} else {
		return cit(x, l, r->l, lvl-1, xl, xm) + cit(x, l, r->r, lvl-1, xm, xr);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	node* root = nullptr;

	int q;
	cin >> q;
	while (q--) {
		int t, p;
		cin >> t >> p;
		if (t == 1) {
			root = dod(p, 1, root);
		} else if (t == 2) {
			root = dod(p, -1, root);
		} else {
			int l;
			cin >> l;
			cout << cit(p, l, root) << '\n';
		}
	}
}