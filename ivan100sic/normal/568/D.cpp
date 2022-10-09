// Retired?
#include <bits/stdc++.h>
using namespace std;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

typedef __int128 lll;

int n;

struct rac {
  ll p, q;

  rac(ll _p=0, ll _q=1) : p(_p), q(_q) {
    if (q < 0) {
      p = -p;
      q = -q;
    }
  }

  bool operator< (const rac& b) const {
    return (lll)p*b.q < (lll)q*b.p;
  }

  bool operator== (const rac& b) const {
    return (lll)p*b.q == (lll)q*b.p;
  }
};

struct line {
  int a, b, c, id;
};

// uvek isto q u razlomku
struct pt {
  rac x, y;

  bool operator< (const pt& b) const {
    return tie(x, y) < tie(b.x, b.y);
  }

  bool operator== (const pt& b) const {
    return tie(x, y) == tie(b.x, b.y);
  }
};

bool pli(pt p, line q) {
  return q.a * p.x.p + q.b * p.y.p + q.c * p.x.q == 0;
}

optional<pt> lli(line p, line q) {
  ll ox = 1ll*p.b*q.c - 1ll*p.c*q.b;
  ll oy = 1ll*p.c*q.a - 1ll*p.a*q.c;
  ll u = 1ll*p.b*q.a - 1ll*p.a*q.b;

  if (u != 0) {
    return pt{rac(ox, u), rac(oy, u)};
  } else {
    return nullopt;
  }
}

struct sol {
  bool ok;
  vector<pair<int, int>> pts;
};

sol resi(vector<line> a, int k) {
  if ((int)a.size() <= k) {
    sol s{1};
    for (auto l : a) {
      s.pts.emplace_back(l.id, -1);
    }
    return s;
  }

  for (int i=0; i<10*k; i++) {
    int idx = uniform_int_distribution<int>(0, (int)a.size()-1)(eng);

    vector<pair<pt, int>> xi;

    for (int j=0; j<(int)a.size(); j++) {
      if (j != idx) {
        auto xx = lli(a[idx], a[j]);
        if (xx) {
          xi.emplace_back(*xx, j);
        }
      }
    }

    sort(begin(xi), end(xi));

    for (int l=0; l<(int)xi.size();) {
      int r = l+1;
      while (r < (int)xi.size() && xi[r].first == xi[l].first) {
        r++;
      }

      string taken(n+1, 0);
      for (int i=l; i<r; i++) {
        taken[a[xi[i].second].id] = 1;
      }
      taken[a[idx].id] = 1;

      if (r-l >= k) {
        // moramo da uzmemo ovu tacku
        vector<line> a2;
        for (auto l : a) {
          if (!taken[l.id]) {
            a2.push_back(l);
          }
        }

        sol rek = resi(a2, k-1);
        if (!rek.ok) {
          return rek;
        }

        rek.pts.emplace_back(a[idx].id, a[xi[l].second].id);
        return rek;
      } else if ((r-l+1)*k >= (int)a.size()) {
        // uzecemo je, ali ako ne bude resenje probacemo ponovo
        vector<line> a2;
        for (auto l : a) {
          if (!taken[l.id]) {
            a2.push_back(l);
          }
        }

        sol rek = resi(a2, k-1);
        if (!rek.ok) {
          continue;
        }

        rek.pts.emplace_back(a[idx].id, a[xi[l].second].id);
        return rek;
      } else {
        l = r;
      }
    }
  }

  return {false};
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int k;
  cin >> n >> k;
  vector<line> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i].a >> a[i].b >> a[i].c;
    a[i].id = i+1;
  }

  auto s = resi(a, k);
  if (s.ok) {
    cout << "YES\n";
    cout << s.pts.size() << '\n';
    for (auto [x, y] : s.pts) {
      cout << x << ' ' << y << '\n';
    }
  } else {
    cout << "NO\n";
  }
}