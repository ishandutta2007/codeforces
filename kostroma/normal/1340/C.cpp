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
  int len, n;
  //read = false;
  if (read) {
    cin >> len >> n;
  } else {
    len = 1000000;
    n = 10000;
  }
  vector<int> a(n);
  for (int& x : a) {
    if (read) {
      cin >> x;
    } else {
      x = rand() % n;
    }
  }
  make_unique(a);
  n = a.size();
  int g, r;
  if (read) {
    cin >> g >> r;
  } else {
    g = r = 1000;
  }
  vector<bitset<1001>> used(n);
  used[0][0] = true;
  vector<int> roots = {0};
  vector<vector<int>> dp(g);
  vector<int> new_roots;
  li res = 0;
  while (!roots.empty()) {
    dp[0] = roots;
    for (int x : roots) {
      if (x == n - 1) {
        cout << res - r << "\n";
        return;
      }
    }
    new_roots.clear();
    for (int rem = 0; rem < g; ++rem) {
      for (int v : dp[rem]) {
        if (v == n - 1) {
          res += rem;
          cout << res << "\n";
          return;
        }
        for (int d = -1; d <= 1; d += 2) {
          int pos = v + d;
          if (pos >= 0 && pos < n) {
            int diff = abs(a[pos] - a[v]);
            if (diff + rem < g) {
              if (!used[pos][diff + rem]) {
                used[pos][diff + rem] = true;
                dp[diff + rem].push_back(pos);
              }
            } else if (diff + rem == g) {
              if (!used[pos][0]) {
                used[pos][0] = true;
                new_roots.push_back(pos);
              }
            }
          }
        }
      }
      dp[rem].clear();
    }
    res += (g + r);
    roots.swap(new_roots);
  }

  cout << "-1\n";

}