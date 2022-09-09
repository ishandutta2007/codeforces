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
  int n, m;
  if (read) {
    cin >> n >> m;
  } else {
    n = rand() % 5000 + 1;
    m = rand() % max(n * (n - 1) / 4, 1);
  }
  int M = m;
  vector<int> res = {1};
  for (int k = 2; res.size() < n; ++k) {
    int adding = (k - 1) / 2;
    if (adding <= m) {
      m -= adding;
      res.push_back(k);
    } else {
      break;
    }
  }
  int k = res.back();
  if (m > 0) {
    if (res.size() == n) {
      cout << "-1\n";
      return;
    }
    for (int next_val = k + 1;; ++next_val) {
      int lef = next_val - k;
      int rig = min(k, (next_val - 1) / 2);
      int adding = max(0, rig - lef + 1);
      if (adding == m) {
        res.push_back(next_val);
        m = 0;
        break;
      }
    }
  }
  if (n > res.size()) {
    int mx = res.back() + 2;
    n -= (int)res.size();
    int L = max(mx * n + 2, mx * 2);
    for (int i = 0; i < n; ++i) {
      res.push_back(L + i * mx);
    }
  }
  if (read) {
    for (int x : res) {
      cout << x << " ";
    }
    cout << endl;
  }

  /*map<int, int> have;
  int sup = 0;
  for (int i = 0; i < res.size(); ++i) {
    sup += (int)have[res[i]];
    for (int j = 0; j < i; ++j) {
      have[res[i] + res[j]]++;
    }
  }
  cerr << "sup: " << sup << " M: " << M << " n: " << res.size() << endl;
  if (sup != M) {
    exit(0);
  }*/

}