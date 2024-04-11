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
    cin >> t;
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

const int C = 300500;
int fact[C], rev_fact[C];
int powers[C];

const int L = 20;	// can be 23 for 998244353
const int N = 1 << L;
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

Poly cache;

void precalc() {
  fact[0] = powers[0] = 1;
  int rev_2 = binpow(2LL, mod - 2, mod);
  for (int i = 1; i < C; ++i) {
    fact[i] = fact[i - 1] * i % mod;
    powers[i] = powers[i - 1] * rev_2 % mod;
  }
  rev_fact[C - 1] = binpow(fact[C - 1], mod - 2, mod);
  for (int i = C - 2; i >= 0; --i) {
    rev_fact[i] = rev_fact[i + 1] * (i + 1) % mod;
  }
  fft_init();

  Poly a(C);
  for (int i = 0; i * 2 < a.size(); ++i) {
    a[i * 2] = rev_fact[i] * powers[i] % mod;
  }
  Poly b(C);
  for (int i = 0; i < b.size(); ++i) {
    b[i] = rev_fact[i];
  }
  cache = multiply(a, b);
}

int get_c(int n, int k) {
  if (k > n || k < 0) {
    return 0;
  }
  return fact[n] * rev_fact[k] % mod * rev_fact[n - k] % mod;
}

void add(int& cur, int val) {
  cur = (cur + val) % mod;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  int res = 0;
  for (int a = 0; a * 4 <= n; ++a) {
    int mult = fact[n - 2 * a] * rev_fact[a] % mod;
    int cur_res = cache[n - 4 * a];
    add(res, mult * cur_res);
  }
  cout << res << "\n";
}