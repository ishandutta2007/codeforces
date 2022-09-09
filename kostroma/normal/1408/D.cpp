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

struct Point {
  int x, y;
  Point() : x(0), y(0) {}
  Point(int x, int y) : x(x), y(y) {}
  Point operator - (const Point& ot) const {
    return Point(x - ot.x, y - ot.y);
  }
  void scan() {
    cin >> x >> y;
  }
  bool operator < (const Point& ot) const {
    if (x != ot.x) {
      return x < ot.x;
    }
    return y < ot.y;
  }
};

void solve(__attribute__((unused)) bool read) {
  int n, m;
  //read = false;
  if (read) {
    cin >> n >> m;
  } else {
    n = 2000;
    m = 2000;
  }
  vector<Point> pts(n), proj(m);
  for (auto& pt : pts) {
    if (read) {
      pt.scan();
    } else {
      pt.x = rand() % (int)1e5;
      pt.y = rand() % (int)1e5;
    }
  }
  for (auto& pt : proj) {
    if (read) {
      pt.scan();
    } else {
      pt.x = rand() % (int)1e5 + (int)1e5;
      pt.y = rand() % (int)1e5 + (int)1e5;
    }
  }
  vector<Point> data;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      auto pt = proj[j] - pts[i];
      if (pt.x >= 0 && pt.y >= 0) {
        ++pt.x;
        ++pt.y;
        data.push_back(pt);
      }
    }
  }
  sort(all(data));
  vector<int> suf_max(data.size() + 1, 0);
  for (int i = (int)suf_max.size() - 2; i >= 0; --i) {
    suf_max[i] = max(suf_max[i + 1], data[i].y);
  }
  int res = suf_max[0];
  for (int i = 0; i < data.size(); ++i) {
    relax_min(res, suf_max[i + 1] + data[i].x);
  }
  cout << res << "\n";

}