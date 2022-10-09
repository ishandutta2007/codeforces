#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r, p;
};

int n, m, k;
seg a[300005];

struct node {
	node* left;
	node* right;
	int val;
} pool[40 * 300005]; int pool_cnt;

node* new_node() {
	return pool + pool_cnt++;
}

node* prazno_drvo(int xl=0, int xr=300005) {
	node* tmp = new_node();
	tmp->val = -1123123123;
	if (xl < xr) {
		int xm = (xl + xr) >> 1;
		tmp->left = prazno_drvo(xl, xm);
		tmp->right = prazno_drvo(xm+1, xr);
	}
	return tmp;
}

node* sett(node* root, int p, int v, int xl=0, int xr=300005) {
	node* tmp = new_node();
	*tmp = *root;
	if (xl == xr) {
		tmp->val = max(tmp->val, v);
		return tmp;
	}

	int xm = (xl + xr) >> 1;
	if (p <= xm)
		tmp->left = sett(tmp->left, p, v, xl, xm);
	else
		tmp->right = sett(tmp->right, p, v, xm+1, xr);
	tmp->val = min(tmp->left->val, tmp->right->val);
	return tmp;
}

int gett(node* root, int l, int r, int xl=0, int xr=300005) {
	if (r < xl || xr < l)
		return 1123123123;
	if (l <= xl && xr <= r)
		return root->val;
	int xm = (xl + xr) >> 1;
	return min(
		gett(root->left, l, r, xl, xm),
		gett(root->right, l, r, xm+1, xr));
}

node* drva[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;

	basic_string<int> uq; // kompresujem samo R koordinate

	for (int i=0; i<k; i++) {
		int l, r, p;
		cin >> l >> r >> p;
		uq += r;
		a[i] = {l, r, p};
	}

	sort(uq.begin(), uq.end());
	uq.erase(unique(uq.begin(), uq.end()), uq.end());
	
	int h = uq.size();
	vector<basic_string<int>> e(h);

	for (int i=0; i<k; i++) {
		a[i].r = lower_bound(uq.begin(), uq.end(), a[i].r) - uq.begin();
		e[a[i].r] += i;
	}

	for (int i=0; i<h; i++) {
		node* curr = i ? drva[i-1] : prazno_drvo();
		for (int j : e[i]) {
			// cerr << "drvo " << i << " setujem " << a[j].p << ' ' << a[j].l << '\n';
			curr = sett(curr, a[j].p, a[j].l);
		}
		drva[i] = curr;
	}

	while (m--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		y = upper_bound(uq.begin(), uq.end(), y) - uq.begin();
		y--;
		if (y == -1) {
			cout << "no\n" << flush;
			continue;
		}
		int v = gett(drva[y], a, b);

		// cerr << "upit " << y << ' ' << uq[y] << ' ' << v << " < " << x << '\n';

		if (v < x) {
			cout << "no\n" << flush;
		} else {
			cout << "yes\n" << flush;
		}
	}
}