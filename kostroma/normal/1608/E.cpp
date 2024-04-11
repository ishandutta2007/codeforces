#pragma comment(linker, "/STACK:512000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <memory>
#include <chrono>
#include <cassert>
#include <random>
#include <queue>
#include <set>
#include <map>
#include <array>
#include <bitset>
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
    freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;

#ifdef AIM
  const rlim_t kStackSize = 60 * 1024 * 1024;   // min stack size = 16 MB
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
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    cout.precision(20);
    cout << fixed;
    //cin >> t;
    precalc();
    int test_num = 1;
    while (t--) {
      //cout << "Case #" << test_num++ << ": ";
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
  Point(int x = 0, int y = 0): x(x), y(y) {}
  Point rotate() const {
    return Point(y, -x);
  }
  Point reflect() const {
    return Point(-x, y);
  }
  void scan() {
    cin >> x >> y;
  }
  bool operator < (const Point& ot) const {
    return make_pair(x, y) < make_pair(ot.x, ot.y);
  }
};

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<vector<Point>> points(3);
  for (int i = 0; i < n; ++i) {
    Point cur;
    cur.scan();
    int type;
    cin >> type;
    points[type - 1].push_back(cur);
  }

  const int INF = (int)1e9 + 100;

  int ans = 0;
  for (int reflect = 0; reflect < 2; ++reflect) {
    for (int rotate = 0; rotate < 4; ++rotate) {
      auto points_by_y = points;
      for (int i = 0; i < 3; ++i) {
        sort(all(points[i]));
        sort(all(points_by_y[i]), [&](const Point& q, const Point& w) {
          return q.y < w.y;
        });
      }

      vector<int> perm(3);
      iota(all(perm), 0);
      do {
        int last = perm[2], first = perm[0], mid = perm[1];

        auto border_by_x = [&](int cnt, int border) {
          int pos = -1;
          for (int i = n / 3 - 1; i >= 0; --i) {
            if (points[mid][i].x < border) {
              pos = i - cnt + 1;
              break;
            }
          }
          if (pos < 0) {
            return false;
          }
          border = points[mid][pos].x;
          return points[first][cnt - 1].x < border;
        };

        auto is_good = [&] (int cnt) {
          int border = points[last][n / 3 - cnt].x;
          if (border_by_x(cnt, border)) {
            return true;
          }
          int cnt_found = 0;
          int first_y = -INF;
          for (auto pt : points_by_y[first]) {
            if (pt.x >= border) {
              continue;
            }
            ++cnt_found;
            first_y = pt.y;
            if (cnt_found == cnt) {
              break;
            }
          }
          if (cnt_found < cnt) {
            return false;
          }
          cnt_found = 0;
          int mid_y = INF;
          for (int i = n / 3 - 1; i >= 0; --i) {
            auto pt = points_by_y[mid][i];
            if (pt.x >= border) {
              continue;
            }
            ++cnt_found;
            mid_y = pt.y;
            if (cnt_found == cnt) {
              break;
            }
          }
          if (cnt_found < cnt) {
            return false;
          }
          return first_y < mid_y;
        };

        int L = 0, R = n / 3 + 1;
        while (L + 1 < R) {
          int M = (L + R) / 2;
          if (is_good(M)) {
            L = M;
          } else {
            R = M;
          }
        }
        //cout << reflect << " " << rotate << " " << first << " " << mid << " " << last << " " << L << endl;
        relax_max(ans, L);
      } while (next_permutation(all(perm)));

      for (auto& vec : points) {
        for (auto& pt : vec) {
          pt = pt.rotate();
        }
      }
    }
    for (auto& vec : points) {
      for (auto& pt : vec) {
        pt = pt.reflect();
      }
    }
  }
  cout << ans * 3 << "\n";
}