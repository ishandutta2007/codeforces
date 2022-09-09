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

void precalc() {

}

#define int li
//const li mod = 1000000007;
//using ull = unsigned long long;

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
  Point operator - (const Point& ot) const {
    return Point(x - ot.x, y - ot.y);
  }
  int operator * (const Point& ot) const {
    return x * ot.y - y * ot.x;
  }
  bool top() const {
    return y > 0 || y == 0 && x > 0;
  }

};

bool cmp(const Point& q, const Point& w) {
  if (q.top() != w.top()) {
    return q.top();
  }
  return q * w > 0;
}

li getC(int n) {
  return (li)n * (n - 1) / 2;
}

li get_ans(vector<Point> points) {
  vector<pair<Point, int>> to_sort;
  int up = 0, down = 0;
  for (auto item : points) {
    if (item.top()) {
      to_sort.push_back({item, 1});
      ++up;
    } else {
      to_sort.push_back({Point(-item.x, -item.y), -1});
      ++down;
    }
  }
  sort(all(to_sort), [&] (const pair<Point, int>& q, const pair<Point, int>& w) {
    return q.first * w.first > 0;
  });
  li res = 0;
  for (auto& item : to_sort) {
    if (item.second == 1) {
      --up;
    } else {
      --down;
    }
    res += getC(up) * getC(down);
    if (item.second == 1) {
      ++down;
    } else {
      ++up;
    }
  }
  return res;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<Point> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> points[i].x >> points[i].y;
  }
  li ans = 0;
  for (int c = 0; c < n; ++c) {
    vector<Point> cur;
    for (int i = 0; i < n; ++i) {
      if (i != c) {
        cur.push_back(points[i] - points[c]);
      }
    }
    ans += get_ans(cur);
  }
  assert(ans % 2 == 0);
  cout << ans / 2 << "\n";
}