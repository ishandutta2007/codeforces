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

vector<vector<int>> g;

int dfs(int v, vector<int>& res) {
  if (g[v].empty()) {
    return v;
  }
  vector<pair<int, int>> paths;
  for (int to : g[v]) {
    int st = dfs(to, res);
    paths.emplace_back(st, to);
  }
  for (int i = 0; i < paths.size(); ++i) {
    res[paths[i].second] = (i + 1 < paths.size() ? paths[i + 1].first : v);
  }
  return paths[0].first;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
    --x;
  }
  vector<vector<int>> cycles;
  vector<int> used(n, -1);
  vector<int> vec;
  vector<int> res(n, -1);
  vector<char> in_cycle(n, false);
  for (int i = 0; i < n; ++i) {
    vec.clear();
    int cur = i;
    while (used[cur] == -1) {
      used[cur] = i;
      vec.push_back(cur);
      cur = a[cur];
    }
    if (used[cur] < i) {
      continue;
    }
    auto it = find(all(vec), cur);
    assert(it != vec.end());
    vec.erase(vec.begin(), it);
    cycles.push_back(vec);
    for (int j = 0; j < vec.size(); ++j) {
      res[vec[j]] = vec[(j + 1) % vec.size()];
      in_cycle[vec[j]] = true;
      //cout << vec[j] << " ";
    }
    //cout << endl;
  }
  g.clear();
  g.resize(n);
  vector<int> roots;
  for (int i = 0; i < n; ++i) {
    if (in_cycle[i]) {
      continue;
    }
    if (in_cycle[a[i]]) {
      roots.push_back(i);
      continue;
    }
    g[a[i]].push_back(i);
  }
  vector<pair<int, int>> paths;
  for (int root : roots) {
    int st = dfs(root, res);
    paths.emplace_back(st, root);
  }
  for (int i = 0; i < paths.size(); ++i) {
    res[paths[i].second] = paths[(i + 1) % paths.size()].first;
  }
  if (paths.size() == 1 && paths[0].first == paths[0].second) {
    int pos = paths[0].first;
    int need = a[pos];
    bool f = false;
    for (int i = 0; i < n; ++i) {
      if (res[i] == need) {
        res[i] = pos;
        res[pos] = need;
        f = true;
        break;
      }
    }
    assert(f);
  }
  int k = 0;
  for (int i = 0; i < n; ++i) {
    k += (a[i] == res[i]);
  }
  cout << k << "\n";
  for (int i = 0; i < n; ++i) {
    assert(i != res[i]);
    cout << res[i] + 1 << " ";
  }
  cout << "\n";
}