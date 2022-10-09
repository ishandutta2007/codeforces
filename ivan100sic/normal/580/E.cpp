#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define uint unsigned

const uint mod1 = 2483928439;
const uint mod2 = 2483928449;
const uint b = 133;

template<uint m>
uint pw(uint x, uint y) {
	if (y == 0)
		return 1;
	uint z = pw<m>(x, y >> 1);
	z = z * 1ull * z % m;
	if (y & 1)
		z = z * 1ull * x % m;
	return z;
}

uint pw1[131073], pw2[131073];

struct hashval {
	uint v1, v2, l;

	hashval() : v1(0), v2(0), l(0) {}

	hashval(uint v1, uint v2, uint l) : v1(v1), v2(v2), l(l) {}

	hashval operator+ (const hashval& b) const {
		hashval t;
		t.v1 = (v1 * 1ull * pw1[b.l] + b.v1) % mod1;
		t.v2 = (v2 * 1ull * pw2[b.l] + b.v2) % mod2;
		t.l = l + b.l;
		return t;
	}

	bool operator== (const hashval& b) const {
		return v1 == b.v1 && v2 == b.v2;
	}
};

uint lvlpw1[20], lvlpw2[20];

hashval rangehash(int lvl, char x) {
	return hashval(
		(uint)(lvlpw1[lvl] * 1ull * x % mod1),
		(uint)(lvlpw2[lvl] * 1ull * x % mod2),
		1u << lvl);
}

const int maxn = 131072;

struct segtree {
	vector<hashval> a;
	string b;

	segtree(string s) : a(2*maxn), b(2*maxn, 0) {
		for (int i=0; i<(int)s.size(); i++) {
			a[i+maxn] = hashval(uint(s[i]), uint(s[i]), 1u);
		}
		for (int i=maxn-1; i>0; i--)
			a[i] = a[2*i] + a[2*i+1];
	}

	void push(int x) {
		if (!b[x])
			return;
		if (x < maxn) {
			b[2*x] = b[x];
			b[2*x+1] = b[x];
		}
		a[x] = rangehash(__builtin_clz(x) - 14, b[x]);
		b[x] = 0;
	}

	hashval query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
		push(x);
		if (r < xl || xr < l)
			return hashval();
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
	}

	void update(int l, int r, char v, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			b[x] = v;
			push(x);
			return;
		}

		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, v, 2*x, xl, xm);
		update(l, r, v, 2*x+1, xm+1, xr);
		a[x] = a[2*x] + a[2*x+1];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pw1[0] = pw2[0] = 1;
	for (int i=1; i<=131072; i++) {
		pw1[i] = pw1[i-1] * 1ull * b % mod1;
		pw2[i] = pw2[i-1] * 1ull * b % mod2;
	}
	lvlpw1[0] = lvlpw2[0] = 1;
	for (int i=1; i<18; i++) {
		lvlpw1[i] = (pw1[1 << (i-1)] + 1ull) * lvlpw1[i-1] % mod1;
		lvlpw2[i] = (pw2[1 << (i-1)] + 1ull) * lvlpw2[i-1] % mod2;
	}

	int n, m, k;
	cin >> n >> m >> k;
	m += k;

	string s;
	cin >> s;
	segtree drvo(s);
	while (m--) {
		int t, l, r, x;
		cin >> t >> l >> r >> x;
		l--, r--;
		if (t == 1) {
			drvo.update(l, r, x+48);
		} else {
			if (drvo.query(l, r-x) == drvo.query(l+x, r))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

}