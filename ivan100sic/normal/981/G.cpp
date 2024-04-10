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
struct segtree_lazy {

	struct updater {
		/* DATA MEMBERS */
		mint k, b;

		updater(mint k = 1, mint b = 0) : k(k), b(b) {}

		updater operator+ (const updater& other) const {
			return updater(k * other.k, other.b + b * other.k);
		}

		updater& operator+= (const updater& other) {
			return *this = *this + other;
		}

		operator bool () const {
			return k != 1 || b != 0;
		}
	};
	
	struct node_t {
		/* DATA MEMBERS */
		mint sum;
		int len;

		/* CONSTRUCTOR */
		node_t() : sum(0), len(0) {}

		node_t(int sum, int len = 1) : sum(sum), len(len) {}

		node_t& operator+= (const node_t& other) {
			sum += other.sum;
			len += other.len;
			return *this;
		}

		node_t& operator+= (const updater& other) {
			sum = other.k * sum + other.b * len;
			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];
	updater b[2*MAXN];

	void init() {
		for (int i=1; i<=MAXN; i++)
			a[i + MAXN - 1] = node_t(0);
		for (int i=MAXN-1; i>0; i--)
			a[i] = a[2*i] + a[2*i+1];
	}

	void push(int i) {
		if (b[i]) {
			a[i] += b[i];
			if (i < MAXN) {
				b[2*i] += b[i];
				b[2*i+1] += b[i];
			}
			b[i] = updater();
		}
	}

	node_t get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		push(node);

		if (r < nl || nr < l) {
			return node_t();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void update(int l, int r, updater val, int node=1, int nl=1, int nr=MAXN) {
		push(node);

		if (r < nl || nr < l) {
			return;
		}
		if (l <= nl && nr <= r) {
			b[node] += val;
			push(node);
			return;
		}

		int nm = (nl + nr) >> 1;
		update(l, r, val, 2*node, nl, nm);
		update(l, r, val, 2*node+1, nm+1, nr);
		a[node] = a[2*node] + a[2*node+1];
	}
};

int n;
segtree_lazy<262144> drvo;
set<pair<int, int>> seg[200005];

vector<pair<int, int>> rupe(int l, int r, int x) {
	auto& s = seg[x];
	vector<pair<int, int>> rez;
	vector<pair<int, int>> bitni;

	auto it = s.lower_bound({l, -1});
	if (it != s.begin())
		--it;
	while (it != s.end() && !(r < it->first)) {
		bitni.push_back(*it);
		s.erase(it++);
	}

	if (bitni.size() == 0) {
		s.insert({l, r});
		return {{l, r}};
	}

	for (int i=1; i<(int)bitni.size(); i++) {
		int lu = bitni[i-1].second + 1;
		int ru = bitni[i].first - 1;

		int lx = max(lu, l);
		int rx = min(ru, r);
		if (lx <= rx) {
			rez.emplace_back(lx, rx);
		}
	}


	{
		int lu = 1;
		int ru = bitni[0].first - 1;

		int lx = max(lu, l);
		int rx = min(ru, r);
		if (lx <= rx) {
			rez.emplace_back(lx, rx);
		}
	}

	{
		int lu = bitni.back().second + 1;
		int ru = n;

		int lx = max(lu, l);
		int rx = min(ru, r);
		if (lx <= rx) {
			rez.emplace_back(lx, rx);
		}
	}

	bitni.emplace_back(l, r);
	sort(begin(bitni), end(bitni));

	int lx = -1, rx = -1;
	for (auto [l, r] : bitni) {
		if (l > rx + 1) {
			if (rx != -1)
				s.insert({lx, rx});
			lx = l;
			rx = r;
		} else {
			rx = max(rx, r);
		}
	}

	if (rx != -1)
		s.insert({lx, rx});

	return rez;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> n >> q;
	drvo.init();
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			drvo.update(l, r, {2, 0});
			auto v = rupe(l, r, x);
			// cerr << "\nrupe = ";
			// for (auto [l, r] : v)
			// 	cerr << l << ' ' << r << ',';
			// cerr << '\n';
			for (auto [l, r] : v)
				drvo.update(l, r, {499122177, 1});
		} else {
			int l, r;
			cin >> l >> r;
			cout << (int)drvo.get(l, r).sum << '\n';
		}
	}
}