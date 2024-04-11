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
    //cin >> t;
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

const int L = 18;
vector<vector<int>> g;
vector<int> parent;
vector<int> tin, tout;
int TIMER = 0;

void dfs(int v, int p) {
  tin[v] = TIMER++;
  parent[v] = p;
  for (int to : g[v]) {
    if (parent[to] != -1) {
      continue;
    }
    dfs(to, v);
  }
  tout[v] = TIMER++;
}

bool upper(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

vector<int> score;

int res = 0;

int dfs_ans(int v) {
  int to_pair = 0;
  for (int to : g[v]) {
    int cur_res = dfs_ans(to);
    if (score[to]) {
      ++to_pair;
    } else {
      res += cur_res;
    }
  }
  res += to_pair / 2;
  return to_pair % 2;
}

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  tin.resize(n);
  tout.resize(n);
  parent.assign(n, -1);
  dfs(0, 0);
  int Q;
  cin >> Q;
  score.assign(n, 0);
  vector<vector<int>> paths;
  vector<int> up_path, down_path;
  while (Q--) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    up_path.clear();
    down_path.clear();
    while (!upper(parent[a], b)) {
      up_path.push_back(a);
      score[a] ^= 1;
      a = parent[a];
    }
    if (!upper(a, b)) {
      up_path.push_back(a);
      score[a] ^= 1;
      a = parent[a];
    }
    while (b != a) {
      down_path.push_back(b);
      score[b] ^= 1;
      b = parent[b];
    }
    paths.push_back(up_path);
    reverse(all(down_path));
    paths.back().push_back(a);
    for (int x : down_path) {
      paths.back().push_back(x);
    }
  }
  if (*max_element(all(score)) == 0) {
    cout << "YES\n";
    for (auto& path : paths) {
      cout << path.size() << "\n";
      for (auto v : path) {
        cout << v + 1 << " ";
      }
      cout << "\n";
    }
    return;
  }

  g.clear();
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    g[parent[i]].push_back(i);
  }
  cout << "NO\n";
  res = 0;
  int cur_res = dfs_ans(0);
  res += cur_res;
  cout << res << "\n";

}