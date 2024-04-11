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

#define int li
//const li mod = 1000000007;
const int mod = 998244353;
//using ull = unsigned long long;

void precalc() {
}

void add(int& cur, int val) {
  cur = (cur + val) % mod;
}

void solve(__attribute__((unused)) bool read) {
  string s;
  //read = false;
  if (read) {
    cin >> s;
  } else {
    s = string(200000, '1');
    for (int i = 1; i < s.length(); ++i) {
      if (rand() & 1) {
        s[i] = '0';
      }
    }
  }
  int n = (int)s.length();
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
  }
  vector<vector<int>> dp(8, vector<int>(8, 0));
  dp[7][0] = 1;
  vector<vector<int>> next_dp;
  for (int pos = 0; pos < n; ++pos) {
    next_dp.assign(8, vector<int>(8, 0));
    for (int mask = 0; mask < 8; ++mask) {
      for (int val_mask = 0; val_mask < 8; ++val_mask) {
        int next_mask = mask;
        bool f = true;
        for (int i = 0; i < 3; ++i) {
          if (a[pos] == 0 && (val_mask & (1 << i)) && (mask & (1 << i))) {
            f = false;
            break;
          }
          if ((mask & (1 << i)) && a[pos] == 1 && !(val_mask & (1 << i))) {
            next_mask ^= (1 << i);
          }
        }
        if (!f) {
          continue;
        }
        if (val_mask == 0 || val_mask == 7) {
          for (int fr = 0; fr < 8; ++fr) {
            add(next_dp[next_mask][fr], dp[mask][fr]);
          }
        } else {
          int new_min = __builtin_ctz(val_mask);
          if (__builtin_popcount(val_mask) == 2) {
            new_min = __builtin_ctz(7 - val_mask);
          }
          for (int fr = 0; fr < 8; ++fr) {
            auto& nex = next_dp[next_mask][fr | (1 << new_min)];
            add(next_dp[next_mask][fr | (1 << new_min)], dp[mask][fr]);
          }
        }
      }
    }
    next_dp.swap(dp);
  }
  int res = 0;
  for (int mask = 0; mask < 8; ++mask) {
    //cout << dp[mask][7] << " ";
    add(res, dp[mask][7]);
  }
  cout << res << "\n";

}