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
		x = (x * 1ll * other.x) % m;
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

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;


const int MAX_SUFFIX_AUTOMATON_SIZE = 600005;

struct node {
	int link, len, cnt;
	map<char, int> next;
} b[MAX_SUFFIX_AUTOMATON_SIZE]; int sz, last;

void extend(char c) {
	int curr = sz++;
	b[curr].len = b[last].len + 1;
	b[curr].cnt = 1;
	int p = last;
	while (p != -1 && b[p].next.count(c) == 0) {
		b[p].next[c] = curr;
		p = b[p].link;
	}

	if (p == -1) {
		b[curr].link = 0;
	} else {
		int q = b[p].next[c];
		if (b[p].len + 1 == b[q].len) {
			b[curr].link = q;
		} else {
			int clone = sz++;
			b[clone].next = b[q].next;
			b[clone].link = b[q].link;
			b[clone].len = b[p].len + 1;
			while (p != -1 && b[p].next[c] == q) {
				b[p].next[c] = clone;
				p = b[p].link;
			}
			b[curr].link = b[q].link = clone;
		}
	}
	last = curr;
}

basic_string<int> topo() {
	basic_string<int> a(sz, 0);
	iota(a.begin(), a.end(), 0);
	sort(a.begin(), a.end(), [&](int i, int j) {
		return b[i].len < b[j].len;
	});
	return a;
}

void clear() {
	fill(b, b+sz, node{0, 0, {}});
	sz = 1;
	last = 0;
	b[0].link = -1;
}

mint z[600005], sol[600005];

void build(string s, int f, basic_string<int> illegal) {
	clear();
	int n = s.size();
	fill(z, z+n+1, mint(0));
	for (char x : s)
		extend(x);
	auto w = topo();
	reverse(w.begin(), w.end());
	for (int x : w) {
		if (x) {
			int l = b[b[x].link].len + 1;
			int r = b[x].len;
			for (int v : illegal) {
				int fv = b[x].len - v;
				if (l <= fv && fv <= r)
					r = fv-1;
			}
			// cerr << "node " << x << " spans " << l << ' ' << r;
			// cerr << " and appears " << b[x].cnt << " times\n";
			mint c3 = mint(b[x].cnt) ^ 3;
			z[l] += c3;
			z[r+1] -= c3;
			b[b[x].link].cnt += b[x].cnt;
		}
	}

	mint t = 0;
	for (int i=1; i<=n; i++) {
		t += z[i];
		sol[i] += t * f;
	}

	// cerr << "~~~~~~~~~~\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b, c;
	cin >> a >> b >> c;
	a += '1';
	b += '2';
	c += '3';
	int p = a.size();
	int q = b.size();
	int r = c.size();
	build(a+b+c, 1, {p-1, p+q-1, p+q+r-1});
	build(a+b, -1, {p-1, p+q-1});
	build(a+c, -1, {p-1, p+r-1});
	build(b+c, -1, {q-1, q+r-1});
	build(a, 1, {p-1});
	build(b, 1, {q-1});
	build(c, 1, {r-1});

	mint inv6 = 166666668;
	// mint inv6 = 1;

	for (int i=1; i<(int)min({p, q, r}); i++)
		cout << (int)(sol[i] * inv6) << ' ';
	cout << '\n';
}