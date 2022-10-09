// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int credits_1;

int cache[105][105];

int ask(int a, int b) {
  if (cache[a][b] != -1) return cache[a][b];
  credits_1--;
  cout << "1 " << a << ' ' << b << '\n' << flush;
  int x;
  cin >> x;
  cache[a][b] = x;
  cache[b][a] = 1-x;
  return x;
}

int ask(int x, vector<int> a) {
  if (a.empty()) {
    return 0;
  }

  if (credits_1 > 0 && a.size() == 1) {
    return ask(x, a[0]);
  }

  cout << "2 " << x << ' ' << a.size();
  for (int y : a) {
    cout << ' ' << y;
  }
  cout << '\n' << flush;
  int z;
  cin >> z;
  return z;
}

struct union_find {
	vector<int> p;
	union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
	bool operator() (int x, int y) { return e(x) == e(y); }
	int e(int x) {
		if (p[x] == x) return x;
		return p[x] = e(p[x]);
	}
	bool join(int x, int y) {
		x = e(x), y = e(y);
		if (x == y) return false;
		p[x] = y;
		return true;
	}
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    credits_1 = 9*n;
    memset(cache, 255, sizeof cache);

    vector<int> a = {0};
    for (int i=1; i<n; i++) {
      if (ask(i, a[0])) {
        a.insert(a.begin(), i);
      } else if (ask(a.back(), i)) {
        a.push_back(i);
      } else {
        int l = 0, r = a.size() - 1;
        while (r - l > 1) {
          int m = (l+r) / 2;
          if (ask(i, a[m])) {
            r = m;
          } else {
            l = m;
          }
        }

        a.insert(a.begin() + r, i);
      }
    }

    // cerr << "linear order:";
    // for (int x : a) cerr << ' ' << x;
    // cerr << '\n';

    vector<int> ai(n);
    for (int i=0; i<n; i++) {
      ai[a[i]] = i;
    }

    union_find uf(n);

    for (int i=n-1, q=n; i>=1; i--) {
      q = min(i, q);
      while (ask(a[i], vector<int>(a.begin(), a.begin() + q))) {
        int j = q-1;
        while (!ask(a[i], vector<int>{ a[j] })) {
          j--;
        }
        q = j;
      }
      for (int j=q; j<=i; j++) {
        uf.join(a[i], a[j]);
      }
    }

    cout << "3\n";
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        cout << (uf(i, j) || (ai[i] < ai[j]));
      }
      cout << '\n';
    }
    cout << flush;

    int ok;
    cin >> ok;
  }
}