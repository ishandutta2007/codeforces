// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

basic_string<int> e[100005], f[100005];
int n, m;
int sol[100005];

int l[100005], r[100005], dt;

void dfs1(int x, int p) {
  l[x] = dt++;
  for (int y : e[x]) {
    if (y != p) {
      dfs1(y, x);
    }
  }
  r[x] = dt;
}

template<class T, class U, class F, class G, class H>
struct segtreelazy {
	struct node { T v; U u; };
	int maxn;
	vector<node> a;
	T e; U eu;
	F f; G g; H h;
	// Add two elements
	// Add two updaters
	// Add an element and an update
	// Neutral element
	// Neutral update
	// Bottom level element
	segtreelazy(int n, F f, G g, H h, T e = T(), U eu = U(), T v = T()) :
		e(e), eu(eu), f(f), g(g), h(h)
	{
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.assign(2*maxn, node{v, eu});
		for (int i=maxn-1; i; i--)
			a[i].v = f(a[2*i].v, a[2*i+1].v);
	}

	void push(int x) {
		a[x].v = h(a[x].v, a[x].u);
		if (x < maxn) {
			a[2*x  ].u = g(a[2*x  ].u, a[x].u);
			a[2*x+1].u = g(a[2*x+1].u, a[x].u);
		}
		a[x].u = eu;
	}

	void set(int p, const T& v) {
		int x = 1, xl = 0, xr = maxn;
		while (xr-xl > 1) {
			push(x);
			int xm = (xl+xr) >> 1;
			(p < xm ? xr : xl) = xm;
			x = 2*x + (p >= xm);
		}
		a[x] = {v, eu};
		do {
			push(x^1);
			x >>= 1;
			a[x].v = f(a[2*x].v, a[2*x+1].v);
		} while (x > 1);
	}

	void update(int l, int r, const U& u, int x, int xl, int xr) {
		if (r <= xl || xr <= l)
			return push(x);
		if (l <= xl && xr <= r)
			return a[x].u = g(a[x].u, u), push(x);
		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, u, 2*x  , xl, xm);
		update(l, r, u, 2*x+1, xm, xr);
		a[x].v = f(a[2*x].v, a[2*x+1].v);
	}

	T get(int l, int r, int x, int xl, int xr) {
		push(x);
		if (r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x].v;
		int xm = (xl+xr) >> 1;
		return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
	}

	void update(int l, int r, const U& u) { update(l, r, u, 1, 0, maxn); }
	T operator() (int l, int r) { return get(l, r, 1, 0, maxn); }
};

struct elem {
	int mn = 123123123, cnt = 0;

	elem operator+ (const elem& b) const {
		if (mn < b.mn) return *this;
		else if (mn > b.mn) return b;
		return {mn, cnt + b.cnt};
	}

	elem operator+ (int b) const {
		return {mn+b, cnt};
	}
};

segtreelazy st(100005, plus<elem>(), plus<int>(), [](elem b, int y) { return elem{b.mn+y, b.cnt}; }, elem{}, 0, elem{0, 1});

void ads(int l, int r, int v) {
	st.update(l, r, v);
}

int cn1() {
	auto x = st(0, n);
	if (x.mn == 0) return n - x.cnt;
	else return n;
}

void dfs2(int x) {
  // dodaj
  if (f[x].size()) {
    ads(l[x], r[x], 1);
    for (int y : f[x]) {
      ads(l[y], r[y], 1);
    }
  }

  sol[x] = cn1();

  for (int y : e[x]) {
    if (l[y] > l[x]) {
      dfs2(y);
    }
  }

  // skini
  if (f[x].size()) {
    ads(l[x], r[x], -1);
    for (int y : f[x]) {
      ads(l[y], r[y], -1);
    }
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m;
  for (int i=1; i<n; i++) {
    int x, y;
    cin >> x >> y;
    e[x] += y;
    e[y] += x;
  }

  dfs1(1, 0);

  while (m--) {
    int x, y;
    cin >> x >> y;
    f[x] += y;
    f[y] += x;
  }

  dfs2(1);

  for (int i=1; i<=n; i++) {
    cout << (sol[i] ? sol[i]-1 : 0) << " \n"[i == n];
  }

}