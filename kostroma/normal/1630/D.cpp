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

#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void precalc() {
}

void solve(__attribute__((unused)) bool read) {
  int n, m;
  //read = false;
  if (read) {
    cin >> n >> m;
  } else {
    n = 1000000;
    m = 1;
  }
  vector<int> a(n);
  for (int& x : a) {
    if (read) {
      cin >> x;
    } else {
      x = rand() % (int)1e9 - (int)5e8;
    }
  }
  int d;
  if (read) {
    cin >> d;
  } else {
    d = 1000000;
  }
  for (int i = 1; i < m; ++i) {
    int cur;
    cin >> cur;
    d = gcd(d, cur);
  }

  auto kill = [&] () {
    int default_res = 0;
    for (int r = 0; r < d; ++r) {
      vector<pair<int, int>> positive, negative;
      int sum_mod = 0;
      int cnt_neg = 0;
      for (int i = r; i < n; i += d) {
        sum_mod += abs(a[i]);
        if (a[i] >= 0) {
          positive.emplace_back(a[i], i);
        } else {
          ++cnt_neg;
          negative.emplace_back(-a[i], i);
        }
      }
      sort(all(positive));
      sort(all(negative));
      if (positive.size() > 2) {
        positive.resize(2);
      }
      if (negative.size() > 2) {
        negative.resize(2);
      }
      int cur_res = sum_mod;
      if (cnt_neg % 2 == 1) {
        int cand = negative[0].first;
        if (!positive.empty()) {
          relax_min(cand, positive[0].first);
        }
        cur_res -= 2 * cand;
      }
      default_res += cur_res;
    }
    return default_res;
  };

  int res = kill();
  for (int i = 0; i < d; ++i) {
    a[i] = -a[i];
  }
  res = max(res, kill());
  cout << res << "\n";
}