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
const int mod = 998244353;
//using ull = unsigned long long;


struct Dsu {
  vector<int> dsu;
  vector<int> edge_count;
  vector<int> sizes;
  Dsu(int n) {
    dsu.resize(n);
    iota(all(dsu), 0);
    edge_count.assign(n, 0);
    sizes.assign(n, 1);
  }
  int find_set(int v) {
    if (dsu[v] == v) {
      return v;
    }
    return dsu[v] = find_set(dsu[v]);
  }
  void merge(int q, int w) {
    q = find_set(q);
    w = find_set(w);
    if (q != w) {
      dsu[w] = q;
      edge_count[q] += edge_count[w];
      edge_count[w] = 0;
      sizes[q] += sizes[w];
      sizes[w] = 0;
    }
    ++edge_count[q];
  }
};

struct Edge {
  int from, to, cost;
  bool operator < (const Edge& ot) const {
    return cost < ot.cost;
  }
};

vector<vector<int>> g;

void add(int& cur, int val) {
  cur += val;
  cur %= mod;
}

vector<int> dfs(int v) {
  if (g[v].empty()) {
    return {0, 1};
  }
  vector<int> res(1, 1);
  for (int to : g[v]) {
    auto cur_res = dfs(to);
    vector<int> new_res(res.size() + cur_res.size() - 1, 0);
    for (int was = 0; was < res.size(); ++was) {
      for (int take = 0; take < cur_res.size(); ++take) {
        add(new_res[was + take], res[was] * cur_res[take]);
      }
    }
    res.swap(new_res);
  }
  if (res.size() == 1) {
    res.resize(2, 0);
  }
  res[1] = (res[1] + 1) % mod;
  /*cout << "v: " << v << " dp: ";
  for (int x : res) {
    cout << x << " ";
  }
  cout << endl;*/
  return res;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 1500;
  }
  vector<Edge> edges;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int cur;
      if (read) {
        cin >> cur;
      } else {
        cur = i + j * n;
      }
      if (i < j) {
        edges.push_back({i, j, cur});
      }
    }
  }
  sort(all(edges));
  g.resize(n);
  vector<int> largest_clique(n);
  for (int i = 0; i < n; ++i) {
    largest_clique[i] = i;
  }
  Dsu dsu(n);
  vector<int> children;
  for (auto e : edges) {
    dsu.merge(e.from, e.to);
    int root = dsu.find_set(e.from);
    if (dsu.edge_count[root] == dsu.sizes[root] * (dsu.sizes[root] - 1) / 2) {
      int clique_id = g.size();
      children.clear();
      for (int i = 0; i < n; ++i) {
        if (dsu.find_set(i) == root) {
          children.push_back(largest_clique[i]);
          largest_clique[i] = clique_id;
        }
      }
      make_unique(children);
      g.push_back(children);
    }
  }
  auto res = dfs((int)g.size() - 1);
  assert(res.size() == n + 1);
  for (int i = 1; i <= n; ++i) {
    cout << res[i] << " ";
  }
  cout << "\n";

}