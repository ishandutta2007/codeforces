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

vector<vector<int>> g;
vector<vector<int>> dp;

int dfs(int v, int p) {
  dp[v][0] = 0;
  dp[v][1] = 1;
  int inner_dp[2] = {0, 0};
  int res = 0;
  int cnt = g[v].size();
  if (v != p) {
    --cnt;
  }
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    relax_max(res, dfs(to, v));
    relax_max(res, inner_dp[0] + max(dp[to][0], dp[to][1]) + cnt - 2 + (v != p));
    relax_max(res, inner_dp[1] + dp[to][0] + 1);
    for (int i = 0; i < 2; ++i) {
      relax_max(inner_dp[0], dp[to][i]);
      if (i == 0) {
        relax_max(inner_dp[1], dp[to][i]);
      }
    }
  }
  relax_max(dp[v][0], max(inner_dp[0], inner_dp[1]) + cnt - 1);
  dp[v][1] = inner_dp[1] + 1;
  relax_max(res, max(dp[v][0], dp[v][1]));
  //cout << v << " " << dp[v][0] << " " << dp[v][1] << endl;
  return res;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dp.assign(n, vector<int>(2));
  int res = dfs(0, 0);
  cout << res << "\n";

}