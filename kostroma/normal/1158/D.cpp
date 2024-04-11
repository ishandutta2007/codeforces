#pragma comment(linker, "/STACK:512000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

#define int li
//const int mod = 1000000007;

struct Point {
  int x, y, id;
  Point() : x(0), y(0) {}
  Point(int x, int y) : x(x), y(y) {}
  Point operator - (const Point& ot) const {
    return Point(x - ot.x, y - ot.y);
  }
  int operator * (const Point& ot) const {
    return x * ot.y - y * ot.x;
  }
  bool operator < (const Point& ot) const {
    return make_pair(x, y) < make_pair(ot.x, ot.y);
  }
  bool operator == (const Point& ot) const {
    return make_pair(x, y) == make_pair(ot.x, ot.y);
  }
};

vector<Point> up, down;

vector<Point> get_hull(vector<Point>& points) {
  up.clear();
  down.clear();
  for (auto pt : points) {
    for (int w = 0; w < 2; ++w) {
      auto& cur_vec = (w == 0) ? up : down;
      while (cur_vec.size() >= 2) {
        auto diff = (cur_vec.back() - cur_vec[cur_vec.size() - 2]) * (cur_vec.back() - pt);
        if (w == 0 && diff <= 0 || w == 1 && diff >= 0) {
          cur_vec.pop_back();
        } else {
          break;
        }
      }
      cur_vec.push_back(pt);
    }
  }
  auto res = up;
  for (int i = (int)down.size() - 2; i > 0; --i) {
    res.push_back(down[i]);
  }
  return res;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 2000;
  }
  vector<Point> points(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> points[i].x >> points[i].y;
    } else {
      points[i].x = rand() % 100000000000;
      points[i].y = rand() % 100000000000;
    }
    points[i].id = i;
  }
  sort(all(points));
  string s;
  if (read) {
    cin >> s;
  } else {
    s.resize(n - 2);
    for (int i = 0; i < s.length(); ++i) {
      s[i] = "LR"[i % 2];
    }
  }
  auto hull = get_hull(points);
  vector<int> ans;
  for (int pos = 0; pos < s.length(); ) {
    int r = pos;
    while (r < s.length() && s[r] == s[pos]) {
      ++r;
    }
    int need = r - pos;
    while (need > 0) {
      if (s[pos] == 'L') {
        reverse(hull.begin() + 1, hull.end());
      }
      int can = min(need, (int)hull.size() - 1);
      need -= can;
      for (int i = 0; i < can; ++i) {
        ans.push_back(hull[i].id);
        auto erase_it = find(all(points), hull[i]);
        points.erase(erase_it);
      }
      auto cur_point = hull[can];
      hull = get_hull(points);
      auto it = find(all(hull), cur_point);
      rotate(hull.begin(), it, hull.end());
    }
    pos = r;
  }
  for (int i = 0; i < hull.size(); ++i) {
    ans.push_back(hull[i].id);
  }
  for (int x : ans) {
    cout << x + 1 << " ";
  }
  cout << endl;
}