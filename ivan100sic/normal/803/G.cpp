#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

const int INF = 2'000'000'000;

int n, k;
int a[100005];

struct nsegt {
	static const int MAXN = 131072;

	int b[2*MAXN];

	void init() {
		fill(b, b+2*MAXN, INF);

		for (int i=1; i<=n; i++) {
			b[i + MAXN - 1] = a[i];
		}
		for (int i=MAXN-1; i>0; i--) {
			b[i] = min(b[2*i], b[2*i+1]);
		}
	}

	int ask(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return INF;
		}
		if (l <= nl && nr <= r) {
			return b[node];
		}

		int nm = (nl + nr) >> 1;

		return min(
			ask(l, r, 2*node, nl, nm),
			ask(l, r, 2*node+1, nm+1, nr)
		);
	}

	int smart(int l, int r) {
		// uzima u obzir periodicnost
		if (r - l + 1 >= n) {
			return b[1];
		}

		int lr = (l-1) % n + 1;
		int nr = (r-1) % n + 1;

		if (lr <= nr) {
			return ask(lr, nr);
		} else {
			return min(ask(lr, n), ask(1, nr));
		}
	}
} drvo1;

struct node {
	node* left;
	node* right;

	int val;
	int lazy;
};

node* create(int l, int r) {
	node* t = new node;
	t->left = nullptr;
	t->right = nullptr;
	t->val = drvo1.smart(l, r);
	t->lazy = -1;
	return t;
}

int expand(node* t, int nl, int nr) {
	int nm = (nl + nr) >> 1;

	if (!t->left) {
		t->left = create(nl, nm);
	}

	if (!t->right) {
		t->right = create(nm+1, nr);
	}

	return nm;
}

void push(node* t, int nl, int nr) {
	if (t->lazy == -1) {
		return;
	}

	if (nl != nr) {
		expand(t, nl, nr);
		t->left->lazy = t->lazy;
		t->right->lazy = t->lazy;
	}

	t->val = t->lazy;
	t->lazy = -1;
}

const int BIGG = 1 << 30;

void set(int l, int r, int val, node* t, int nl=1, int nr=BIGG) {

	push(t, nl, nr);

	if (r < nl || nr < l) {
		return;
	}

	if (l <= nl && nr <= r) {
		t->lazy = val;
		push(t, nl, nr);
		return;
	}

	int nm = expand(t, nl, nr);
	set(l, r, val, t->left, nl, nm);
	set(l, r, val, t->right, nm+1, nr);

	t->val = min(t->left->val, t->right->val);
}

int get(int l, int r, node* t, int nl=1, int nr=BIGG) {
	push(t, nl, nr);

	if (r < nl || nr < l) {
		return INF;
	}

	if (l <= nl && nr <= r) {
		return t->val;
	}

	int nm = expand(t, nl, nr);
	return min(
		get(l, r, t->left, nl, nm),
		get(l, r, t->right, nm+1, nr)
	);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	drvo1.init();

	node* root = create(1, BIGG);

	int q;
	cin >> q;
	while (q--) {
		int t, l, r, x;
		cin >> t >> l >> r;
		if (t == 1) {
			cin >> x;
			set(l, r, x, root);
		} else {
			cout << get(l, r, root) << '\n';
		}
	}
}