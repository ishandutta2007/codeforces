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

int n, q;
vector<int> e[100005];
int mo[200005], t, l[100005], r[100005];
int a[100005];
int s[100005];
int anc[100005][18];

void dfs(int x, int p) {
	anc[x][0] = p;
	for (int i=1; i<18; i++) {
		anc[x][i] = anc[anc[x][i-1]][i-1];
	}
	mo[++t] = x;
	l[x] = t;
	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x);
		}
	}
	mo[++t] = x;
	r[x] = t;
}

bool iznad(int a, int b) {
	return l[a] <= l[b] && r[b] <= r[a];
}

int lca(int a, int b) {
	if (iznad(a, b)) {
		return a;
	}

	if (iznad(b, a)) {
		return b;
	}

	for (int i=17; i>=0; i--) {
		int aa = anc[a][i];
		if (!iznad(aa, b)) {
			a = aa;
		}
	}
	return anc[a][0];
}

int unutar[100005];
long long rez[100005];

int c[100005][2];
long long sol = 0;

inline void remove(int x) {
	int v = a[x];
	long long oldval = c[v][0] * 1ll * c[v][1];
	c[v][s[x]]--;
	long long nuval = c[v][0] * 1ll * c[v][1];
	sol += nuval - oldval;
}

inline void add(int x) {
	int v = a[x];
	long long oldval = c[v][0] * 1ll * c[v][1];
	c[v][s[x]]++;
	long long nuval = c[v][0] * 1ll * c[v][1];
	sol += nuval - oldval;
}

inline void flipuj(int x) {
	if (unutar[x]) {
		remove(x);
	} else {
		add(x);
	}
	unutar[x] ^= 1;
}

struct upit {
	int l, r, id, lca;

	bool operator< (const upit& other) const {
		return make_pair(l >> 8, r) < make_pair(other.l >> 8, other.r);
	}

} u[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> s[i];
	}

	map<int, int> mp;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		mp[a[i]] = 0;
	}

	{
		int v = 0;
		for (auto& p : mp) {
			p.second = ++v;
		}
	}

	for (int i=1; i<=n; i++) {
		a[i] = mp[a[i]];
	}

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs(1, 1);

	cin >> q;

	for (int i=1; i<=q; i++) {
		int x, y;
		cin >> x >> y;
		u[i].id = i;

		if (iznad(x, y)) {
			u[i].l = l[x];
			u[i].r = l[y];
		} else if (iznad(y, x)) {
			u[i].l = l[y];
			u[i].r = l[x];
		} else {
			int p = lca(x, y);
			if (r[x] <= l[y]) {
				u[i].l = r[x];
				u[i].r = l[y];
			} else {
				u[i].l = r[y];
				u[i].r = l[x];
			}
			u[i].lca = p;
		}
	}

	/*
	for (int i=1; i<=2*n; i++) {
		cerr << "mo " << mo[i] << '\n';
	}
	for (int i=1; i<=n; i++) {
		cerr << "lr " << l[i] << ' ' << r[i] << '\n';
	}
	*/

	sort(u+1, u+q+1);

	int al = 1, ar = 0;
	for (int i=1; i<=q; i++) {
		while (ar < u[i].r) {
			flipuj(mo[++ar]);
		}
		while (al > u[i].l) {
			flipuj(mo[--al]);
		}
		while (ar > u[i].r) {
			flipuj(mo[ar--]);
		}
		while (al < u[i].l) {
			flipuj(mo[al++]);
		}

		if (u[i].lca) {
			flipuj(u[i].lca);
		}

		/*

		cerr << al << ' ' << ar << '\n';
		cerr << u[i].l << ' ' << u[i].r << '\n';
		for (int i=al; i<=ar; i++) {
			cerr << mo[i] << '\n';
		}

		*/

		rez[u[i].id] = sol;

		if (u[i].lca) {
			flipuj(u[i].lca);
		}
	}

	for (int i=1; i<=q; i++) {
		cout << rez[i] << '\n';
	}
}