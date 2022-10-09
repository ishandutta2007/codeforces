// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

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
		T v = e;
		for (; p; p -= p & -p)
			v = f(v, a[p-1]);
		return v;
	}
};

map<int, basic_string<int>> g;
basic_string<int> e[200005];
int n;
int l[200005], r[200005], dt, d[200005];

void dfs(int x) {
  l[x] = ++dt;
  for (int y : e[x]) {
    if (d[y] == -1) {
      d[y] = d[x] + 1;
      dfs(y);
    }
  }
  r[x] = ++dt;
}

int w[200005], w0[200005];

void markdown(int x) {
  w[x]++;
}

void markup(int x) {
  w[1]++;
  w[x]--;
  w0[x]++;
}

void dfs2(int x) {
  w0[x] += w[x];
  for (int y : e[x]) {
    if (d[y] == d[x] + 1) {
      w[y] += w[x];
      dfs2(y);
    }
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n;
  for (int i=1; i<=n; i++) {
    int x;
    cin >> x;
    g[x] += i;
    d[i] = -1;
  }

  fenwick f(2*n+5);

  for (int i=1; i<n; i++) {
    int x, y;
    cin >> x >> y;
    e[x] += y;
    e[y] += x;
  }

  d[1] = 0;
  dfs(1);

  // > 0?
  for (auto [k, v] : g) {
    if (v.size() >= 3) {
      for (int x : v) {
        f.add(l[x], 1);
      }

      vector<pair<int, int>> q;

      for (int x : v) {
        int dc = 0;
        for (int y : e[x]) {
          if (d[y] == d[x] + 1) {
            if (f(r[y]) > f(l[y])) {
              dc++;
            }
          }
        }

        bool oc = f(r[x]) - f(l[x]) != (int)v.size();

        if (dc >= 2) {
          cerr << "horizontal\n";
          cout << "0\n";
          return 0;
        }

        if (dc >= 1 && oc) {
          cerr << "weird\n";
          cout << "0\n";
          return 0;
        }

        q.emplace_back(l[x], 1);
        q.emplace_back(r[x], -1);
      }

      for (int x : v) {
        f.add(l[x], -1);
      }

      int z = 0;
      sort(begin(q), end(q));
      for (auto [x, y] : q) {
        z += y;
        if (z >= 3) {
          cerr << "vertical\n";
          cout << "0\n";
          return 0;
        }
      }
    }
  }

  for (auto [k, e] : g) {
    if (e.size() >= 2) {
      int y = *min_element(begin(e), end(e), [&](int x, int y) { return d[x] < d[y]; });

      for (int x : e) {
        f.add(l[x], 1);
      }

      // ok?
      int ci = 0;
      for (int x : e) {
        if (l[y] <= l[x] && r[x] <= r[y]) {
          ci++;
        }
      }

      if (ci == (int)e.size()) {
        // markiraj root, odmarkiraj nepraznu decu root-a
        w[1]++;
        for (int ch : ::e[y]) {
          if (d[ch] == d[y] + 1) {
            if (f(l[ch]) != f(r[ch])) {
              w[ch]--;
            }
          }
        }

        for (int z : e) {
          if (z != y) {
            w[z]++;
          }
        }
      } else {
        // sve na dole
        for (int z : e) {
          w[z]++;
        }
      }

      for (int x : e) {
        f.add(l[x], -1);
      }
    }
  }

  dfs2(1);
  cout << count(w0+1, w0+n+1, 0) << '\n';
}