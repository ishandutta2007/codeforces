// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 1'000'000'007;
typedef modint<mod> mint;

struct trie {
	struct node {
		int e[2];
		int c;

		node() {
			e[0] = e[1] = -1;
			c = 0;
		}
	};

	vector<node> a;

	trie() : a(1) {}

	void add(int x) {
		int y = 0;
		a[y].c += 1;
		for (int i=29; i>=0; i--) {
			int r = (x >> i) & 1;
			if (a[y].e[r] != -1) {
				y = a[y].e[r];
			} else {
				y = a[y].e[r] = a.size();
				a.emplace_back();
			}
			a[y].c += 1;
		}
	}

	int sum(int x, int m) {
		int z = 0;
		int y = 0;
		for (int i=29; i>=0; i--) {
			int l = 0, r = 1;
			if ((m >> i) & 1) swap(l, r);
			int c = (x >> i) & 1;
			if (c) {
				if (a[y].e[l] != -1) {
					z += a[a[y].e[l]].c;
				}
				y = a[y].e[r];
			} else {
				y = a[y].e[l];
			}
			if (y == -1) return z;
		}
		return z;
	}
};

int n;
int a[50005];

// strogo manji od v u xoru
ll manji(int v) {
	trie t;
	ll z = 0;
	for (int i=0; i<n; i++) {
		z += t.sum(v, a[i]);
		t.add(a[i]);
	}
	return z;
}

// suma strogo manjih od v u xoru
mint suma(int v) {
	mint z = 0;
	for (int j=0; j<30; j++) {
		trie t[2];
		for (int i=0; i<n; i++) {
			int b = (a[i] >> j) & 1;
			int c = t[b^1].sum(v, a[i]);
			z += mint(1 << j) * c;
			t[b].add(a[i]);
		}
	}
	return z;
}

// 1-based
int nadji(ll m) {
	int l = 1, r = (1 << 30) - 1, o = 0;
	while (l <= r) {
		int mid = (l+r) / 2;
		if (manji(mid) < m) {
			o = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return o;
}

mint resi(ll m) {
	if (m == 0) return 0;
	int v = nadji(m);
	auto z = manji(v);
	return mint(m-z)*v + suma(v);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ll m;
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i];

	mint sss = 0;
	{
		for (int b=0; b<30; b++) {
			int c[2] = {0, 0};
			for (int i=0; i<n; i++) {
				c[(a[i] >> b) & 1]++;
			}
			sss += mint(1 << b) * c[0] * c[1];
		}
	}

	cout << (sss - resi(n*(n-1ll)/2-m))() << '\n';
}