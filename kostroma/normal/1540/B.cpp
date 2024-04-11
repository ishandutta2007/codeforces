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

#define int li
const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

vector<vector<int>> g;
vector<int> depth;
vector<vector<int>> parent;
vector<int> tin, tout;
int TIMER = 1;

void dfs(int v, int p) {
  tin[v] = TIMER++;
  parent[0][v] = p;
  for (int i = 1; i < parent.size(); ++i) {
    parent[i][v] = parent[i - 1][parent[i - 1][v]];
  }
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    depth[to] = depth[v] + 1;
    dfs(to, v);
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
  for (int i = (int)parent.size() - 1; i >= 0; --i) {
    if (!upper(parent[i][a], b)) {
      a = parent[i][a];
    }
  }
  return parent[0][a];
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  g.resize(n);
  tin.resize(n);
  tout.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> revs(2 * n + 5);
  for (int i = 1; i < revs.size(); ++i) {
    revs[i] = binpow(i, mod - 2, mod);
  }
  int res = 0;
  const int L = 10;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int a = 0; a < dp.size(); ++a) {
    for (int b = 0; b < dp.size(); ++b) {
      if (a == 0) {
        dp[a][b] = 1;
        continue;
      }
      if (b == 0) {
        dp[a][b] = 0;
        continue;
      }
      dp[a][b] = (dp[a - 1][b] + dp[a][b - 1]) * revs[2] % mod;
    }
  }
  for (int r = 0; r < n; ++r) {
    depth.assign(n, 0);
    parent.assign(L, vector<int>(n, -1));
    dfs(r, r);
    //double cur_res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int v = lca(i, j);
        int a = depth[i] - depth[v], b = depth[j] - depth[v];
        res += dp[b][a];
        //cur_res += a / 1.0 / (a + b);
        //cout << "root: " << r + 1 << " i: " << i + 1 << " j: " << j + 1 << " v: " << v + 1 << endl; // " a: " << a << " b: " << b << " res: " << res << endl;
        res %= mod;
      }
    }
    /*int stupid_up = 0, stupid_down = 0;
    while (stupid_down < 100000) {
      ++stupid_down;
      vector<int> vec = {r};
      vector<char> used(n, false);
      used[r] = true;
      while (vec.size() < n) {
        vector<int> adj;
        for (int v : vec) {
          for (int to : g[v]) {
            if (!used[to]) {
              adj.push_back(to);
            }
          }
        }
        int take = adj[rand() % adj.size()];
        vec.push_back(take);
        used[take] = true;
      }
      for (int i = 0; i < vec.size(); ++i) {
        for (int j = i + 1; j < vec.size(); ++j) {
          if (vec[i] > vec[j]) {
            stupid_up++;
          }
        }
      }
    }
    cout << "r: " << r + 1 << " res: " << cur_res << " stupid: " << stupid_up / 1. / stupid_down << endl;*/
  }
  res = res * revs[n] % mod;
  cout << res << "\n";
}