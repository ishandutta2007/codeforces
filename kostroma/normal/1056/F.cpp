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

const int C = 111;
double dp[2][C][C * 10];
const double INF = 1e12;

void solve(__attribute__((unused)) bool read) {
  int n;
  double C, T;
  cin >> n >> C >> T;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.rbegin(), a.rend());
  int par = 0;
  auto clear_dp = [&] (int p) {
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n * 10; ++j) {
        dp[p][i][j] = INF;
      }
    }
  };
  clear_dp(par);
  vector<double> powers(n + 1, 1);
  for (int i = 1; i < powers.size(); ++i) {
    powers[i] = powers[i - 1] / 0.9;
  }
  dp[par][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    clear_dp(par ^ 1);
    for (int taken = 0; taken <= i; ++taken) {
      for (int score = 0; score <= taken * 10; ++score) {
        auto cur_dp = dp[par][taken][score];
        if (cur_dp > INF / 2) {
          continue;
        }
        relax_min(dp[par ^ 1][taken][score], cur_dp);
        relax_min(dp[par ^ 1][taken + 1][score + a[i].second], cur_dp + a[i].first * powers[taken + 1]);
      }
    }
    par ^= 1;
  }
  int ans = 0;
  for (int taken = 0; taken <= n; ++taken) {
    for (int score = 0; score <= taken * 10; ++score) {
      auto cur_dp = dp[par][taken][score];
      if (cur_dp > INF / 2) {
        continue;
      }
      double t = (sqrt(C * cur_dp) - 1) / C;
      relax_max(t, 0.);
      relax_min(t, T);
      double current_time = t + 10 * taken + cur_dp / (1 + C * t);
      if (current_time <= T) {
        relax_max(ans, score);
      }
    }
  }

  cout << ans << endl;

}