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
    freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;

#ifdef AIM
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
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    cout.precision(20);
    cout << fixed;
    cin >> t;
    precalc();
    int test_num = 1;
    while (t--) {
      //cout << "Case #" << test_num++ << ": ";
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

struct Dp {
  int leaves = 0;
  int buds = 0;
  bool is_leaf = false;
};

vector<vector<int>> g;

Dp dfs(int v, int p) {
  int cnt = 0;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    ++cnt;
  }
  if (cnt == 0) {
    return {1, 0, true};
  }
  Dp res = {0, 0, false};
  int child_buds = 0;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    auto cur_dp = dfs(to, v);
    if (!cur_dp.is_leaf) {
      ++child_buds;
    }
    res.leaves += cur_dp.leaves;
    res.buds += cur_dp.buds;
  }
  res.buds += child_buds;
  if (child_buds == cnt) {
    //--res.buds;
    res.is_leaf = true;
    ++res.leaves;
  }
  assert(res.buds < res.leaves);
  return res;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = rand() % 10 + 2;
  }
  g.clear();
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    if (read) {
      cin >> a >> b;
      --a;
      --b;
    } else {
      a = rand() % i;
      b = i;
    }
    g[a].push_back(b);
    g[b].push_back(a);
  }
  if (n == 1) {
    cout << "0\n";
    return;
  }
  auto res = dfs(0, 0);
  cout << res.leaves - res.buds << "\n";
}