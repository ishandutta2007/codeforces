#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
#ifdef AIM
#include <sys/resource.h>
#endif
using namespace std;

#define all(a) a.begin(), a.end()
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
//freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif

#ifdef AIM
  const rlim_t kStackSize = 256 * 1024 * 1024;
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0) {
    if (rl.rlim_cur < kStackSize) {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0) {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif

  start = clock();
  int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  precalc();
  while (t--) {
    solve(true);
  }
  cout.flush();

#ifdef AIM1
  while (true) {
    solve(false);
  }
#endif

#ifdef AIM
  cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif
  return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
  if (!w)
    return 1 % mod;
  if (w & 1)
    return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template<typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

void precalc() {

}

#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

struct Dsu {
  vector<int> dsu;
  Dsu(int n) {
    dsu.resize(n);
    iota(all(dsu), 0);
  }
  int find_set(int v) {
    if (dsu[v] == v) {
      return v;
    }
    return dsu[v] = find_set(dsu[v]);
  }
  bool merge(int q, int w) {
    q = find_set(q);
    w = find_set(w);
    if (q == w) {
      return false;
    }
    dsu[w] = q;
    return true;
  }
};

struct Edge {
  int from, to, cost;
  bool operator < (const Edge& ot) const {
    return cost > ot.cost;
  }
};

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> m >> n;
  vector<int> a(m);
  for (int& x : a) {
    cin >> x;
  }
  vector<int> b(n);
  for (int& x : b) {
    cin >> x;
  }
  vector<vector<int>> sets(m);
  int N = n + m;
  vector<Edge> edges;
  for (int i = 0; i < m; ++i) {
    int sz;
    cin >> sz;
    sets[i].resize(sz);
    for (int& x : sets[i]) {
      cin >> x;
      --x;
      edges.push_back({i, x + m, b[x] + a[i]});
    }
  }
  Dsu dsu(N);
  sort(all(edges));
  int ans = 0;
  for (auto& e : edges) {
    if (!dsu.merge(e.from, e.to)) {
      ans += e.cost;
    }
  }
  cout << ans << "\n";

}