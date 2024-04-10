#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	int sum;
	node* l;
	node* r;

	node() : sum(0), l(0), r(0) {}
};

int getsum(node* x, ll l, ll r, ll xl, ll xr) {
	if (!x || r < xl || xr < l)
		return 0;
	if (l <= xl && xr <= r)
		return x->sum;
	ll xm = (xl+xr) >> 1;
	return getsum(x->l, l, r, xl, xm)
		+ getsum(x->r, l, r, xm+1, xr);
}

node* ubaci(node* x, ll xl, ll xr, ll p) {
	if (!x)
		x = new node;
	x->sum++;
	if (xl == xr)
		return x;

	ll xm = (xl+xr) >> 1;
	if (p <= xm)
		x->l = ubaci(x->l, xl, xm, p);
	else
		x->r = ubaci(x->r, xm+1, xr, p);
	return x;
}

node* drva[11005];
int n, k;

struct tacka {
	int x, r, f;
	bool operator< (const tacka& b) const {
		return r > b.r;
	}
};

tacka a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].r >> a[i].f;
		a[i].f += 15;
	}

	sort(a, a+n);
	ll sol = 0;
	for (int i=0; i<n; i++) {
		auto [X, R, F] = a[i];
		for (int f=F-k; f<=F+k; f++) {
			sol += getsum(drva[f], X-R, X+R, 1, 1e9);
		}
		drva[F] = ubaci(drva[F], 1, 1e9, X);
	}
	cout << sol << "\n";
}