#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
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
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
#endif

#ifdef PINELY
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

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

void precalc() {
}

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = (rand() % 5 + 1) * 2;
  }
  vector<vector<int>> a(n, vector<int>(n));
  int stupid_res = 0;
  if (read) {
    for (auto& vec : a) {
      for (int& x : vec) {
        cin >> x;
      }
    }
  } else {
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        b[i][j] = rand() % 1000;
        stupid_res ^= b[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        a[i][j] = 0;
        if (i) {
          a[i][j] ^= b[i - 1][j];
        }
        if (i + 1 < n) {
          a[i][j] ^= b[i + 1][j];
        }
        if (j) {
          a[i][j] ^= b[i][j - 1];
        }
        if (j + 1 < n) {
          a[i][j] ^= b[i][j + 1];
        }
      }
    }
  }
  int res = 0;
  for (int w = 0; w < 2; ++w) {
    for (int diag = 2; diag < 2 * n; diag += 4) {
      int min_row = max(0, diag - (n - 1));
      for (int i = min_row; i <= diag && i < n; i += 2) {
        int j = diag - i;
        if (j < 0 || j >= n) {
          continue;
        }
        //cout << i << " " << j << endl;
        res ^= a[i][j];
      }
    }
    reverse(all(a));
  }
  cout << res << "\n";

  /*if (res != stupid_res) {
    cout << "FOUND res: " << res << " stupid: " << stupid_res << endl;
    exit(0);
  } else {
    cout << "ok\n";
  }*/

}