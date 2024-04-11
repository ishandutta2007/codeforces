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

void add(int& cur, int val) {
  cur += val;
  cur %= mod;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  vector<int> c;
  vector<int> b;
  cin >> n;
  c.resize(n);
  for (int& x : c) {
    cin >> x;
  }
  b.resize(n - 1);
  for (int& x : b) {
    cin >> x;
  }

  vector<int> b_pref_sum(n, 0);
  vector<int> cached_b_sum(n, 0);
  for (int k = 1; k < n; ++k) {
    b_pref_sum[k] = b_pref_sum[k - 1] + b[k - 1];
    cached_b_sum[k] = cached_b_sum[k - 1] + b_pref_sum[k];
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int x;
    cin >> x;
    if (x > c[0]) {
      cout << "0\n";
      continue;
    }
    vector<vector<int>> sum_dp(n + 1, vector<int>(n * 100 + 1, 0));
    sum_dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int s = 0; s < sum_dp[i].size(); ++s) {
        if (sum_dp[i][s] == 0) {
          continue;
        }
        for (int take = 0; take <= c[i]; ++take) {
          if (s + take >= x * (i + 1) + cached_b_sum[i]) {
            add(sum_dp[i + 1][s + take], sum_dp[i][s]);
          }
        }
      }
    }
    int res = 0;
    for (auto& val : sum_dp[n]) {
      add(res, val);
    }
    cout << res << "\n";
  }

}