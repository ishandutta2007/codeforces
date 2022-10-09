// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int, class F = plus<T>>
struct segtree {
	int maxn;
	vector<T> a;
	T e;
	F f;

	segtree(int n, T e = T(), F f = F(), T v = T()) : e(e), f(f) {
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.assign(2*maxn, v);
		for (int i=maxn-1; i; i--)
			a[i] = f(a[2*i], a[2*i+1]);
	}

	void add(int p, const T& v) {
		p += maxn;
		a[p] = f(a[p], v);
		for (p >>= 1; p; p >>= 1)
			a[p] = f(a[2*p], a[2*p+1]);
	}

	void update(int p, const T& v) {
		p += maxn;
		a[p] = v;
		for (p >>= 1; p; p >>= 1)
			a[p] = f(a[2*p], a[2*p+1]);
	}

	T get(int l, int r, int x, int xl, int xr) const {
		if (r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
	}

	T operator() (int l, int r) const {
		return get(l, r, 1, 0, maxn);
	}
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, sol = 0;
    cin >> n;
    vector<int> a(n), d(n);

    segtree st(n, pair(-1, 0), [](auto u, auto v) {
      return pair(u.first, -u.second) > pair(v.first, -v.second)
        ? u : v;
    }, pair(-1, 0));

    segtree mx(n, -1, [](int x, int y) { return max(x, y); }, -1);

    for (int i=0; i<n; i++) {
      cin >> a[i];
      a[i]--;
      mx.update(i, a[i]);
    }

    d[0] = 1;
    st.add(a[0], pair(1, 0));
    for (int i=1; i<n; i++) {
      // prvo obradi i
      // na nesto staro - st
      auto q = st(0, a[i]+1);
      // cerr << "get " << i << ' ' << q.first << ' ' << q.second << '\n';
      d[i] = max(d[i], q.first + 1 + (mx(q.second+1, i) >= a[i]));
      // kao prvi broj
      d[i] = max(d[i], 2);
      // sad update seg
      st.add(a[i], pair(d[i], i));
      // global sol upd
      sol = max(sol, d[i] + (mx(i+1, n) >= a[i]));
    }

    // for (int i=0; i<n; i++) {
    //   cerr << d[i] << " \n"[i == n-1];
    // }

    cout << sol << '\n';
  }
}