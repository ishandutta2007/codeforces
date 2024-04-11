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

void precalc() {

}

#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

vector<int> h, max_in_subtree, mx_subtree, mx2_subtree;
vector<vector<int>> g;

const int INF = (int)1e18;

void dfs1(int v, int p) {
  max_in_subtree[v] = h[v];
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    dfs1(to, v);
    relax_max(max_in_subtree[v], max_in_subtree[to]);
  }
  vector<int> children_maxes;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    children_maxes.push_back(max_in_subtree[to]);
  }
  mx2_subtree[v] = mx_subtree[v] = 0;
  if (children_maxes.empty()) {
    return;
  }
  sort(children_maxes.rbegin(), children_maxes.rend());
  mx_subtree[v] = children_maxes[0];
  mx2_subtree[v] = children_maxes.size() >= 2 ? children_maxes[1] : 0;
}

int dfs2(int v, int p) {
  int mx2 = mx2_subtree[v];
  int children = 0;
  int res = 0;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    ++children;
    res += dfs2(to, v);
  }
  if (children == 0) {
    return h[v];
  }
  if (h[v] > mx_subtree[v]) {
    res += h[v] - mx_subtree[v];
  }
  if (v == p && h[v] > mx2) {
    res += h[v] - mx2;
  }
  return res;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 4;
  }
  g.clear();
  g.resize(n);
  h.resize(n);
  max_in_subtree.assign(n, 0);
  for (int& x : h) {
    if (read) {
      cin >> x;
    } else {
      x = rand() % 1000;
    }
  }
  for (int i = 1; i < n; ++i) {
    int a, b;
    if (read) {
      cin >> a >> b;
      --a;
      --b;
    } else {
      a = i;
      b = rand() % i;
    }
    g[a].push_back(b);
    g[b].push_back(a);
  }
  if (n == 2) {
    cout << 2 * (*max_element(all(h))) << "\n";
    return;
  }
  int root = max_element(all(h)) - h.begin();
  mx2_subtree.resize(n);
  mx_subtree.resize(n);
  dfs1(root, root);

  int ans = dfs2(root, root);
  cout << ans << "\n";

}