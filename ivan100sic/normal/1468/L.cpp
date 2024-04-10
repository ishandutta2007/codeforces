// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;
typedef unsigned __int128 ulll;

struct sieve {
	const int maxn;
	vector<int> f, primes;

	sieve(int maxn) : maxn(maxn), f(maxn) {
		for (int i=2; i<maxn; i++) {
			if (f[i] == 0) {
				f[i] = i;
				primes.push_back(i);
			}

			for (int p : primes) {
				if (p > f[i] || i * p >= maxn) {
					break;
				}

				f[i*p] = p;
			}
		}
	}

 	auto factor_small(int x) const {
		vector<pair<int, int>> v;
		while (x > 1) {
			int p = f[x], c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.emplace_back(p, c);
		}
		return v;
	}

	template<class T>
	auto factor(T x) const {
		vector<pair<T, int>> v;
		for (int p : primes) {
			if ((ll)p*p > x) {
				break;
			}

			if (x % p == 0) {
				int c = 0;
				while (x % p == 0) {
					x /= p;
					c++;
				}
				v.emplace_back(p, c);
			}
		}

		if (x > 1) {
			v.emplace_back(x, 1);
		}

		return v;
	}
} sv(1000005);

struct pollard_rho {
  map<ull, ull> c;
  mt19937 e{(unsigned)chrono::high_resolution_clock::now().time_since_epoch().count()};

  pollard_rho() : c({{2, 2}, {3, 3}, {4, 2}}) {}

  ull pw(ull x, ull y, ull m) {
    if (y == 0) return 1 % m;
    if (y == 1) return x % m;
    ll z = pw(x, y >> 1, m);
    z = (ulll)z * z % m;
    if (y & 1) {
      z = (ulll)z * x % m;
    }
    return z;
  }

  bool mr(ull n) {
    const int b[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

    ull r = 0, d = n-1;
    while (d % 2 == 0) {
      r++;
      d /= 2;
    }

    for (ull a : b) {
      ull x = pw(a, d, n);
      bool f = 0;
      if (x == 1 || x == n-1) continue;
      for (ull i=0; i<r-1; i++) {
        x = (ulll)x*x % n;
        if (x == n-1) {
          f = 1;
          break;
        }
      }

      if (f) {
        continue;
      }

      // cerr << "not prime, witness " << a << " value " << x << '\n';
      return false;
    }

    return true;
  }

  ull g(ull x, ull a, ull m) {
    return ((ulll)x*x + a) % m;
  }

  ull s(ull m) {
    // cerr << m << '\n';
    ull& y = c[m];
    if (y) return y;
    if (m % 2 == 0) return y = 2;
    if (m % 3 == 0) return y = 3;
    if (m < 1000005) return y = sv.f[m];
    if (mr(m)) return y = m;

    uniform_int_distribution<ull> u(1, m-1);
    while (1) {
      ull a = u(e), t = u(e), h = t;
      while (1) {
        t = g(t, a, m);
        h = g(g(h, a, m), a, m);
        ull d = gcd((ull)abs((ll)t-(ll)h), m);
        if (d == m) {
          break;
        } else if (d == 1) {
          continue;
        } else {
          return y = d;
        }
      }
    }
  }

  vector<ll> factor(ll m) {
    vector<ll> p, f = {m};
    while (f.size()) {
      ll x = f.back();
      f.pop_back();
      ll y = s(x);
      if (y == x) {
        p.push_back(y);
      } else {
        f.push_back(y);
        f.push_back(x / y);
      }
    }
    return p;
  }

};

ll orig[1005];

void no() {
  cout << "0\n";
  exit(0);
}

void ans(vector<int> a) {
  for (ll x : a) {
    cout << orig[x] << ' ';
  }
  cout << '\n';
  exit(0);
}

int d[1005][1005];

vector<int> dpss(vector<int> e, int k) {
  memset(d, 255, sizeof d);
  d[0][0] = 0;
  int n = e.size();
  for (int i=0; i<n; i++) {
    for (int j=0; j<=1000; j++) {
      if (d[i][j] == -1) continue;
      for (int x=0; x<=e[i]; x++) {
        if (x == 1) continue;
        d[i+1][j+x] = x;
      }
    }
  }

  if (d[n][k] == -1) return {};
  vector<int> z(n);

  while (n > 0) {
    int x = d[n][k];
    n--;
    z[n] = x;
    k -= x;
  }

  return z;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  pollard_rho rh;
  int n, k;
  cin >> n >> k;
  vector<pair<vector<ll>, int>> sl;
  map<ll, vector<int>> pr;
  for (int i=0; i<n; i++) {
    ll x;
    cin >> x;
    orig[i] = x;
    auto g = rh.factor(x);
    sort(begin(g), end(g));

    // for (ll y : g) cerr << y << ' ';
    // cerr << '\n';

    g.erase(unique(begin(g), end(g)), end(g));
    if (g.size() > 1) {
      sl.emplace_back(g, i);
    } else {
      pr[g[0]].emplace_back(i);
    }
  }

  {
    auto it = pr.begin();
    while (it != pr.end()) {
      if (it->second.size() == 1) {
        it = pr.erase(it);
      } else {
        it++;
      }
    }
  }

  sl.erase(partition(begin(sl), end(sl), [&](auto v) {
    for (ll p : v.first) {
      if (!pr.count(p)) {
        return false;
      }
    }
    return true;
  }), sl.end());

  int pt=0, st=sl.size();
  for (auto [x, y] : pr) {
    pt += y.size();
  }

  // cerr << "pt = " << pt << '\n';
  // cerr << "st = " << st << '\n';

  if (k == 1 || k > pt+st) no();
  if (k >= pt) {
    vector<int> a;
    for (auto [x, y] : pr) {
      a.insert(a.end(), y.begin(), y.end());
    }
    for (int i=0; i<k-pt; i++) {
      a.push_back(sl[i].second);
    }
    ans(a);
  }

  vector<pair<ll, vector<int>>> prv(begin(pr), end(pr));
  int y = prv.size();
  vector<int> z(y);
  for (int i=0; i<y; i++) {
    z[i] = prv[i].second.size();
  }
  auto e = dpss(z, k);

  // cerr << e.size() << '\n';
  // for (int x : e) cerr << x << ' ';
  // cerr << '\n';

  vector<int> a;
  if (e.size()) {
    for (int i=0; i<y; i++) {
      a.insert(a.end(), prv[i].second.begin(), prv[i].second.begin() + e[i]);
    }
    ans(a);
  } else {
    // cerr << "dpss failed\n";

    // k was odd, all were 2
    for (auto [pf, idx] : sl) {
      // count?
      if ((int)pf.size() <= k/2) {
        // ok
        vector<int> a;
        int resto = k;
        for (auto p : pf) {
          a.insert(a.end(), pr[p].begin(), pr[p].end()); // +2
          resto -= 2;
        }

        for (auto [p, v] : pr) {
          if (find(begin(pf), end(pf), p) == pf.end() && resto >= 3) {
            resto -= 2;
            a.insert(a.end(), pr[p].begin(), pr[p].end()); // +2
          }
        }

        a.push_back(idx);
        ans(a);
      }
    }
  }

  no();
}