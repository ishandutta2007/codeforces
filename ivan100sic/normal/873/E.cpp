#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> a;

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x;
		int pos;

		/* CONSTRUCTOR */
		node_t() : x(-1), pos(0) {}

		node_t(int x, int pos) : x(x), pos(pos) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			if (x < other.x) {
				x = other.x;
				pos = other.pos;
			}

			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];

	void init() {
		for (int i=1; i<=n-1; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = node_t(::a[i-1].first - ::a[i].first, i);
		}

		a[n + MAXN - 1] = node_t(::a[n-1].first, n);

		for (int i=n+1; i<=MAXN; i++) {
			a[i + MAXN - 1] = node_t();
		}
		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	node_t get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return node_t();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void add(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] += val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}

	void set(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

segtree<131072> drvo;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a.push_back({x, i});
	}
	sort(a.begin(), a.end(), greater<pair<int, int>>());

	vector<int> sol_vals = {-1, -1, -1};
	vector<int> sol_sizes = {-1, -1, -1};

	

	drvo.init();

	cerr << "here\n";

	for (int i=1; i<=n; i++) {

		for (int j=1; j<=n-i; j++) {

			if (j > 2*i || i > 2*j) {
				continue;
			}

			int k_lo = max((i+1)/2, (j+1)/2);
			int k_hi = min(2*i, 2*j);

			k_lo = max(k_lo, 1);
			k_hi = min(k_hi, n-i-j);

			if (k_lo > k_hi) {
				continue;
			}

			// cerr << i << ' ' << j << ' ' << k_lo << ' ' << k_hi << '\n';

			auto best = drvo.get(i+j+k_lo, i+j+k_hi);
			int k = best.pos - i - j;
			int val = best.x;

			vector<int> vals = {
				a[i-1].first - a[i].first,
				a[i+j-1].first - a[i+j].first,
				val
			};


			vector<int> sizes = {i, j, k};

			if (vals > sol_vals) {
				sol_vals = vals;
				sol_sizes = sizes;
			}
		}
	}

	cerr << "sol\n";
	cerr << sol_sizes[0] << ' ' << sol_sizes[1] << ' ' << sol_sizes[2] << '\n';

	for (int i=0; i<sol_sizes[0]; i++) {
		a[i].first = 1;
	}
	for (int i=sol_sizes[0]; i<sol_sizes[0] + sol_sizes[1]; i++) {
		a[i].first = 2;
	}
	for (int i=sol_sizes[0] + sol_sizes[1];
			i<sol_sizes[0] + sol_sizes[1] + sol_sizes[2]; i++) {
		a[i].first = 3;
	}
	for (int i=sol_sizes[0] + sol_sizes[1] + sol_sizes[2]; i<n; i++) {
		a[i].first = -1;
	}

	for (auto& p : a) {
		swap(p.first, p.second);
	}

	sort(a.begin(), a.end());

	for (auto p : a) {
		cout << p.second << ' ';
	}
}