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
const int mod = 998244353;
//using ull = unsigned long long;

int dp[2][2][210];
int sums[2][210];

void add(int& cur, int val) {
  cur += val;
  if (cur >= mod) {
    cur -= mod;
  }
  if (cur < 0) {
    cur += mod;
  }
}

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 100000;
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = -1;
    }
    if (a[i] > 0) {
      --a[i];
    }
  }
  int par = 0;
  for (int val = 0; val < 200; ++val) {
    if (a[0] != -1 && a[0] != val) {
      continue;
    }
    dp[par][0][val] = 1;
  }
  for (int i = 1; i < n; ++i) {
    memset(dp[par ^ 1], 0, sizeof dp[par ^ 1]);
    for (int c = 0; c < 2; ++c) {
      for (int val = 0; val < 200; ++val) {
        sums[c][val] = dp[par][c][val];
        if (val) {
          add(sums[c][val], sums[c][val - 1]);
        }
      }
      for (int val = 0; val < 200; ++val) {
        if (a[i] != -1 && a[i] != val) {
          continue;
        }
        int prev_less = (val == 0 ? 0 : sums[c][val - 1]);
        int prev_eq = sums[c][val] - prev_less;
        int prev_more = sums[c][199] - sums[c][val];
        /*if (prev_less + prev_eq + prev_more > 0) {
          cout << i << " " << c << " " << val << " " << prev_less << " " << prev_eq << " " << prev_more << endl;
        }*/
        add(dp[par ^ 1][0][val], prev_less);
        add(dp[par ^ 1][1][val], prev_eq);
        if (c == 1) {
          add(dp[par ^ 1][1][val], prev_more);
        }
      }
    }
    par ^= 1;
  }

  int res = 0;
  for (int val = 0; val < 200; ++val) {
    add(res, dp[par][1][val]);
  }
  cout << res << "\n";

}