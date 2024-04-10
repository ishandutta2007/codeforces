// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T, class D, class G, class F = plus<D>>
struct tree_dp {
	vector<T> a;
	D e;
	vector<D> up, dn, rt;
	F f;
	G g;
	vector<int> p;
	vector<vector<int>> h;

	tree_dp(const vector<T>& a, D e, G g, F f = F()) : a(a), e(e),
		up(a.size()), dn(a.size()), f(f), g(g), p(a.size()), h(a.size()) {}

	void add_edge(int x, int y) {
		h[x].push_back(y);
		h[y].push_back(x);
	}

	void dfs1(int x) {
		D d = e;
		for (int y : h[x]) {
			if (y == p[x])
				continue;
			p[y] = x;
			dfs1(y);
			d = f(d, dn[y]);
		}
		dn[x] = g(d, a[x]);
	}

	void dfs2(int x) {
		D d = x ? up[x] : e, t = e;
		int m = h[x].size() - !!x;
		vector<D> pref(m, e);
		int i = 0;
		for (int y : h[x]) {
			if (y == p[x])
				continue;
			pref[i++] = t;
			t = f(t, dn[y]);
		}
		t = e;
		for (int j=(int)h[x].size()-1; j>=0; j--) {
			int y = h[x][j];
			if (y == p[x])
				continue;
			i--;
			up[y] = g(f(pref[i], f(d, t)), a[x]);
			t = f(t, dn[y]);
		}
		for (int y : h[x])
			if (y != p[x])
				dfs2(y);
	}

	void finish() {
		rt.resize(a.size());
		rt[0] = dn[0];
		for (int x=1; x<(int)a.size(); x++) {
			D d = up[x];
			for (int y : h[x])
				if (y != p[x])
					d = f(d, dn[y]);
			rt[x] = g(d, a[x]);
		}
	}

	D operator() (int x) {
		if (rt.empty()) {
			dfs1(0);
			dfs2(0);
			finish();
		}
		return rt[x];
	}
};

struct val {
	int s=-123123123, b=-123123123, c=0;

	val operator+ (const val& o) const {
		return {max(s, o.s), max(b, o.b), c+o.c};
	}
};

val extend(val v, bool) {
	if (v.c)
		return {1 + v.b, max(v.s, v.b) + v.c - 1, 1};
	else
		return {1, 0, 1};
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;
	vector<bool> a(n);
	tree_dp d(a, val{}, extend);
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		d.add_edge(x, y);
	}
	int sol = 0;
	for (int i=0; i<n; i++)
		sol = max({sol, d(i).s, d(i).b});
	cout << sol << '\n';
}