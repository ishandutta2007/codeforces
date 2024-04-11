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
    //freopen("/Users/alexandero/Downloads/worklife_balance_chapter_2_input.txt", "r", stdin);
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

const int C = 200500;
int fact[C], rev_fact[C], pow2[C];

int get_c(int n, int k) {
  if (k > n || n < 0) {
    return 0;
  }
  return fact[n] * rev_fact[k] % mod * rev_fact[n - k] % mod;
}

void precalc() {
  fact[0] = 1;
  pow2[0] = 1;
  for (int i = 1; i < C; ++i) {
    fact[i] = fact[i - 1] * i % mod;
    pow2[i] = pow2[i - 1] * 2 % mod;
  }
  rev_fact[C - 1] = binpow(fact[C - 1], mod - 2, mod);
  for (int i = C - 2; i >= 0; --i) {
    rev_fact[i] = rev_fact[i + 1] * (i + 1) % mod;
  }
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  int pref_sum = 0, suf_sum = 0;
  int l = 0, r = n - 1;
  int res = 1;
  while (l <= r) {
    if (pref_sum < suf_sum) {
      pref_sum += a[l++];
      continue;
    } else if (pref_sum > suf_sum) {
      suf_sum += a[r--];
      continue;
    }
    int new_l = l, new_r = r;
    while (new_l <= r && a[new_l] == 0) {
      ++new_l;
    }
    while (new_r >= l && a[new_r] == 0) {
      --new_r;
    }
    if (new_l > r) {
      res = res * pow2[r - l + 2 * (l > 0)] % mod;
      break;
    }
    int lef_options = new_l - l;
    int rig_options = r - new_r;
    if (l > 0) {
      ++lef_options;
      ++rig_options;
    }
    int mult = get_c(lef_options + rig_options, lef_options);
    //cout << l << " " << r << " " << mult << endl;
    res = res * mult % mod;
    l = new_l;
    r = new_r;
    pref_sum += a[l++];
    suf_sum += a[r--];
  }
  if (l == r + 1 && pref_sum == suf_sum) {
    res = res * 2 % mod;
  }
  cout << res << '\n';
}