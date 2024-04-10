#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void add(int pos, const T& val) {
		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<ll, 400005> drvo_par;
fenwick<ll, 400005> drvo_nepar;

int n, q;
int a[200005];
basic_string<int> e[200005];
int l[200005], r[200005], d[200005], t;

void dfs(int x) {
	l[x] = ++t;
	for (int y : e[x])
		if (l[y] == 0) {
			d[y] = d[x] + 1;
			dfs(y);
		}
	r[x] = ++t;
}

void prop(int x, int val) {
	if (d[x] & 1) {
		drvo_nepar.add(l[x], val);
		drvo_nepar.add(r[x], -val);

		drvo_par.add(l[x], -val);
		drvo_par.add(r[x], val);
	} else {
		drvo_nepar.add(l[x], -val);
		drvo_nepar.add(r[x], val);

		drvo_par.add(l[x], val);
		drvo_par.add(r[x], -val);
	}
}

int get(int x) {
	if (d[x] & 1)
		return drvo_nepar.sum(l[x]);
	else
		return drvo_par.sum(l[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	dfs(1);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, val;
			cin >> x >> val;
			prop(x, val);
		} else {
			int x;
			cin >> x;
			cout << get(x) + a[x] << '\n';
		}
	}
}