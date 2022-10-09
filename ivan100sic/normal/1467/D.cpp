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

mint d[5005][5005], sol;
mint z[5005];
int a[5005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, k, q;
  cin >> n >> k >> q;

  for (int i=1; i<=n; i++) {
    d[0][i] = 1;
  }

  for (int t=0; t<k; t++) {
    for (int i=1; i<=n; i++) {
      if (i) d[t+1][i-1] += d[t][i];
      if (i < n) d[t+1][i+1] += d[t][i];
    }
  }

  for (int t=0; t<=k; t++) {
    for (int i=1; i<=n; i++) {
      z[i] += d[t][i] * d[k-t][i];
    }
  }

  for (int i=1; i<=n; i++) {
    cerr << z[i]() << " \n"[i == n];
  }

  for (int i=1; i<=n; i++) {
    cin >> a[i];
    sol += z[i] * a[i];
  }

  while (q--) {
    int i, x;
    cin >> i >> x;
    sol -= z[i] * a[i];
    a[i] = x;
    sol += z[i] * a[i];
    cout << sol() << '\n';
  }
}