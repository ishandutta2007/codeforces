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
 
#ifdef AIM
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
//const li mod = 998244353;
//using ull = unsigned long long;
#define int li
//const li mod = 1000000007;
const int mod = 998244353;
//using ull = unsigned long long;
 
const int L = 21;	// can be 23 for 998244353
const int N = (1 << L);
bool fft_initialized = false;
 
using Poly = vector<long long>;
 
long long pw(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1ll) {
      res = res * a % mod;
    }
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
 
int getRoot() {
  int root = 1;
  while (pw(root, 1 << L) != 1 || pw(root, 1 << (L - 1)) == 1) {
    ++root;
  }
  return root;
}
 
const int root = getRoot();
 
long long angles[N + 1];
int bitrev[N];
 
void fft_init() {
  if (fft_initialized) {
    return;
  }
  angles[0] = 1;
  for (int i = 1; i <= N; ++i) {
    angles[i] = angles[i - 1] * root % mod;
  }
 
  for (int i = 0; i < N; ++i) {
    int x = i;
    for (int j = 0; j < L; ++j) {
      bitrev[i] = (bitrev[i] << 1) | (x & 1);
      x >>= 1;
    }
  }
 
  fft_initialized = true;
}
 
inline int revBit(int x, int len) {
  return bitrev[x] >> (L - len);
}
 
void fft(vector<long long>& a, bool inverse = false) {
  assert(fft_initialized && "you fucking cunt just write fft_init()");
  int n = a.size();
  assert(!(n & (n - 1)));	// work only with powers of two
  int l = __builtin_ctz(n);
  for (int i = 0; i < n; ++i) {
    int j = revBit(i, l);
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
 
  for (int len = 1; len < n; len *= 2) {
    for (int start = 0; start < n; start += 2 * len) {
      for (int i = 0; i < len; ++i) {
        long long x = a[start + i], y = a[start + len + i];
        int idx = N / 2 / len * i;
        long long w = angles[inverse ? N - idx : idx];
        w = w * y % mod;
        a[start + i] = x + w;
        if (a[start + i] >= mod) {
          a[start + i] -= mod;
        }
        a[start + len + i] = x - w;
        if (a[start + len + i] < 0) {
          a[start + len + i] += mod;
        }
      }
    }
  }
 
  if (inverse) {
    int rev_deg = 1;
    for (int i = 0; i < l; ++i) {
      rev_deg = (rev_deg % 2) ? ((rev_deg + mod) / 2) : (rev_deg / 2);
    }
    for (auto& x : a) {
      x = x * rev_deg % mod;
    }
  }
}
 
Poly multiply(Poly a, Poly b) {
  int n = 1;
  while (n < (int)a.size() || n < (int)b.size()) {
    n *= 2;
  }
  a.resize(n + n);
  b.resize(n + n);
  fft(a);
  fft(b);
  for (int i = 0; i < n + n; ++i) {
    a[i] = a[i] * b[i] % mod;
  }
  fft(a, true);
  while (!a.empty() && a.back() == 0) {
    a.pop_back();
  }
  return a;
}
 
void add(int& cur, int val) {
  cur = (cur + val) % mod;
}
 
Poly sum(Poly a, Poly b) {
  Poly res(max(a.size(), b.size()), 0);
  for (int i = 0; i < res.size(); ++i) {
    if (i < a.size()) {
      add(res[i], a[i]);
    }
    if (i < b.size()) {
      add(res[i], b[i]);
    }
  }
  return res;
}
 
map<int, Poly> dp;
 
Poly get_res(int n) {
  if (dp.count(n)) {
    return dp[n];
  }
  dp[n] = {};
  if (n < 0) {
    return dp[n];
  }
  if (n <= 1) {
    return dp[n] = {1};
  }
  if (n == 2) {
    return dp[n] = {1, 1};
  }
  int half = n / 2;
  auto f = get_res(half);
  auto s = get_res(n - half);
  dp[n] = multiply(f, s);
  f = get_res(half - 1);
  s = get_res(n - half - 1);
  auto cur_vec = multiply(f, s);
  cur_vec.insert(cur_vec.begin(), 0);
  dp[n] = sum(dp[n], cur_vec);
  return dp[n];
}
 
const int C = 5500;
int fact[C];
int revfact[C];
 
int getA(int n, int k) {
  return fact[n] * revfact[n - k] % mod;
}
 
void solve(__attribute__((unused)) bool read) {
  if (fact[0] == 0) {
    fact[0] = 1;
    for (int i = 1; i < C; ++i) {
      fact[i] = fact[i - 1] * i % mod;
    }
    revfact[C - 1] = binpow(fact[C - 1], mod - 2, mod);
    for (int i = C - 2; i >= 0; --i) {
      revfact[i] = revfact[i + 1] * (i + 1) % mod;
    }
  }
  dp.clear();
  fft_init();
  vector<vector<int>> used(2);
  int h, w;
  if (read) {
    cin >> h >> w;
  } else {
    h = 3600;
    w = 3600;
  }
  used[0].resize(h);
  used[1].resize(w);
  int N;
  if (read) {
    cin >> N;
  } else {
    N = 2400;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 2; ++j) {
      int r, c;
      if (read) {
        cin >> r >> c;
        --r;
        --c;
      } else {
        r = rand() % h;
        c = rand() % w;
      }
      used[0][r] = true;
      used[1][c] = true;
    }
  }
  vector<vector<int>> lens(2);
  map<int, Poly> results;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < used[i].size(); ) {
      int r = j;
      while (r < used[i].size() && used[i][r] == 0) {
        ++r;
      }
      if (r > j) {
        lens[i].push_back(r - j);
      }
      j = r + 1;
    }
  }
  for (auto& vec : lens) {
    for (int x : vec) {
      if (results.count(x)) {
        continue;
      }
      results[x] = get_res(x);
    }
  }
  vector<Poly> actual_results(2);
  vector<int> actual_sum(2);
  for (int i = 0; i < 2; ++i) {
    multiset<pair<int, Poly>> cur_set;
    for (int x : lens[i]) {
      cur_set.insert({x, results[x]});
    }
    if (cur_set.empty()) {
      cout << 1 << endl;
      return;
    }
    while (cur_set.size() > 1) {
      auto item1 = *cur_set.begin();
      cur_set.erase(cur_set.begin());
      auto item2 = *cur_set.begin();
      cur_set.erase(cur_set.begin());
      pair<int, Poly> new_item = {item1.first + item2.first, multiply(item1.second, item2.second)};
      cur_set.insert(new_item);
    }
    actual_sum[i] = cur_set.begin()->first;
    actual_results[i] = cur_set.begin()->second;
  }
  int res = 0;
  for (int take1 = 0; take1 < actual_results[0].size(); ++take1) {
    for (int take2 = 0; take2 < actual_results[1].size(); ++take2) {
      int rest1 = actual_sum[1] - 2 * take2;
      int rest2 = actual_sum[0] - 2 * take1;
      if (rest1 < take1 || rest2 < take2) {
        continue;
      }
      int cur_mult = getA(rest1, take1) * getA(rest2, take2) % mod * actual_results[0][take1] % mod * actual_results[1][take2] % mod;
      add(res, cur_mult);
    }
  }
  cout << res << endl;
}