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

template<class T = int, class F = plus<T>>
struct fenwick {
	vector<T> a;
	T e;
	F f;

	fenwick(int n, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

	void add(int p, const T& v) {
		for (p++; p <= (int)a.size(); p += p & -p)
			a[p-1] = f(a[p-1], v);
	}

	T operator() (int p) const {
    // dodato
    if (p <= 0) return e;
    if (p > (int)a.size()) p = a.size();
    // templ
    T v = e;
		for (; p; p -= p & -p)
			v = f(v, a[p-1]);
		return v;
	}
};

template<class T>
struct niz {
  vector<T> p, g;
  int l = 0, r = 0;

  T& operator[] (int i) {
    l = min(l, i);
    r = max(r, i);
    if (i >= 0) {
      while (i >= (int)p.size()) p.emplace_back();
      return p[i];
    } else {
      while (-i >= (int)g.size()) g.emplace_back();
      return g[-i];
    }
  }

  pair<int, int> opseg() {
    return {l, r};
  }
};

struct gr {
  int v, c;
  mint w;
};

int n;
vector<gr> e[100005];

bool bl[100005];
int sz[100005];

// velicine podstabala
void dfs1(int x, int p) {
  sz[x] = 1;
  for (auto [y, _, __] : e[x]) {
    if (y == p || bl[y]) continue;
    dfs1(y, x);
    sz[x] += sz[y];
  }
}

// odredi centroid
void dfs2(int x, int p, int komp, int& cent) {
  bool ok = 2*sz[x] >= komp;
  for (auto [y, _, __] : e[x]) {
    if (y == p || bl[y]) continue;
    dfs2(y, x, komp, cent);
    if (2*sz[y] >= komp) {
      ok = 0;
    }
  }

  if (ok) cent = x;
}

struct stvar {
  mint first = 1;
  int second = 0;

  stvar operator+ (const stvar& b) const {
    return {first * b.first, second + b.second};
  }
};

// iz centroida trazi putanje
void dfs3(int x, int p, mint prod, int d, niz<stvar>& a) {
  a[d].first *= prod;
  a[d].second++;

  for (auto [y, c, w] : e[x]) {
    if (y == p || bl[y]) continue;
    dfs3(y, x, prod * w, d + c, a);
  }
}

mint sol = 1;

void dfs4(int x) {
  // given cvor, resi stablo
  dfs1(x, x);
  int ce = -1;
  dfs2(x, x, sz[x], ce);
  x = ce;

  fenwick<stvar> f(3*sz[x] + 9);
  int offs = sz[x] + 3;

  for (auto [y, c, w] : e[x]) {
    if (bl[y]) continue;
    niz<stvar> t;
    dfs3(y, x, w, c, t);

    auto [l, r] = t.opseg();
    for (int i=l; i<=r; i++) {
      // sam
      if (i < 0) {
        sol *= t[i].first;
      }

      // i+x < 0
      // x < -i

      // sa drugim
      auto q = f(offs - i);
      sol *= (q.first ^ t[i].second) * (t[i].first ^ q.second);
    }

    for (int i=l; i<=r; i++) {
      f.add(i+offs, t[i]);
    }
  }

  bl[x] = 1;
  for (auto [y, c, w] : e[x]) {
    if (!bl[y]) {
      dfs4(y);
    }
  }
}

void dfs5(int x, int p) {
  sz[x] = 1;
  for (auto [y, c, w] : e[x]) {
    if (y == p) continue;
    dfs5(y, x);
    sol *= w ^ (sz[y] * 1ll * (n - sz[y]));
    sz[x] += sz[y];
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n;
  for (int i=1; i<n; i++) {
    int u, v, x, c;
    cin >> u >> v >> x >> c;
    if (c == 0) {
      c = -1;
    } else {
      c = 2;
    }
    e[u].push_back({v, c, x});
    e[v].push_back({u, c, x});
  }

  dfs4(1);
  // cerr << "tmp sol = " << sol() << '\n';

  for (int i=1; i<=n; i++) {
    bl[i] = 0;
    for (auto& [y, c, w] : e[i]) {
      if (c == -1) {
        c = 2;
      } else {
        c = -1;
      }
    }
  }
  dfs4(1);

  // cerr << "tmp sol = " << sol() << '\n';

  mint ans = sol.inv();
  sol = 1;

  dfs5(1, 1);
  ans *= sol;

  cout << ans() << '\n';
}