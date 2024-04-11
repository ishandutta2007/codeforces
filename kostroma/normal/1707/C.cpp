#pragma comment(linker, "/STACK:512000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <memory>
#include <chrono>
#include <cassert>
#include <random>
#include <queue>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <sstream>
#ifdef PINELY
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
#ifdef PINELY
    freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;

#ifdef PINELY
  const rlim_t kStackSize = 60 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif
#ifndef PINELY
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    cout.precision(20);
    cout << fixed;
    //cin >> t;
    precalc();
    int test_num = 1;
    while (t--) {
      //cout << "Case #" << test_num++ << ": ";
      solve(true);
    }
    cout.flush();

#ifdef PINELY1
    while (true) {
    solve(false);
  }
#endif

#ifdef PINELY
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

template<typename T>
void print_vec(const vector<T>& vals) {
  for (int x : vals) {
    cout << x << " ";
  }
  cout << endl;
}

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void precalc() {
}

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

vector<vector<int>> g;
vector<int> tin, tout;
vector<int> depth;
int TIMER = 0;

const int L = 17;
vector<vector<int>> parent;

void dfs(int v, int p, int d) {
  depth[v] = d;
  parent[0][v] = p;
  for (int i = 1; i < L; ++i) {
    parent[i][v] = parent[i - 1][parent[i - 1][v]];
  }
  tin[v] = TIMER++;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    dfs(to, v, d + 1);
  }
  tout[v] = TIMER++;
}

bool upper(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
  if (upper(a, b)) {
    return a;
  }
  for (int i = L - 1; i >= 0; --i) {
    if (!upper(parent[i][a], b)) {
      a = parent[i][a];
    }
  }
  return parent[0][a];
}

int jump(int v, int dist) {
  for (int i = 0; i < L; ++i) {
    if (dist & (1 << i)) {
      v = parent[i][v];
    }
  }
  return v;
}

vector<int> score_down;

void dfs2(int v, int p) {
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    score_down[to] += score_down[v];
    dfs2(to, v);
  }
}

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  Dsu dsu(n);
  vector<pair<int, int>> other_edges;
  for (int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    --from; --to;
    if (dsu.merge(from, to)) {
      g[from].push_back(to);
      g[to].push_back(from);
    } else {
      other_edges.emplace_back(from, to);
    }
  }
  parent.assign(L, vector<int>(n));
  depth.resize(n);
  tin.resize(n);
  tout.resize(n);
  dfs(0, 0, 0);
  score_down.assign(n, 0);
  int need_score = 0;
  for (auto& [a, b] : other_edges) {
    int c = lca(a, b);
    if (c == b) {
      swap(a, b);
    }
    ++score_down[b];
    if (c == a) {
      int nex = jump(b, depth[b] - depth[a] - 1);
      --score_down[nex];
    } else {
      ++score_down[a];
      ++need_score;
    }
  }
  dfs2(0, 0);
  string ans(n, '0');
  for (int v = 0; v < n; ++v) {
    assert(score_down[v] <= need_score);
    if (score_down[v] == need_score) {
      ans[v] = '1';
    }
  }
  cout << ans << "\n";
}