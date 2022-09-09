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

const int L = 21;

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto& vec : s) {
    cin >> vec;
  }
  vector<vector<int>> dp(n, vector<int>(m));
  vector<int> vals(m);
  for (int j = 0; j < m; ++j) {
    vals[j] = -1;
    for (int i = 0; i < n; ++i) {
      
      dp[i][j] = j;
      if (i == 0) {
        dp[i][j] = 0;
      }
      if (i > 0 && s[i - 1][j] == '.') {
        relax_min(dp[i][j], dp[i - 1][j]);
      }
      if (j > 0 && s[i][j - 1] == '.') {
        relax_min(dp[i][j], dp[i][j - 1]);
      }
      relax_max(vals[j], dp[i][j]);
      //cout << i << " " << j << " " << dp[i][j] << "\n";
    }
  }
  vector<vector<int>> sparse(L, vector<int>(m));
  sparse[0] = vals;
  for (int i = 1; i < L; ++i) {
    for (int j = 0; j < m; ++j) {
      int pos = j + (1 << (i - 1));
      if (pos < m) {
        sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][pos]);
      } else {
        sparse[i][j] = sparse[i - 1][j];
      }
    }
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int l, r;
    cin >> l >> r;
    --l;
    int bits = 0;
    while ((1 << (bits + 1)) <= r - l) {
      ++bits;
    }
    //int bits = 31 - __builtin_clz(r - l);
    int cur_res = max(sparse[bits][l], sparse[bits][r - (1 << bits)]);
    //cout << l << " " << r << " " << bits << " " << cur_res << endl;
    if (cur_res <= l) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}