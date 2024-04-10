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

const int mod = 998'244'353;
typedef modint<mod> mint;

mint solve(string a) {
	mint w0 = 1, w1 = 0, d0 = 0, d1 = 0;
	for (char c : a) {
		if (c == '*') {
			w0 += w1;
			w1 = 0;
			d0 += d1;
			d1 = 0;
		} else {
			mint w0p, w1p, d0p, d1p;

			// farbam u dobru
			w0p += w1;
			w1p += w0;
			d0p += d1 + w1;
			d1p += d0;

			// farbam u losu
			w0p += w0 + w1;
			d0p += d0 + d1;

			// vrati
			w0 = w0p;
			w1 = w1p;
			d0 = d0p;
			d1 = d1p;
		}
	}

	return d0 + d1;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, m, white = 0;
  cin >> n >> m;
  vector<string> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
    white += count(begin(a[i]), end(a[i]), 'o');
  }

	mint sol;
	for (int i=0; i<n; i++) {
		sol += solve(a[i]) * (mint(2) ^ (white - count(begin(a[i]), end(a[i]), 'o')));
	}

	for (int i=0; i<m; i++) {
		string b(n, 0);
		transform(begin(a), end(a), begin(b), [&](auto& r) { return r[i]; });
		sol += solve(b) * (mint(2) ^ (white - count(begin(b), end(b), 'o')));
	}

	cout << sol() << "\n";
}