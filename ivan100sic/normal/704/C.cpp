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

int n, tgt = 1;
int sgl[100005];
vector<pair<int, int>> dbl;
basic_string<int> e[100005];
mint ans[2];

void rd() {
  int m;
  cin >> n >> m;
  while (n--) {
    int k;
    cin >> k;
    if (k == 1) {
      int x;
      cin >> x;
      if (x < 0) {
        tgt ^= 1;
        x = -x;
      }

      sgl[x] ^= 1;
    } else {
      int x, y;
      cin >> x >> y;

      if (x == y) {
        if (x < 0) {
          tgt ^= 1;
          x = -x;
        }
        sgl[x] ^= 1;
      } else if (x == -y) {
        tgt ^= 1;
      } else {
        int c = 1, d = 1;
        if (x < 0) {
          c ^= 1;
          x = -x;
        }

        if (y < 0) {
          d ^= 1;
          y = -y;
        }

        tgt ^= 1;
        dbl.emplace_back(x, y);
        sgl[x] ^= d;
        sgl[y] ^= c;
        tgt ^= c*d;
      }
    }
  }

  n = m;
}

void info() {
  cerr << "tgt: " << tgt << '\n';

  cerr << "sgl:\n";
  for (int i=1; i<=n; i++) {
    cerr << sgl[i] << " \n"[i == n];
  }

  cerr << "dbl:\n";
  for (auto [x, y] : dbl) {
    cerr << x << ' ' << y << '\n';
  }
}

void rmd() {
  vector<pair<int, int>> tmp;
  sort(begin(dbl), end(dbl));
  for (int i=0; i<(int)dbl.size();) {
    if (i+1 < (int)dbl.size() && dbl[i] == dbl[i+1]) {
      i += 2;
    } else {
      tmp.emplace_back(dbl[i]);
      i++;
    }
  }

  swap(tmp, dbl);
}

int status[100005];
int deg1;

void dfs1(int x) {
  status[x] = 1;
  if (e[x].size() == 1)  deg1 = x;
  for (int y : e[x]) {
    if (status[y] == 0) {
      dfs1(y);
    }
  }
}

void dfs2(int x, vector<int>& v) {
  status[x] = 2;
  v.emplace_back(x);
  for (int y : e[x]) {
    if (status[y] < 2) {
      dfs2(y, v);
    }
  }
}

void mix(mint w0, mint w1) {
  mint t0 = w0 * ans[0] + w1 * ans[1];
  mint t1 = w1 * ans[0] + w0 * ans[1];
  ans[0] = t0;
  ans[1] = t1;
}

void solve1(vector<int> v) {
  int m = v.size();
  //     S  X
  mint w[2][2];

  {
    int x0 = v[0];
    w[0][0] = 1;
    w[1][sgl[x0]] = 1;
  }

  for (int i=1; i<m; i++) {
    int nd = v[i];
    mint ww[2][2];
    for (int u=0; u<2; u++) {
      for (int s=0; s<2; s++) {
        for (int x=0; x<2; x++) {
          int ss = u;
          int xx = x ^ (s & u) ^ (u & sgl[nd]);
          ww[ss][xx] += w[s][x];
        }
      }
    }

    for (int u : {0, 1}) {
      for (int v : {0, 1}) {
        w[u][v] = ww[u][v];
      }
    }
  }

  mix(w[0][0] + w[1][0], w[0][1] + w[1][1]);
}

void solve2(vector<int> v) {
  int m = v.size();
  mint w[2][2][2];

  {
    int x0 = v[0];
    w[0][0][0] = 1;
    w[1][1][sgl[x0]] = 1;
  }

  for (int i=1; i<m; i++) {
    int nd = v[i];
    mint ww[2][2][2];
    for (int p=0; p<2; p++) {
      for (int u=0; u<2; u++) {
        for (int s=0; s<2; s++) {
          for (int x=0; x<2; x++) {
            int ss = u;
            int xx = x ^ (s & u) ^ (u & sgl[nd]);
            ww[p][ss][xx] += w[p][s][x];
          }
        }
      }
    }

    for (int u : {0, 1}) {
      for (int v : {0, 1}) {
        for (int q : {0, 1}) {
          w[u][v][q] = ww[u][v][q];
        }
      }
    }
  }

  mint mx[2];

  for (int p=0; p<2; p++) {
    for (int s=0; s<2; s++) {
      for (int x=0; x<2; x++) {
        int xx = x ^ (s & p);
        mx[xx] += w[p][s][x];
      }
    }
  }

  mix(mx[0], mx[1]);
}

void solveall() {
  ans[0] = 1;

  for (auto [x, y] : dbl) {
    e[x] += y;
    e[y] += x;
  }

  for (int i=1; i<=n; i++) {
    if (status[i] == 0) {
      if (e[i].size() == 0) {
        if (sgl[i]) {
          mix(1, 1);
        } else {
          mix(2, 0);
        }

        continue;
      }


      deg1 = -1;
      dfs1(i);

      if (deg1 != -1) {
        vector<int> v;
        dfs2(deg1, v);
        solve1(v);
      } else {
        vector<int> v;
        dfs2(i, v);
        solve2(v);
      }
    }
  }

  cout << ans[tgt]() << '\n';
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  rd();
  rmd();
  // info();
  solveall();

}