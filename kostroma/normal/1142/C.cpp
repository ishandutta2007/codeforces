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
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
  void scan() {
    cin >> x >> y;
  }
  bool operator < (const Point& ot) const {
    return make_pair(x, y) < make_pair(ot.x, ot.y);
  }
};

int get_difference(Point q, Point w, Point candy) {
  return ((candy.y - q.y) - candy.x * (candy.x - q.x)) * (w.x - q.x) - (candy.x - q.x) * ((w.y - q.y) - w.x * (w.x - q.x));
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<Point> points(n);
  for (int i = 0; i < n; ++i) {
    points[i].scan();
  }
  sort(all(points));
  vector<Point> candies;
  for (int i = 0; i < n; ++i) {
    if (i + 1 < n && points[i + 1].x == points[i].x) {
      continue;
    }
    while (candies.size() >= 2 && get_difference(candies.back(), points[i], candies[candies.size() - 2]) > 0) {
      candies.pop_back();
    }
    candies.push_back(points[i]);
  }
  int ans = candies.size() >= 2;
  for (int i = 1; i + 2 <= candies.size(); ++i) {
    if (get_difference(candies[i], candies[i + 1], candies[i - 1]) < 0) {
      ++ans;
    }
  }
  cout << ans << endl;
}