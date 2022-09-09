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

#define int li
//const li mod = 1000000007;
const int mod = 998244353;
//using ull = unsigned long long;

const int C = 3010;
int dp[C][C];

void add(int& cur, int val) {
  cur += val;
  cur %= mod;
}

void solve(__attribute__((unused)) bool read) {
  int n, m;
  //read = false;
  if (read) {
    cin >> n >> m;
  } else {
    n = 200000;
    m = 3000;
  }
  vector<int> a(n), w(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = rand() % 2;
    }
  }
  int sums[2] = {0, 0};
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> w[i];
    } else {
      w[i] = rand() % (int)1e5 + 1;
    }
    sums[a[i]] += w[i];
  }
  dp[0][0] = 1;
  const int SHIFT = 2 * m;
  vector<int> cached_rev(2 * SHIFT + 5);
  for (int i = 0; i < cached_rev.size(); ++i) {
    cached_rev[i] = binpow(sums[0] + sums[1] + i - SHIFT, mod - 2, mod);
  }
  for (int pref = 0; pref < m; ++pref) {
    for (int p = 0; p <= pref; ++p) {
      int cur_dp = dp[pref][p];
      if (cur_dp == 0) {
        continue;
      }
      int mins = pref - p;
      int mult = cached_rev[SHIFT + p - mins];
      add(dp[pref + 1][p], (sums[0] - mins) * mult % mod * cur_dp);
      add(dp[pref + 1][p + 1], (sums[1] + p) * mult % mod * cur_dp);
    }
  }
  vector<int> frac(n);
  for (int i = 0; i < n; ++i) {
    frac[i] = w[i] * binpow(sums[a[i]], mod - 2, mod) % mod;
    if (!a[i]) {
      frac[i] = -frac[i];
    }
  }
  vector<int> new_sums(2, 0);
  for (int x = 0; x <= m; ++x) {
    //cout << dp[m][x] * 3 << endl;
    int y = m - x;
    add(new_sums[0], dp[m][x] * y);
    add(new_sums[1], dp[m][x] * x);
  }
  for (int i = 0; i < n; ++i) {
    int x = (frac[i] * new_sums[a[i]] + w[i]) % mod;
    if (x < 0) {
      x += mod;
    }
    if (read) {
      cout << x << "\n";
    }
  }

}