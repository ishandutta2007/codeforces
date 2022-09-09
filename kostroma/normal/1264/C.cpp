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

void solve(__attribute__((unused)) bool read) {
  int n, Q;
  cin >> n >> Q;
  vector<int> p(n);
  vector<int> revs(105);
  for (int i = 1; i < revs.size(); ++i) {
    revs[i] = binpow(i, mod - 2, mod);
  }
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  vector<int> pref_prod(n + 1, 1);
  vector<int> pref_rev_prod(n + 1, 1);
  for (int i = 0; i < n; ++i) {
    int val = p[i] * revs[100] % mod;
    pref_prod[i + 1] = pref_prod[i] * val % mod;
    int rev_val = revs[p[i]] * 100 % mod;
    pref_rev_prod[i + 1] = pref_rev_prod[i] * rev_val % mod;
  }
  auto get_rev_prods = [&] (int l, int r) {
    return pref_rev_prod[r] * pref_prod[l] % mod;
  };
  auto get_prods = [&] (int l, int r) {
    return pref_prod[r] * pref_rev_prod[l] % mod;
  };
  vector<int> suffices(n + 1, 0);
  for (int i = n - 1; i >= 0; --i) {
    suffices[i] = (suffices[i + 1] + get_rev_prods(i, n)) % mod;
  }
  auto get_res = [&] (int l, int r) {
    int res = (suffices[l] - suffices[r]) * get_prods(r, n) % mod;
    if (res < 0) {
      res += mod;
    }
    return res;
  };
  int res = get_res(0, n);
  set<int> active;
  active.insert(0);
  active.insert(n);
  while (Q--) {
    int pos;
    cin >> pos;
    --pos;
    if (active.count(pos)) {
      auto it = active.lower_bound(pos);
      auto prev_index = *prev(it), next_index = *next(it);
      auto prev_res = get_res(prev_index, pos);
      auto next_res = get_res(pos, next_index);
      res -= prev_res + next_res;
      res += get_res(prev_index, next_index);
      res %= mod;
      if (res < 0) {
        res += mod;
      }
      active.erase(pos);
    } else {
      auto it = active.lower_bound(pos);
      auto prev_index = *prev(it), next_index = *it;
      auto prev_res = get_res(prev_index, pos);
      auto next_res = get_res(pos, next_index);
      res += prev_res + next_res;
      res -= get_res(prev_index, next_index);
      res %= mod;
      if (res < 0) {
        res += mod;
      }
      active.insert(pos);
    }
    cout << res << "\n";
  }

}