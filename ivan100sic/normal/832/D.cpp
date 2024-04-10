#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int p[100005][17], d[100005];
vector<int> e[100005];
int l[100005], r[100005], t;

void dfs(int x, int p, int d) {
	t++;
	l[x] = t;

	::p[x][0] = p;
	for (int i=1; i<17; i++) {
		::p[x][i] = ::p[::p[x][i-1]][i-1];
	}
	::d[x] = d;

	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x, d+1);
		}
	}

	r[x] = t;
}

bool iznad(int a, int b) {
	return l[a] <= l[b] && r[b] <= r[a];
}

int lca(int a, int b) {
	if (iznad(a, b)) return a;
	if (iznad(b, a)) return b;

	for (int i=16; i>=0; i--) {
		int c = p[a][i];
		if (!iznad(c, b)) {
			a = c;
		}
	}
	return p[a][0];
}

int dist(int a, int b) {
	int c = lca(a, b);
	return d[a] + d[b] - 2*d[c];
}

int kth(int a, int b, int k) {
	if (k == 0) return a;
	int c = lca(a, b);
	if (k <= d[a] - d[c]) {
		// digni a za k
		for (int i=16; i>=0; i--) {
			if ((1<<i) <= k) {
				a = p[a][i];
				k -= 1<<i;
			}
		}
		return a;
	} else {
		k = dist(a, b) - k;
		// digni b za ~k
		for (int i=16; i>=0; i--) {
			if ((1<<i) <= k) {
				b = p[b][i];
				k -= 1<<i;
			}
		}
		return b;
	}
}

/*

int common_len(int a, int b, int c) {
	// cerr << "qry " << a << ' ' << b << ' ' << c << '\n';
	// posmatrajmo put a-c i vidimo gde on
	// prvo sece b-c

	if (a == b) {
		return dist(a, c) + 1;
	}

	int x = lca(a, b);
	
	//cerr << "lca : " << x << '\n';

	if (x == b) {
		swap(a, b);
	}

	if (x == a) {
		if (!iznad(a, c)) {
			return dist(a, c) + 1;
		}
		if (iznad(c, b)) {
			return 1;
		}
		if (iznad(b, c)) {
			return d[c] - d[b] + 1;
		}

		int y = lca(c, b);
		return d[c] - d[y] + 1;
	}
	

	if (!iznad(x, c)) {
		return dist(x, c) + 1;
	}

	if (iznad(a, c)) {
		return d[c] - d[a] + 1;
	}

	if (iznad(b, c)) {
		return d[c] - d[b] + 1;
	}

	int y = lca(a, c);
	int z = lca(b, c);

	int w = d[y] < d[z] ? y : z;

	return d[c] - d[w] + 1;
}

*/

int common_len(int a, int b, int c) {

	if (a == c || b == c) return 1;
	if (a == b) {
		return dist(a, c) + 1;
	}

	int da = dist(a, c);
	int db = dist(b, c);

	if (da < db) {
		b = kth(b, c, db-da);
	} else {
		a = kth(a, c, da-db);
	}

	int dd = min(da, db);

	if (a == b) {
		return dist(a, c) + 1;
	}

	for (int i=16; i>=0; i--) {
		if ((1 << i) <= dd) {
			int aa = kth(a, c, 1<<i);
			int bb = kth(b, c, 1<<i);

			if (aa != bb) {
				a = aa;
				b = bb;
				dd -= 1 << i;
			}
		}
	}

	return dist(a, c);
}

int main() {
	int q;
	cin >> n >> q;
	for (int i=2; i<=n; i++) {
		int u, v;
		cin >> u;
		v = i;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 1, 0);

	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		int u = common_len(a, b, c);
		int v = common_len(b, c, a);
		int w = common_len(c, a, b);

		// cerr << "ans : " << u << ' ' << v << ' ' << w << '\n';

		cout << max(max(u, v), w) << '\n';
	}
}