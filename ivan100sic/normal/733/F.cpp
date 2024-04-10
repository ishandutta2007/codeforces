#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int c[200005], w[200005], u[200005], v[200005];

struct dsu_t {
	int* p;
	int* s;

	dsu_t (int n) {
		p = new int[n+1];
		s = new int[n+1];

		for (int i=1; i<=n; i++) {
			p[i] = i;
			s[i] = 0;
		}
	}

	int endp(int x) {
		if (x != p[x]) {
			p[x] = endp(p[x]);
		}
		return p[x];
	}

	bool same(int a, int b) {
		return endp(a) == endp(b);
	}

	void merge(int a, int b) {
		a = endp(a);
		b = endp(b);

		if (s[a] > s[b]) swap(a, b);
		s[b] += s[a];
		p[a] = b;
	}

	~dsu_t() {
		delete[] p;
		delete[] s;
	}
};

int global_reduction_lb;

struct edge {
	int idx, u, v, cost, reduction;

	int val() const {
		if (reduction >= global_reduction_lb) {
			return cost - reduction;
		} else {
			return cost;
		}
	}

	bool operator< (const edge& other) const {
		return val() < other.val();
	}
};

edge e[200005];
int ia[200005];
int reduced_idx;

int calc_tree(int reduction_lb) {
	global_reduction_lb = reduction_lb;
	sort(e+1, e+m+1);

	int tree = 0, reduced = 0;
	dsu_t* dsu = new dsu_t(n);

	reduced_idx = 0;

	// cerr << reduction_lb << ' ';

	for (int i=1; i<=m; i++) {
		// cerr << e[i].val() << ' ';
		if (!dsu->same(e[i].u, e[i].v)) {
			dsu->merge(e[i].u, e[i].v);
			ia[++tree] = e[i].idx;
			if (e[i].reduction >= reduction_lb && !reduced) {
				reduced++;
				reduced_idx = e[i].idx;
				global_reduction_lb = 2000000000;
				sort(e+i+1, e+m+1);
			}
		}
		if (tree == n-1) break;
	}
	// cerr << '\n';
	
	delete dsu;
	return reduced;
}

int main() {
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> w[i];
	}
	for (int i=1; i<=m; i++) {
		cin >> c[i];
	}
	for (int i=1; i<=m; i++) {
		cin >> u[i] >> v[i];
	}

	
	int k;
	cin >> k;
	for (int i=1; i<=m; i++) {
		e[i].idx = i;
		e[i].u = u[i];
		e[i].v = v[i];
		e[i].cost = w[i];
		e[i].reduction = k / c[i];
	}
	

	long long l = -2000000000, r = 2000000000, o = -2000000001;

	while (l <= r) {
		int m = (l+r) / 2;
		cerr << "bs : " << l << ' ' << r << ' ' << m << '\n';
		int used_reduced_edges = calc_tree(m);
		if (used_reduced_edges >= 1) {
			o = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}

	cerr << "o : " << o << '\n';

	calc_tree(o);

	long long total = 0;

	for (int i=1; i<n; i++) {
		int j = ia[i];
		if (j == reduced_idx) {
			total += w[j] - k / c[j];
		} else {
			total += w[j];
		}
	}

	cout << total << '\n';

	for (int i=1; i<n; i++) {
		int j = ia[i];
		cout << j << ' ';
		if (j == reduced_idx) {
			cout << w[j] - k / c[j] << '\n';
		} else {
			cout << w[j] << '\n';
		}
	}

}