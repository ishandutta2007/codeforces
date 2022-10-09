// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct karta {
  int p, q;
};

int brut_rek(vector<vector<karta>> a, int p, int s) {
  if (s == 2) {
    return 0;
  }

  if (p == 0) {
    int h = brut_rek(a, 1, s+1);
    for (int i=0; i<(int)a.size(); i++) {
      if (a[i].size()) {
        auto b = a;
        int v = b[i][0].p;
        b[i].erase(b[i].begin());
        h = max(h, v + brut_rek(b, 1, 0));
      }
    }
    return h;
  } else {
    int h = brut_rek(a, 0, s+1);
    for (int i=0; i<(int)a.size(); i++) {
      if (a[i].size()) {
        auto b = a;
        int v = -b[i][0].q;
        b[i].erase(b[i].begin());
        h = min(h, v + brut_rek(b, 0, 0));
      }
    }
    return h;
  }
}

int brut(vector<vector<karta>> a) {
  return brut_rek(a, 0, 0);
}

vector<vector<karta>> rd() {
  int n;
  cin >> n;
  vector<vector<karta>> a(n);
  for (int i=0; i<n; i++) {
    int p, q, r, s;
    cin >> p >> q >> r >> s;
    a[i].push_back({p, q});
    a[i].push_back({r, s});
  }

  return a;
}

vector<vector<karta>> gen(int n, int d) {
  uniform_int_distribution uid(0, 100);
  vector<vector<karta>> a(n);
  for (int i=0; i<n; i++) {
    a[i].push_back({uid(eng), uid(eng)});
    if (i < d) {
      a[i].push_back({uid(eng), uid(eng)});
    }
  }
  return a;
}

struct kutija_handle {
  vector<vector<karta>>* a;
  int id;

  bool operator< (const kutija_handle& b) const {
    if (a->at(id).empty() || b.a->at(b.id).empty()) {
      return id < b.id;
    }

    auto x = a->at(id)[0];
    auto y = b.a->at(b.id)[0];

    int u = x.p + x.q;
    int v = y.p + y.q;
    if (u != v) {
      return u > v;
    }

    return id < b.id;
  }
};

ll solve2(vector<vector<karta>> a) {
  set<kutija_handle> v0, v1;
  int n = a.size();

  for (int i=0; i<n; i++) {
    auto d = a[i];
    if (d[0].p - d[1].q > min(0, d[1].p - d[0].q)) v0.insert({&a, i});
    if (d[0].q - d[1].p > min(0, d[1].q - d[0].p)) v1.insert({&a, i});
  }

  int p = 0, sk=0;
  ll z = 0;
  while (sk < 2) {
    if (p == 0) {
      if (v0.size()) {
        int i = v0.begin()->id;
        v0.erase({&a, i});
        v1.erase({&a, i});

        auto& w = a[i];
        z += w[0].p;
        w.erase(w.begin());
        if (w.size()) {
          v0.insert({&a, i});
          v1.insert({&a, i});
        }
        sk = 0;
      } else {
        sk++;
      }
    } else {
      if (v1.size()) {
        int i = v1.begin()->id;
        v0.erase({&a, i});
        v1.erase({&a, i});

        auto& w = a[i];
        z -= w[0].q;
        w.erase(w.begin());
        if (w.size()) {
          v0.insert({&a, i});
          v1.insert({&a, i});
        }
        sk = 0;
      } else {
        sk++;
      }
    }

    p ^= 1;
  }

  return z;
}

void pr(vector<vector<karta>> a) {
  cerr << a.size() << '\n';
  for (auto b : a) {
    for (auto c : b) {
      cerr << c.p << ' ' << c.q << ' ';
    }
    cerr << '\n';
  }
  cerr << '\n';
}

void check() {
  int runs = 10000;
  for (int i=0; i<runs; i++) {
    cerr << i << '\n';
    auto a = gen(2, 2);
    int e = brut(a);
    int f = solve2(a);
    if (e != f) {
      cerr << "error\n";
      cerr << e << ' ' << f << '\n';
      pr(a);
      return;
    }
  }
  cerr << "ok\n";
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cout << solve2(rd()) << '\n';
  // check();
}