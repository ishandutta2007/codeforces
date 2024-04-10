#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// cu ga optimizujem sutra, za sada da vidim da li je to to
struct brut_solver {
	int n, m, k;

	vector<basic_string<int>> e;
	vector<int> d, w;

	void solve() {
		cin >> n >> m >> k;
		e.assign(n+1, {});
		d.assign(n+1, 0);
		w.assign(n+1, 0);
		for (int i=2; i<=n; i++) {
			int p;
			cin >> p;
			e[p] += i;
		}
		for (int i=0; i<m; i++) {
			int v, d, w;
			cin >> v >> d >> w;
			this->d[v] = d;
			this->w[v] = w;
		}
		cout << dfs(1)[k] << '\n';
	}

	vector<ll> dfs(int x) {
		vector<ll> r(k+1, 0);
		for (int y : e[x]) {
			auto t = dfs(y);
			for (int i=0; i<=k; i++)
				r[i] += t[i];
		}
		if (w[x]) {
			ll q = r[d[x]] + w[x];
			for (int i=d[x]; i<=k; i++)
				r[i] = max(r[i], q);
		}
		return r;
	}
};

int n, m, k;
basic_string<int> e[100005];
int d[100005], w[100005];

struct node {
	ll low, hi, add, lim;
	int sz, l, r;
};

const int H = 10000000;
node b[10000000];
int lst_begin;

int new_node() {
	int t = lst_begin;
	lst_begin = b[lst_begin].r;
	memset(b+t, 0, sizeof(node));
	return t;
}

void delete_node(int t) {
	b[t].r = lst_begin;
	lst_begin = t;
}

// t != 0, read-only
void push(int t) {
	if (b[t].l) {
		b[b[t].l].lim = max(b[b[t].l].lim, b[t].lim);
		b[b[t].r].lim = max(b[b[t].r].lim, b[t].lim);
		b[b[t].l].add += b[t].add;
		b[b[t].r].add += b[t].add;
	}

	b[t].low = max(b[t].low + b[t].add, b[t].lim);
	b[t].hi  = max(b[t].hi  + b[t].add, b[t].lim);
	b[t].add = b[t].lim = 0;
}

void pull(int t) {
	b[t].low = min(b[b[t].l].low, b[b[t].r].low);
	b[t].hi  = max(b[b[t].l].hi , b[b[t].r].hi );
	b[t].sz  = b[b[t].l].sz + b[b[t].r].sz + 1;
}

// t != 0, read-only
ll extract_val(int t, int p, int xl, int xr) {
	push(t);
	if (b[t].l) {
		int xm = (xl+xr) >> 1;
		if (p <= xm)
			return extract_val(b[t].l, p, xl, xm);
		else
			return extract_val(b[t].r, p, xm+1, xr);
	} else {
		return b[t].low;
	}
}

void recursive_delete(int t) {
	if (!t) return;
	recursive_delete(b[t].l);
	recursive_delete(b[t].r);
	delete_node(t);
}

void extend(int t) {
	b[t].l = new_node();
	b[t].r = new_node();
	b[b[t].l].low = b[b[t].l].hi = b[t].low;
	b[b[t].r].low = b[b[t].r].hi = b[t].low;
}

// t != 0
void limit_suffix(int& t, int p, ll v, int xl, int xr) {
	push(t);
	if (v <= b[t].low || xr < p)
		return;
	if (v >= b[t].hi && p <= xl) {
		recursive_delete(t);
		t = new_node();
		b[t].low = b[t].hi = v;
		b[t].sz = 1;
	} else {
		if (!b[t].l)
			extend(t);
		int xm = (xl+xr) >> 1;
		limit_suffix(b[t].l, p, v, xl, xm);
		limit_suffix(b[t].r, p, v, xm+1, xr);
		pull(t);
	}
}

// p != 0, q != 0
void merge_trees(int p, int q) {
	push(q);
	if (b[q].l) {
		push(p);
		if (!b[p].l)
			extend(p);
		merge_trees(b[p].l, b[q].l);
		merge_trees(b[p].r, b[q].r);
		pull(p);
	} else {
		b[p].add += b[q].low;
		push(p);
	}
}

// p != 0, q != 0
int add_trees(int p, int q) {
	if (b[p].sz < b[q].sz)
		swap(p, q);
	merge_trees(p, q);
	recursive_delete(q);
	return p;
}

int new_empty() {
	int t = new_node();
	b[t].sz = 1;
	return t;
}

/*
vector<ll> dfs(int x) {
	vector<ll> r(k+1, 0);
	for (int y : e[x]) {
		auto t = dfs(y);
		for (int i=0; i<=k; i++)
			r[i] += t[i];
	}
	if (w[x]) {
		ll q = r[d[x]] + w[x];
		for (int i=d[x]; i<=k; i++)
			r[i] = max(r[i], q);
	}
	return r;
}
*/

int dfs(int x) {
	int r = new_empty();
	for (int y : e[x]) {
		int t = dfs(y);
		r = add_trees(r, t);
	}
	if (w[x]) {
		ll q = extract_val(r, d[x], 1, k) + w[x];
		limit_suffix(r, d[x], q, 1, k);
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// brut_solver().solve();

	cin >> n >> m >> k;
	for (int i=2; i<=n; i++) {
		int p;
		cin >> p;
		e[p] += i;
	}
	for (int i=0; i<m; i++) {
		int v, d, w;
		cin >> v >> d >> w;
		::d[v] = d;
		::w[v] = w;
	}

	for (int i=1; i<H-1; i++)
		b[i].r = i+1;
	lst_begin = 1;

	cout << b[dfs(1)].hi << '\n'; 
}