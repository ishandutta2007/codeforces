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
#include <complex>

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

const int C = 3000050;
int fact[C], rev_fact[C];

int get_c(int n, int k) {
  if (n < 0 || k > n) {
    return 0;
  }
  return fact[n] * rev_fact[k] % mod * rev_fact[n - k] % mod;
}

void add(int& cur, int val) {
  cur = (cur + val) % mod;
  if (cur < 0) {
    cur += mod;
  }
}

const int root3 = 82062379;

using Complex = complex<int>;

int mmod(int val) {
  val %= mod;
  if (val < 0) {
    val += mod;
  }
  return val;
}

Complex get_mod(Complex val) {
  return Complex(mmod(val.real()),
  mmod(val.imag()));
}

int sqr(int val) {
  return val * val % mod;
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
  int n, Q;
  //read = false;
  if (read) {
    cin >> n >> Q;
  } else {
    n = 1000000;
    Q = 20;
  }
  vector<vector<Complex>> dp(2, vector<Complex>(3 * n + 1, {0, 0}));
  int rev2 = binpow(2LL, mod - 2, mod);
  vector<Complex> roots = {
      Complex(1LL, 0LL),
      Complex((mod - rev2) % mod, root3 * rev2 % mod),
      Complex((mod - rev2) % mod, (mod - root3) * rev2 % mod),
  };
  int rev3 = binpow(3LL, mod - 2, mod);
  for (int r = 0; r < 2; ++r) {
    for (int y = 0; y <= 3 * n; ++y) {
      dp[r][0] += roots[y * (r + 1) % 3];
      dp[r][0] = get_mod(dp[r][0]);
    }
    for (int x = 1; x < dp[r].size(); ++x) {
      auto cur = get_mod(dp[r][x - 1] - Complex(get_c(3 * n + 1, x)));
      cur = get_mod(cur * roots[r + 1]);
      auto znam = Complex(1 - roots[r + 1].real(), -roots[r + 1].imag());
      auto sop = Complex(1 - roots[r + 1].real(), roots[r + 1].imag());
      //int dist = get_mod(znam * sop).real();
      //cout << dist << "\n";
      cur = get_mod(cur * sop);
      //cur = get_mod(cur * Complex(binpow(dist, mod - 2, mod), 0LL));
      cur = get_mod(cur * Complex(rev3, 0LL));
      dp[r][x] = cur;
      //cout << r << " " << x << " " << dp[r][x].real() << " " << dp[r][x].imag() << endl;
    }
  }

  while (Q--) {
    int x;
    if (read) {
      cin >> x;
    } else {
      x = rand() % (3 * n) + 1;
    }
    //cout << x << " " << dp[0].size() << " " << dp[1].size() << endl;
    auto res_dp = get_mod(dp[0][x] + dp[1][x]);
    assert(res_dp.imag() == 0);
    int res = mmod(res_dp.real() + get_c(3 * n + 1, x + 1));
    res = res * rev3 % mod;
    cout << res << "\n";
  }
}