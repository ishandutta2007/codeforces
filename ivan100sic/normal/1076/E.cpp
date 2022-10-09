#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[300005];
int l[300005], r[300005], t, poc[600005];
int d[300005];

void dfs(int x, int p) {
	l[x] = ++t;
	poc[t] = x;
	for (int y : e[x]) {
		if (y != p) {
			d[y] = d[x] + 1;
			dfs(y, x);
		}
	}
	r[x] = ++t;
}

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void add(int pos, const T& val) {
		pos = min(pos, size-1);
		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		pos = min(pos, size-1);
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<ll, (1 << 20) + 1> drvo;

struct upit {
	int lim, x;
};

basic_string<upit> f[600005];
ll ans[600005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	d[1] = 1;
	dfs(1, 1);

	int q;
	cin >> q;
	for (int i=0; i<q; i++) {
		int v, d, x;
		cin >> v >> d >> x;
		int L = l[v];
		int R = r[v];
		int D = d + ::d[v];

		f[L] += {D, x};
		f[R] += {D, -x};
	}

	for (int i=1; i<=2*n; i++) {
		for (auto u : f[i]) {
			drvo.add(u.lim, u.x);
		}
		if (poc[i]) {
			int x = poc[i];
			ans[x] = drvo.sum(1 << 20) - drvo.sum(d[x]-1);
		}
	}

	for (int i=1; i<=n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}