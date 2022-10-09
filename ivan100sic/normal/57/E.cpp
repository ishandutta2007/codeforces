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

int d[1005][1005];

const int LIM = 233;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  memset(d, 255, sizeof d);

  int n;
  ll ki;
  cin >> ki >> n;

  while (n--) {
    int x, y;
    cin >> x >> y;
    x += 500;
    y += 500;
    d[x][y] = -2;
  }

  d[500][500] = 0;
  queue<pair<int, int>> q;
  q.push({500, 500});

  while (q.size()) {
    auto [x, y] = q.front();
    q.pop();
    if (d[x][y] >= LIM-1) break;

    for (int dx=-2; dx<=2; dx++) {
      for (int dy=-2; dy<=2; dy++) {
        if (abs(dx) + abs(dy) == 3 && dx && dy) {

          int xx = x + dx, yy = y + dy;
          if (d[xx][yy] == -1) {
            d[xx][yy] = d[x][y] + 1;
            q.push({xx, yy});
          }
        }
      }
    }
  }

  vector<int> f(LIM);
  for (int i=0; i<1005; i++) {
    for (int j=0; j<1005; j++) {
      if (d[i][j] >= 0) {
        f[d[i][j]]++;
      }
    }
  }

  if (ki < LIM) {
    cout << accumulate(begin(f), begin(f) + ki + 1, 0) << '\n';
  } else {
    mint q = f[LIM-2];
    mint r = f[LIM-1];
    mint lim = LIM;
    mint k = ki;

    mint beyond = (k-lim+1)*((k-lim+2)*q+(lim-k-4)*r) * mint(-2).inv();

    cout << accumulate(begin(f), end(f), beyond)() << '\n';
  }
}