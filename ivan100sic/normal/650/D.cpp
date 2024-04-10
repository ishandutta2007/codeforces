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

const int MOD = 1'644'441'343;
typedef modint<MOD> mint;

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x;
		mint c;

		/* CONSTRUCTOR */
		node_t() : x(-1), c(0) {}

		node_t(int x, mint c) : x(x), c(c) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			if (x == other.x) {
				c += other.c;
			} else if (other.x > x) {
				*this = other;
			}

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

segtree<(1 << 20)> drvo;

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

int n, q;
int a[400005], qx[400005], qy[400005], ans[400005];
int bez[400005];
basic_string<int> f[400005];
mint wf[400005], wb[400005];
int ww[400005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	compressor e;
	for (int i=1; i<=n; i++)
		cin >> a[i], e.add(a+i);
	for (int i=0; i<q; i++)
		cin >> qx[i] >> qy[i], e.add(qy+i), f[qx[i]] += i;

	e.run();

	// cerr << "a[0] = " << a[1] << '\n';

	drvo.add(0, {0, 1});
	for (int i=1; i<=n; i++) {
		for (int j : f[i])
			ans[j] += drvo.get(0, qy[j]-1).x;
		auto g = drvo.get(0, a[i]-1);
		g.x++;
		// cerr << "? " << i << ' ' << g.x << ' ' << (int)g.c << '\n';
		wf[i] = g.c;
		ww[i] += g.x;
		drvo.add(a[i], g);
	}

	drvo = decltype(drvo)();
	drvo.add(800004, {0, 1});

	for (int i=n; i>=1; i--) {
		for (int j : f[i])
			ans[j] += drvo.get(qy[j]+1, 1123123123).x + 1;
		auto g = drvo.get(a[i]+1, 1123123123);
		g.x++;
		wb[i] = g.c;
		ww[i] += g.x - 1;
		drvo.add(a[i], g);
	}

	auto [lis, br] = drvo.get(0, 1123123123);
	// cerr << "! " << lis << ' ' << (int)br << '\n';

	for (int i=0; i<q; i++) {
		int j = qx[i];
		int z = ww[j] == lis && wf[j] * wb[j] == br ? lis - 1 : lis;
		// cerr << "maybe " << z << '\n';
		cout << max(z, ans[i]) << '\n';
	}
}