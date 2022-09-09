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

void mmod(int& cur) {
  cur %= mod;
  if (cur < 0) {
    cur += mod;
  }
}

struct LinFun {
  int a, b; //a * x + b
  LinFun() : a(0), b(0) {}
  LinFun(int A, int B) {
    a = A;
    b = B;
    mmod(a);
    mmod(b);
  }
  LinFun operator + (const LinFun& ot) const {
    return LinFun(a + ot.a, b + ot.b);
  }
  LinFun operator - (const LinFun& ot) const {
    return LinFun(a + ot.a, b + ot.b);
  }
  LinFun operator * (int c) const {
    return LinFun(a * c, b * c);
  }
};

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int& x : a) {
    cin >> x;
    sum += x;
  }
  int rev_sum = binpow(sum, mod - 2, mod);
  int rev_n = binpow(n - 1, mod - 2, mod);
  vector<int> dp(sum, 0);
  dp[0] = n - 1;
  for (int k = 1; k < sum; ++k) {
    auto prob = k * rev_sum % mod;
    auto prob_inc = (1 - prob) * rev_n;
    mmod(prob_inc);
    auto steps_inc = binpow(prob_inc, mod - 2, mod);
    mmod(steps_inc);
    //cout << "prob_inc: " << prob_inc << " steps_inc: " << steps_inc << " " << steps_inc * 2 % mod << endl;
    auto prob_dec = prob * binpow((prob + (1 - rev_n) * (1 - prob)) % mod, mod - 2, mod) % mod;
    //cout << "prob_dec: " << prob_dec << " " << prob_dec * 2 % mod << endl;
    //cout << k << " " << prob_dec << endl;
    dp[k] = steps_inc + (steps_inc - 1) * dp[k - 1] % mod * prob_dec;
    mmod(dp[k]);
  }
  for (int k = sum - 1; k > 0; --k) {
    dp[k - 1] = (dp[k - 1] + dp[k]) % mod;
  }
  /*for (int i = 0; i < sum; ++i) {
    cout << i << " " << dp[i] << " " << dp[i] * 2 % mod << endl;
  }*/

  int res = -dp[0] * (n - 1) % mod;
  for (int x : a) {
    if (x == sum) {
      cout << "0\n";
      return;
    }
    res += dp[x];
    mmod(res);
  }
  res = res * binpow(n, mod - 2, mod);
  mmod(res);
  cout << res << "\n";
}