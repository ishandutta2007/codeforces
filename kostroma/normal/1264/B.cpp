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

void solve(__attribute__((unused)) bool read) {
  vector<int> cnt(4, 0);
  for (int i = 0; i < 4; ++i) {
    cin >> cnt[i];
  }
  int overall_cnt = accumulate(all(cnt), 0);
  for (int t = 0; t < 2; ++t) {
    int a = (t == 0 ? 0 : 3);
    int b = (t == 0 ? 1 : 2);
    if (cnt[a] + cnt[b] == overall_cnt && cnt[a] == cnt[b] + 1) {
      cout << "YES\n";
      for (int i = 0; i < cnt[b]; ++i) {
        cout << a << " " << b << " ";
      }
      cout << a << "\n";
      return;
    }
  }
  if (cnt[0] > cnt[1] || cnt[3] > cnt[2]) {
    cout << "NO\n";
    return;
  }
  vector<int> pref, suf;
  while (cnt[0] > 0) {
    pref.push_back(0);
    --cnt[0];
    pref.push_back(1);
    --cnt[1];
  }
  while (cnt[3] > 0) {
    suf.push_back(3);
    --cnt[3];
    suf.push_back(2);
    --cnt[2];
  }
  if (abs(cnt[1] - cnt[2]) > 1) {
    cout << "NO\n";
    return;
  }
  if (cnt[1] > cnt[2]) {
    pref.insert(pref.begin(), 1);
    --cnt[1];
  } else if (cnt[2] > cnt[1]) {
    suf.insert(suf.begin(), 2);
    --cnt[2];
  }
  assert(cnt[1] == cnt[2]);
  while (cnt[1] > 0) {
    pref.push_back(2);
    pref.push_back(1);
    --cnt[1];
    --cnt[2];
  }
  auto res = pref;
  reverse(all(suf));
  for (int x : suf) {
    res.push_back(x);
  }
  cout << "YES\n";
  for (int x : res) {
    cout << x << " ";
  }
  cout << "\n";
}