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

//#define int li
const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void add(int& cur, int val) {
  cur += val;
  if (cur >= mod) {
    cur -= mod;
  }
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
  map<int, int> cached_res;
  int cached_all_less = -1;
  clock_t start = clock();
  vector<vector<int>> sum_dp(n + 1, vector<int>(n * 101 + 1, 0));
  sum_dp[0][0] = 1;
  while (Q--) {
    int x;
    cin >> x;
    if (x > c[0]) {
      cout << "0\n";
      continue;
    }
    if (cached_res.count(x)) {
      cout << cached_res[x] << "\n";
      continue;
    }
    bool valid = true;
    bool all_less = true;
    for (int i = 0; i < n; ++i) {
      int cur_sum = cached_b_sum[i] + x * (i + 1);
      if (cur_sum > 10000) {
        valid = false;
        break;
      }
      if (cur_sum > 0) {
        all_less = false;
      }
    }
    if (!valid) {
      cout << "0\n";
      continue;
    }
    if (all_less && cached_all_less != -1) {
      cout << cached_all_less << "\n";
      continue;
    }
    for (int i = 0; i < n; ++i) {
      sum_dp[i + 1].assign(n * 101 + 1, 0);
      for (int s = 0; s < sum_dp[i].size(); ++s) {
        if (sum_dp[i][s] == 0) {
          continue;
        }
        int min_take = max(x * (i + 1) + cached_b_sum[i] - s, 0);
        if (min_take <= c[i]) {
          add(sum_dp[i + 1][s + min_take], sum_dp[i][s]);
          add(sum_dp[i + 1][s + c[i] + 1], mod - sum_dp[i][s]);
        }
      }
      for (int s = 1; s < sum_dp[i + 1].size(); ++s) {
        add(sum_dp[i + 1][s], sum_dp[i + 1][s - 1]);
      }
    }
    int res = 0;
    for (auto& val : sum_dp[n]) {
      add(res, val);
    }
    if (all_less) {
      cached_all_less = res;
    } else {
      cached_res[x] = res;
    }
    /*if (clock() - start > 4.0 * CLOCKS_PER_SEC) {
      cout << cached_res.size() << endl;
      break;
    }*/
    cout << res << "\n";
  }

}