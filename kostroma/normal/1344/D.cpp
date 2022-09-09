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
//const int mod = 998244353;
//using ull = unsigned long long;

void solve(__attribute__((unused)) bool read) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  int L = -(int)4e18 - 100, R = (int)1e9 + 100;

  vector<int> b(n);

  auto get_b = [&](int border) {
    if (border <= 0) {
      return -1LL;
    }
    double bb = sqrt((border - 1) / 3.);
    int L = max(0LL, (int)bb - 5), R = (int)(bb + 5);
    //cout << border << " " << L << " " << R << endl;
    while (L + 1 < R) {
      int M = (L + R) / 2;
      if (3 * (M * M + M) + 1 <= border) {
        L = M;
      } else {
        R = M;
      }
    }
    //assert(3 * L * (L + 1) + 1 <= border);
    return L;
  };

  vector<int> exact;

  auto fill_b = [&] (int M, int max_sum) {
    int s = 0;
    exact.clear();
    for (int i = 0; i < n; ++i) {
      int border = a[i] - M;
      int cur_b = min(get_b(border), a[i] - 1);
      if (cur_b * (cur_b + 1) * 3 + 1 == border) {
        exact.push_back(i);
      }
      b[i] = cur_b + 1;
      s += b[i];
    }
    /*if (max_sum == k) {
      cout << s << " " << max_sum << endl;
      for (int x : exact) {
        cout << x << " ";
      }
      cout << endl;
    }*/
    assert(s <= max_sum + exact.size());
    while (s > max_sum) {
      --b[exact.back()];
      exact.pop_back();
      --s;
    }
  };

  while (L + 1 < R) {
    int M = (L + R) / 2;
    fill_b(M, (int)1e18);
    int s = accumulate(all(b), 0LL);
    if (s < k) {
      R = M;
    } else {
      L = M;
    }
  }

  //cout << L << " " << R << endl;

  fill_b(L, k);
  for (int x : b) {
    cout << x << " ";
  }
  cout << "\n";

}