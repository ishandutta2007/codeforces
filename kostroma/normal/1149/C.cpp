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

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

vector<int> a;

const int C = 100500;
int pref_bal[C];
int suf_max_bal[C];

struct Block {
  int l, r;
  int min_balance;
  int max_balance;
  int whole_balance;
  int left_us, right_us, both_us;
  void recalc() {
    left_us = 0;
    right_us = 0;
    both_us = 0;
    pref_bal[0] = 0;
    for (int i = l; i < r; ++i) {
      pref_bal[i - l + 1] = pref_bal[i - l] + a[i];
    }
    for (int i = r; i >= l; --i) {
      suf_max_bal[i - l] = pref_bal[i - l];
      if (i < r) {
        relax_max(suf_max_bal[i - l], suf_max_bal[i - l + 1]);
      }
    }
    whole_balance = pref_bal[r - l];
    max_balance = suf_max_bal[0];
    min_balance = 0;
    int max_pref = 0;
    for (int i = l; i <= r; ++i) {
      relax_min(min_balance, pref_bal[i - l]);
      relax_max(max_pref, pref_bal[i - l]);
      relax_max(both_us, max_pref - 2 * pref_bal[i - l] + suf_max_bal[i - l]);
      relax_max(left_us, max_pref - 2 * pref_bal[i - l]);
      relax_max(right_us, suf_max_bal[i - l] - 2 * pref_bal[i - l]);
    }

  }
};

void solve(__attribute__((unused)) bool read) {
  int n, Q;
  cin >> n >> Q;
  n = 2 * (n - 1);
  a.resize(n);
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      a[i] = 1;
    } else {
      a[i] = -1;
    }
  }
  int block_size = max(1, (int)sqrt(n + Q));
  int n_blocks = (n - 1) / block_size + 1;
  vector<Block> blocks(n_blocks);
  for (int i = 0; i < n_blocks; ++i) {
    int l = i * block_size, r = min(n, (i + 1) * block_size);
    blocks[i].l = l;
    blocks[i].r = r;
    blocks[i].recalc();
  }

  vector<int> raw_vals(n_blocks), pref_bals(n_blocks + 1);

  auto calc_result = [&] () {
    int res = 0;
    int pref_sum = 0;
    int max_pref = 0;
    pref_bals[0] = 0;
    for (int i = 0; i < n_blocks; ++i) {
      auto& block = blocks[i];
      relax_max(res, block.both_us);
      int right_val = block.right_us - pref_sum;
      relax_max(res, right_val + max_pref);
      raw_vals[i] = -2 * (pref_sum + block.min_balance) + max_pref;
      relax_max(max_pref, pref_sum + block.max_balance);
      pref_sum += block.whole_balance;
      pref_bals[i + 1] = pref_sum;
      //cout << i << " " << res << endl;
    }
    int max_suf = pref_sum;
    for (int i = n_blocks - 1; i >= 0; --i) {
      auto& block = blocks[i];
      relax_max(res, raw_vals[i] + max_suf);
      int left_val = block.left_us - pref_bals[i];
      relax_max(res, left_val + max_suf);
      //cout << "relax left: " << left_val << " max_suf: " << max_suf << endl;
      relax_max(max_suf, pref_bals[i] + block.max_balance);
      //cout << i << " " << res << endl;
    }
    return res;
  };

  int last_res = calc_result();
  cout << last_res << "\n";
  while (Q--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    if (x > y) {
      swap(x, y);
    }
    if (a[x] == a[y]) {
      cout << last_res << "\n";
      continue;
    }
    int x_block = x / block_size;
    int y_block = y / block_size;
    swap(a[x], a[y]);
    blocks[x_block].recalc();
    if (x_block != y_block) {
      blocks[y_block].recalc();
    }
    last_res = calc_result();
    cout << last_res << "\n";
  }

}