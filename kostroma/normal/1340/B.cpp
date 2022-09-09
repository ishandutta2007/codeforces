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

const int C = 2010;
int suf_dp[C][C];

void solve(__attribute__((unused)) bool read) {
  vector<vector<int>> nums = {
      {0, 1, 2, 4, 5, 6},
      {2, 5},
      {0, 2, 3, 4, 6},
      {0,2,3,5,6},
      {2,5,3,1},
      {0,1,3,5,6},
      {0,1,3,4,5,6},
      {0,2,5},
      {0,1,2,3,4,5,6},
      {0,1,2,3,5,6}
  };
  vector<int> masks(10);
  for (int i = 0; i < 10; ++i) {
    for (int j : nums[i]) {
      masks[i] |= (1 << j);
    }
  }

  int n, k;
  cin >> n >> k;
  vector<int> input_mask(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < 7; ++j) {
      if (s[j] == '1') {
        input_mask[i] |= (1 << j);
      }
    }
  }
  suf_dp[n][0] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 9; j >= 0; --j) {
      if ((masks[j] & input_mask[i]) == input_mask[i]) {
        int take = __builtin_popcount(masks[j] ^ input_mask[i]);
        for (int was = 0; was + take <= k; ++was) {
          if (suf_dp[i + 1][was]) {
            suf_dp[i][was + take] = 1;
          }
        }
      }
    }
  }
  if (suf_dp[0][k] == 0) {
    cout << "-1\n";
    return;
  }
  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 9; j >= 0; --j) {
      if ((masks[j] & input_mask[i]) == input_mask[i]) {
        int take = __builtin_popcount(masks[j] ^ input_mask[i]);
        if (suf_dp[i + 1][k - take]) {
          k -= take;
          res[i] = j;
          break;
        }
      }
    }
  }
  for (int x : res) {
    cout << x;
  }
  cout << "\n";

}