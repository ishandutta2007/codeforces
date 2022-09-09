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
const li mod = 998244353;
//using ull = unsigned long long;

int n;
vector<vector<int>> g;
li rev2;
struct DP {
  li expect = 0;
  li prob = 0;
  void relax(DP ot) {
    expect = (expect + ot.expect) % mod;
    prob = (prob + ot.prob) % mod;
  }
  DP compose(DP& ot) {
    return {(expect * ot.prob + prob * ot.expect) % mod, prob * ot.prob % mod};
  }
};

vector<vector<DP>> dp;

void dfs(int v, int p) {
  dp[v].assign(2, {0, 0});
  if (g[v].size() == 1 && v != p) {
    dp[v][0].prob = 1;
    return;
  }
  vector<DP> cur_dp(2, {0, 0});
  cur_dp[0].prob = 1;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    dfs(to, v);
    vector<DP> new_dp(2, {0, 0});
    for (int has_edge = 0; has_edge < 2; ++has_edge) {
      for (int used = 0; used < 2; ++used) {
        auto in_dp = cur_dp[has_edge].compose(dp[to][used]);
        in_dp.expect = (in_dp.expect * rev2) % mod;
        in_dp.prob = (in_dp.prob * rev2) % mod;
        new_dp[has_edge].relax(in_dp);
        int new_has_edge = (has_edge || !used);
        new_dp[new_has_edge].relax(in_dp);
      }
    }
    new_dp.swap(cur_dp);
  }
  cur_dp[1].expect = (cur_dp[1].expect + cur_dp[1].prob) % mod;
  dp[v] = cur_dp;
  /*cout << "v: " << v + 1 << endl;
  for (int i = 0; i < 2; ++i) {
    cout << "i: " << i << " " << cur_dp[i].expect << " " << cur_dp[i].prob << endl;
  }*/
}

void solve(__attribute__((unused)) bool read) {
  rev2 = binpow(2LL, mod - 2, mod);
  //read = false;
  if (read) {
    cin >> n;
  } else{
    n = 500000;
  }
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    if (read) {
      cin >> a >> b;
      --a;
      --b;
    } else {
      b = i;
      a = i - 1;
    }
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dp.resize(n);
  dfs(0, 0);
  li res = (dp[0][0].expect + dp[0][1].expect) % mod;
  for (int i = 0; i < n; ++i) {
    res = res * 2 % mod;
  }
  cout << res << endl;
}