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
  int n;
  cin >> n;
  vector<vector<int>> pts(n);
  for (int i = 0; i < n; ++i) {
    pts[i].resize(4);
    pts[i][3] = i;
    for (int j = 0; j < 3; ++j) {
      cin >> pts[i][j];
    }
  }
  sort(all(pts));
  vector<pair<int, int>> res;
  for (int w = 2; w >= 0; --w) {
    vector<char> used(pts.size(), false);
    for (int i = 0; i + 1 < pts.size(); ++i) {
      if (used[i]) {
        continue;
      }
      bool can = true;
      for (int j = 0; j < w; ++j) {
        if (pts[i][j] != pts[i + 1][j]) {
          can = false;
          break;
        }
      }
      if (can) {
        res.emplace_back(pts[i][3], pts[i + 1][3]);
        used[i] = used[i + 1] = true;
      }
    }
    vector<vector<int>> new_pts;
    for (int i = 0; i < pts.size(); ++i) {
      if (!used[i]) {
        new_pts.push_back(pts[i]);
      }
    }
    pts.swap(new_pts);
  }
  assert(pts.empty());
  for (auto item : res) {
    cout << item.first + 1 << " " << item.second + 1 << "\n";
  }
}