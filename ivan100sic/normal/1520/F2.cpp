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

int ask_io(int r) {
  int x;
  cout << "? 1 " << r << '\n' << flush;
  cin >> x;
  if (x == -1) {
    // :(
    exit(0);
  }
  return x;
}

fenwick d(200005);
map<int, int> cache;

int ask(int r) {
  if (cache.count(r)) {
    return cache[r] + d(r+1);
  }

  int a = ask_io(r);
  cache[r] = a - d(r+1);
  return a;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, t;
  cin >> n >> t;
  while (t--) {
    int k;
    cin >> k;
    int l = 1, r = n - 1, o = n;
    while (l <= r) {
      int m = (l + r) / 2;
      int x = ask(m);
      if (m-x >= k) {
        o = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    cout << "! " << o << '\n' << flush;
    d.add(o, 1);
  }
}