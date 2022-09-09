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

#define int li
//const li mod = 1000000007;
const int mod = 998244353;
//using ull = unsigned long long;

const int C = 100500;
int fact[C], rev_fact[C];

int get_c(int n, int k) {
  //cout << n << " " << k << endl;
  if (n < 0 || k > n) {
    return 0;
  }
  return fact[n] * rev_fact[k] % mod * rev_fact[n - k] % mod;
}

void solve(__attribute__((unused)) bool read) {
  fact[0] = 1;
  for (int i = 1; i < C; ++i) {
    fact[i] = fact[i - 1] * i % mod;
  }
  rev_fact[C - 1] = binpow(fact[C - 1], mod - 2, mod);
  for (int i = C - 2; i >= 0; --i) {
    rev_fact[i] = rev_fact[i + 1] * (i + 1) % mod;
  }
  int n;
  cin >> n;
  vector<vector<int>> cnt(2, vector<int>(2)); // [left, right][white, black]
  bool has_dif = false;
  int prod = 1;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    bool has_question = false;
    for (int j = 0; j < 2; ++j) {
      if (s[j] == '?') {
        has_question = true;
        continue;
      }
      if (j == 1) {
        s[j] = "WB"[s[j] == 'W'];
      }
      ++cnt[j][s[j] == 'B'];
    }
    if (!has_question) {
      if (s[0] != s[1]) {
        has_dif = true;
      }
    } else if (s[0] == s[1]) {
      prod = prod * 2 % mod;
    }
  }
  int res = 0;
  for (int white = 0; white <= n; ++white) {
    int black = n - white;
    if (cnt[0][0] > white || cnt[0][1] > black || cnt[1][0] > white || cnt[1][1] > black) {
      continue;
    }
    int lef_used = cnt[0][0] + cnt[0][1], rig_used = cnt[1][0] + cnt[1][1];
    //cout << white << " " << lef_used << " " << rig_used << endl;
    res += get_c(n - lef_used, white - cnt[0][0]) *
        get_c(n - rig_used, white - cnt[1][0]);
    res %= mod;
  }
  if (!has_dif) {
    for (int i = 0; i < 2; ++i) {
      if (cnt[0][i] + cnt[1][i] == 0) {
        --prod;
      }
    }
    res = (res + mod - prod) % mod;
  }
  cout << res << "\n";
}