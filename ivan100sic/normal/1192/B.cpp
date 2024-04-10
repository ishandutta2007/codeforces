#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct lazysegtree {
	vector<ll> a, b;
	int maxn;

	lazysegtree(int n = 1) {
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.resize(2*maxn);
		b.resize(2*maxn);
	}

	void push(int x) {
		if (!b[x])
			return;
		if (x < maxn) {
			b[2*x] += b[x];
			b[2*x+1] += b[x];
		}
		a[x] += b[x];
		b[x] = 0;
	}

	void update(int l, int r, ll v, int x, int xl, int xr) {
		if (r < xl || xr < l) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			b[x] += v;
			push(x);
			return;
		}
		int xm = (xl+xr) >> 1;
		push(x);
		update(l, r, v, 2*x, xl, xm);
		update(l, r, v, 2*x+1, xm+1, xr);
		a[x] = max(a[2*x], a[2*x+1]);
	}

	void update(int l, int r, ll v) {
		update(l, r, v, 1, 0, maxn-1);
	}

	ll query() {
		push(1);
		return a[1];
	}
};

int n, q;
ll wmod;
int u[100005], v[100005];
ll w[100005];
basic_string<int> e[100005];
bool blocked[100005];

inline int adj(int i, int x) {
	return u[i] ^ v[i] ^ x;
}

int dfs1(int x, int p) {
	int sz = 1;
	for (int i : e[x]) {
		int y = adj(i, x);
		if (y == p || blocked[y])
			continue;
		sz += dfs1(y, x);
	}
	return sz;
}

int dfs2(int x, int p, int tree_sz, int& centroid) {
	int my_sz = 1;
	bool ok = true;
	for (int i : e[x]) {
		int y = adj(i, x);
		if (y == p || blocked[y])
			continue;
		int t = dfs2(y, x, tree_sz, centroid);
		my_sz += t;
		if (2*t > tree_sz)
			ok = false;
	}
	int gore = tree_sz - my_sz;
	if (2*gore > tree_sz)
		ok = false;
	if (ok)
		centroid = x;
	return my_sz;
}

int el[20][100005], er[20][100005], echid[20][100005];
int edub[20][100005], eroot[20][100005];

void dfs3(int x, int p, int& t, int child_id, int lvl, int dub, int root) {
	el[lvl][x] = t++;
	echid[lvl][x] = child_id;
	edub[lvl][x] = dub;
	eroot[lvl][x] = root;
	for (int i : e[x]) {
		int y = adj(i, x);
		if (y == p || blocked[y])
			continue;
		dfs3(y, x, t, child_id, lvl, dub+1, root);
	}
	er[lvl][x] = t;
}

vector<lazysegtree> drva[100005];
multiset<ll> veze[100005], master;

void subtree(int x, int lvl) {
	eroot[lvl][x] = x;
	int ch = 0;
	for (int i : e[x]) {
		int y = adj(i, x);
		if (blocked[y])
			continue;
		int t = 0;
		dfs3(y, x, t, ch, lvl, 1, x);
		// cerr << "ST " << x << ' ' << lvl << " smer " << y << " sz " << t << '\n';
		drva[x].emplace_back(t);
		veze[x].insert(0);
		ch++;
	}
	master.insert(0);
}

void centroid(int x, int lvl) {
	int sz = dfs1(x, x);
	int cvor = x;
	dfs2(x, x, sz, cvor);
	blocked[cvor] = 1;
	subtree(cvor, lvl);
	for (int i : e[cvor]) {
		int y = adj(i, cvor);
		if (blocked[y])
			continue;
		centroid(y, lvl+1);
	}
}

ll dva(multiset<ll>& a) {
	if (a.size() >= 2)
		return *--a.end() + *-- -- a.end();
	else if (a.size() == 1)
		return *--a.end();
	return 0;
}

void delta(int i, ll delta_w) {
	for (int lvl=0; lvl<20; lvl++) {
		int x = u[i], y = v[i];

		// cerr << x << ' ' << y << ' ' << eroot[lvl][x] << ' ' << eroot[lvl][y];
		// cerr << ' ' << delta_w << '\n';

		if (eroot[lvl][x] != eroot[lvl][y])
			return; // mozda continue?

		int dx = edub[lvl][x];
		int dy = edub[lvl][y];

		if (dx < dy) {
			swap(x, y);
			swap(dx, dy);
		}

		// dx i dy ne vaze vise, x treba upd
		int chid = echid[lvl][x], root = eroot[lvl][x];
		ll old = drva[root][chid].query();

		// cerr << "suck it " << root << ' ' << chid << ' ' << el[lvl][x] <<
			// ' ' << er[lvl][x]-1 << ' ' << delta_w << ' ' << x <<
			// ' ' << y << ' ' << dx << ' ' << dy << '\n';

		drva[root][chid].update(el[lvl][x], er[lvl][x]-1, delta_w);
		ll nu = drva[root][chid].query();

		// cerr << "cu brisnem " << (dva(veze[root])) << '\n';
		// cerr << "veze promena " << old << " --> " << nu << '\n';

		master.erase(master.find(dva(veze[root])));
		veze[root].erase(veze[root].find(old));
		veze[root].insert(nu);
		master.insert(dva(veze[root]));

		// cerr << "cu dodam " << (dva(veze[root])) << '\n';
	}
}

void update(int i, ll nw) {
	delta(i, nw - w[i]);
	w[i] = nw;
}

void preprocess() {
	centroid(1, 0);
	for (int i=0; i<n-1; i++)
		delta(i, w[i]);
}

ll diameter() {
	return *master.rbegin();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q >> wmod;
	for (int i=0; i<n-1; i++) {
		cin >> u[i] >> v[i] >> w[i];
		e[u[i]] += i;
		e[v[i]] += i;
	}

	cerr << u[0] << ' ' << v[0] << ' ' << w[0] << '\n';

	preprocess();

	cerr << u[0] << ' ' << v[0] << ' ' << w[0] << '\n';

	ll last = 0;
	while (q--) {
		int grana; ll tez;
		cin >> grana >> tez;
		grana = (grana + last) % (n-1);
		tez = (tez + last) % wmod;
		update(grana, tez);
		cout << (last = diameter()) << '\n';
	}
}