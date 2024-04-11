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

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> initial_left(n, 0), initial_right(n, 0);
  vector<vector<int>> edges_to_right(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    if (a > b) {
      swap(a, b);
    }
    g[a].push_back(b);
    g[b].push_back(a);
    ++initial_left[b];
    ++initial_right[a];
    edges_to_right[a].push_back(b);
  }
  int Q;
  cin >> Q;

  li res = 0;

  auto make_inc = [&] (bool add, int pos) {
    auto val = initial_left[pos] * 1LL * initial_right[pos];
    if (add) {
      res += val;
    } else {
      res -= val;
    }
  };

  for (int i = 0; i < n; ++i) {
    make_inc(true, i);
  }

  vector<int> current_pos(n);
  iota(all(current_pos), 0);
  cout << res << "\n";
  for (int w = 0; w < Q; ++w) {
    int v;
    cin >> v;
    --v;
    int pos = current_pos[v];

    for (int to : edges_to_right[v]) {
      make_inc(false, current_pos[to]);
      --initial_left[current_pos[to]];
      ++initial_right[current_pos[to]];
      make_inc(true, current_pos[to]);

      edges_to_right[to].push_back(v);
    }
    edges_to_right[v].clear();

    make_inc(false, pos);
    initial_left[pos] = initial_right[pos] = 0;

    int n_edges = g[v].size();
    initial_left.push_back(n_edges);

    int new_pos = n + w;
    current_pos[v] = new_pos;
    initial_right.push_back(0);

    cout << res << "\n";
  }

}