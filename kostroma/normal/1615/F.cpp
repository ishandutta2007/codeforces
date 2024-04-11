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
  cin >> t;
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
  cur = (cur + val) % mod;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<string> s(2);
  for (int i = 0; i < 2; ++i) {
    cin >> s[i];
    for (int j = 1; j < s[i].length(); j += 2) {
      if (s[i][j] != '?') {
        s[i][j] = "10"[s[i][j] - '0'];
      }
    }
  }
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
  auto cnt = dp;
  cnt[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (s[0][i] != '0') {
        add(dp[i][j][1], dp[i][j][0]);
        add(cnt[i][j][1], cnt[i][j][0]);
      }
      /*cout << "i: " << i << " j: " << j << " cnt: " << cnt[i][j][0] << " " << cnt[i][j][1] <<
           " dp: " << dp[i][j][0] << " " << dp[i][j][1] << endl;*/
      if (j < n && s[1][j] != '0') {
        add(cnt[i + 1][j + 1][0], cnt[i][j][1]);
        add(dp[i + 1][j + 1][0], dp[i][j][1] + abs(i - j) * cnt[i][j][1]);
      }
      if (s[0][i] != '1') {
        add(cnt[i + 1][j][0], cnt[i][j][0]);
        add(dp[i + 1][j][0], dp[i][j][0]);
      }
      if (j < n && s[1][j] != '1') {
        add(cnt[i][j + 1][1], cnt[i][j][1]);
        add(dp[i][j + 1][1], dp[i][j][1]);
      }
    }
  }
  int res = 0;
  for (int i = n; i >= 0; --i) {
    if (i < n && s[1][i] == '1') {
      break;
    }
    //cout << i << " " << dp[n][i][0] << endl;
    add(res, dp[n][i][0]);
  }
  cout << res << "\n";

}