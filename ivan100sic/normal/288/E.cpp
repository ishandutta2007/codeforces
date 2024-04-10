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

struct poly {
  // a + bx + cxx
  mint a, b, c;

  poly operator+ (const poly& o) const {
    return {a+o.a, b+o.b, c+o.c};
  }

  poly operator* (const poly& o) const {
    return {a*o.a, a*o.b+b*o.a, a*o.c+b*o.b+c*o.a};
  }
};

struct rez {
  poly f, s, l;

  rez operator/ (const rez& b) const {
    return {f, s + b.s + l*b.f, b.l};
  }
};

poly addo(poly p, mint o) {
  return {p.a + p.b*o + p.c*o*o, p.b + p.c*2*o, p.c};
}

rez addo(rez a, mint o) {
  return {addo(a.f, o), addo(a.s, o), addo(a.l, o)};
}

mint p10[100005];
rez p[100005];

string a, b;
int n;

rez below(string& a, int i) {
  if (i == n-1) {
    if (a[i] == '4') {
      return {
        {4, 1, 0},
        {0, 0, 0},
        {4, 1, 0}
      };
    } else {
      return p[1];
    }
  }

  // duz. ostatka
  int l = n-i-1;

  if (a[i] == '4') {
    return addo(below(a, i+1), p10[l] * 4);
  } else {
    return addo(p[l], p10[l] * 4) / addo(below(a, i+1), p10[l] * 7);
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> a >> b;
  n = a.size();

  p[1] = {
    {4, 1, 0},
    {28, 11, 1},
    {7, 1, 0}
  };

  p10[0] = 1;
  for (int i=1; i<=n; i++) p10[i] = p10[i-1] * 10;

  for (int l=2; l<=n; l++) {

    rez a4 = addo(p[l-1], p10[l-1] * 4);
    rez a7 = addo(p[l-1], p10[l-1] * 7);

    p[l] = a4 / a7;

    // ok
    // auto r = p[l].s;
    // cerr << l << ' ' << r.a() << ' ' << r.b() << ' ' << r.c() << '\n';
  }

  auto r1 = below(a, 0);
  auto r2 = below(b, 0);

  cerr << r1.s.a() << '\n';
  cerr << r2.s.a() << '\n';

  cout << (r2.s.a - r1.s.a)() << '\n';
}