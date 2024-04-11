#pragma comment(linker, "/STACK:512000000")
#include <bits/stdc++.h>
#ifdef AIM
#include <sys/resource.h>
#endif
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
  string s = FILENAME;
//    assert(!s.empty());
  freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
//freopen("/home/alexandero/ClionProjects/cryptozoology/output.txt", "w", stdout);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif

#ifdef AIM
  const rlim_t kStackSize = 256 * 1024 * 1024;
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif

  precalc();
  cout.precision(10);
  cout << fixed;
  //cin >> t;
  int testNum = 1;
  while (t--) {
      //cout << "Case #" << testNum++ << ": ";
      solve(true);
  }
  cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
  cout.flush();
  auto end = clock();

  usleep(10000);
  print_stats(end - start);
  usleep(10000);
#endif

    return 0;
}

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
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
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

//#define int li
//const int mod = 1000000007;

struct Point {
  int x, y;
  int id;
};

const int INF = (int)1e9;

int get_res(vector<Point> points) {
  int n = points.size();
  sort(all(points), [&](const Point& q, const Point& w) {
    if (q.x != w.x) {
      return q.x > w.x;
    }
    return q.y > w.y;
  });
  vector<int> best_x(n, -INF), best_y(n, -INF);
  int max_val = -INF;
  for (int i = 0; i < points.size(); ++i) {
    relax_max(max_val, points[i].y);
    best_x[points[i].id] = max_val;
  }
  sort(all(points), [&](const Point& q, const Point& w) {
    if (q.y != w.y) {
      return q.y > w.y;
    }
    return q.x > w.x;
  });
  max_val = -INF;
  for (int i = 0; i < points.size(); ++i) {
    relax_max(max_val, points[i].x);
    best_y[points[i].id] = max_val;
  }
  int best_res = -INF;
  for (auto& pt : points) {
    int id = pt.id;
    relax_max(best_res, (best_x[id] - pt.x) * 2 + (best_y[id] - pt.y) * 2);
  }
  return best_res;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<Point> points(n);
  int minx = INF, maxx = -INF, miny = INF, maxy = -INF;
  for (int i = 0; i < n; ++i) {
    cin >> points[i].x >> points[i].y;
    points[i].id = i;
    relax_min(minx, points[i].x);
    relax_min(miny, points[i].y);
    relax_max(maxx, points[i].x);
    relax_max(maxy, points[i].y);
  }
  int large_ans = 2 * (maxx - minx + maxy - miny);
  int small_ans = -INF;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      relax_max(small_ans, get_res(points));
      for (auto& pt : points) {
        pt.y = -pt.y;
      }
    }
    for (auto& pt : points) {
      pt.x = -pt.x;
    }
  }
  cout << small_ans;
  for (int i = 4; i <= n; ++i) {
    cout << " " << large_ans;
  }
  cout << endl;
}