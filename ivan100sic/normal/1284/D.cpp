#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x, y;

		/* CONSTRUCTOR */
		node_t() : x(2e9), y(-2e9) {}

		node_t(int x, int y) : x(x), y(y) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			x = min(x, other.x);
			y = max(y, other.y);

			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	vector<node_t> a;

	segtree() : a(2*MAXN) {}

	node_t get(int l, int r, int node=1, int nl=0, int nr=MAXN-1) {
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
		pos += MAXN;
		a[pos] += val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

struct compressor {
	vector<int*> v;

	void add(int* x) {
		v.push_back(x);
	}

	int run() {
		sort(v.begin(), v.end(), [](int* x, int* y) { return *x < *y; });
		int k = 0, last = -1;
		for (int i=0; i<(int)v.size(); i++) {
			if (i == 0 || *v[i] != last) {
				k++;
			}
			last = *v[i];
			*v[i] = k;
		}
		return k;
	}
};

segtree<524288> drvo;

struct stvar {
	int a, b, c, d;
	bool operator< (const stvar& x) const {
		if (a != x.a)
			return a < x.a;
		return b > x.b;
	}
};

void no() {
	cout << "NO\n";
	exit(0);
}

void resi(vector<stvar> a) {
	drvo = {};
	sort(a.begin(), a.end());
	for (auto [u, v, p, q] : a) {
		auto rez = drvo.get(u, 123123123);
		if (rez.x < p || rez.y > q)
			no();
		drvo.add(v, {q, p});
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<stvar> a(n);
	compressor cm;
	for (auto& [x, y, z, t] : a) {
		cin >> x >> y >> z >> t;
		cm.add(&x);
		cm.add(&y);
		cm.add(&z);
		cm.add(&t);
	}
	cm.run();
	resi(a);
	for (auto& [x, y, z, t] : a)
		swap(x, z), swap(y, t);
	resi(a);
	cout << "YES\n";
}