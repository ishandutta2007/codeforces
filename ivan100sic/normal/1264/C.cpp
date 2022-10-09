#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int m>
struct modint {

	unsigned x;

	modint() : x(0) {}

	modint(long long arg) {
		arg %= m;
		if (arg < 0) {
			x = arg + m;
		} else {
			x = arg;
		}
	}	

	modint& operator+= (const modint& other) {
		x += other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint& operator*= (const modint& other) {
		x = (x * 1ull * other.x) % m;
		return *this;
	}

	modint& operator-= (const modint& other) {
		x += m - other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint operator+ (const modint& other) const {
		modint tmp = *this;
		tmp += other;
		return tmp;
	}

	modint operator- (const modint& other) const {
		modint tmp = *this;
		tmp -= other;
		return tmp;
	}

	modint operator* (const modint& other) const {
		modint tmp = *this;
		tmp *= other;
		return tmp;
	}

	explicit operator int () const {
		return x;
	}

	modint& operator++ () {
		++x;
		if (x == m) {
			x = 0;
		}
		return *this;
	}

	modint& operator-- () {
		if (x == 0) {
			x = m-1;
		} else {
			--x;
		}
		return *this;
	}

	modint operator++ (int) {
		modint tmp = *this;
		++*this;
		return tmp;
	}

	modint operator-- (int) {
		modint tmp = *this;
		--*this;
		return tmp;
	}

	bool operator== (const modint& other) const {
		return x == other.x;
	}

	bool operator!= (const modint& other) const {
		return x != other.x;
	}

	template<class T>
	modint operator^ (T arg) const {
		if (arg == 0) {
			return 1;
		}
		if (arg == 1) {
			return x;
		}
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1) {
			t *= *this;
		}
		return t;
	}

	template<class T>
	modint operator^= (T arg) {
		return *this = *this ^ arg;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 998244353;
typedef modint<MOD> mint;

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		mint p, q;

		/* CONSTRUCTOR */
		node_t(mint p = 0, mint q = 1) : p(p), q(q) {}

		node_t& operator+= (const node_t& other) {
			return *this = *this + other;
		}

		node_t operator+ (const node_t& other) const {
			return node_t(p + q * other.p, q * other.q);
		}

		mint val() const {
			return p * q.inv();
		}
	};

	node_t a[2*MAXN];

	void init(int* prob, int n) {
		mint inv100 = mint(100).inv();
		for (int i=1; i<=n; i++)
			a[i + MAXN - 1] = node_t(1, inv100 * prob[i]);
		for (int i=MAXN-1; i>0; i--)
			a[i] = a[2*i] + a[2*i+1];
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
};

struct stvar {
	int l, r;
	mint v;

	bool operator< (const stvar& b) const {
		return l < b.l;
	}
};

set<stvar> s;
segtree<262144> drvo;

int n, q;
int a[200005];
bool ziv[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	drvo.init(a, n);
	s.insert({1, n, drvo.get(1, n).val()});
	mint svi = drvo.get(1, n).val();

	while (q--) {
		int x;
		cin >> x;
		if (!ziv[x]) {
			auto it = --s.lower_bound({x, x, {}});
			svi -= it->v;
			int l = it->l;
			int r = it->r;
			s.erase(it);
			auto v1 = drvo.get(l, x-1).val();
			auto v2 = drvo.get(x, r).val();
			svi += v1 + v2;
			s.insert({l, x-1, v1});
			s.insert({x, r, v2});
			ziv[x] = 1;
		} else {
			auto it2 = s.lower_bound({x, x, {}});
			auto it1 = prev(it2);

			svi -= it1->v + it2->v;

			int l = it1->l;
			int r = it2->r;

			s.erase(it1);
			s.erase(it2);

			auto v = drvo.get(l, r).val();

			s.insert({l, r, v});
			svi += v;

			ziv[x] = 0;
		}

		cout << (int)svi << '\n';
	}
}