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

//#define int li
//const li mod = 1000000007;
//using ull = unsigned long long;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n;

struct Point {
  int x, y;
  int id;
  Point() {}
  Point(int x, int y, int id = -1): x(x), y(y), id(id) {}
  Point move(int dir) {
    return Point(x + dx[dir], y + dy[dir], id);
  }
  bool operator < (const Point& ot) const {
    return make_pair(x, y) < make_pair(ot.x, ot.y);
  }
};

bool correct(Point cur) {
  return cur.x >= 0 && cur.x < n && cur.y >= 0 && cur.y < n;
}

struct Move {
  Point start, dest;
};

vector<Move> get_moves(vector<Point>& points) {
  sort(all(points));
  vector<Move> res;
  while (true) {
    bool have = false;
    for (int i = 0; i < points.size(); ++i) {
      if (points[i].x > i) {
        auto new_pos = points[i].move(1);
        res.push_back({points[i], new_pos});
        points[i] = new_pos;
        have = true;
      }
    }
    if (!have) {
      break;
    }
  }
  while (true) {
    bool have = false;
    for (int i = (int)points.size() - 1; i >= 0; --i) {
      if (points[i].x < i) {
        auto new_pos = points[i].move(0);
        res.push_back({points[i], new_pos});
        points[i] = new_pos;
        have = true;
      }
    }
    if (!have) {
      break;
    }
  }
  while (true) {
    bool have = false;
    for (int i = 0; i < points.size(); ++i) {
      int dir = -1;
      if (points[i].y < i) {
        dir = 3;
      } else if (points[i].y > i) {
        dir = 2;
      }
      if (dir != -1) {
        auto new_pos = points[i].move(dir);
        res.push_back({points[i], new_pos});
        points[i] = new_pos;
        have = true;
      }
    }
    if (!have) {
      break;
    }
  }

  for (int i = 0; i < points.size(); ++i) {
    if (points[i].id == i) {
      continue;
    }
    int need = -1;
    for (int j = i + 1; j < points.size(); ++j) {
      if (points[j].id == i) {
        need = j;
        break;
      }
    }
    assert(need != -1);
    for (int j = 0; j < need - i; ++j) {
      Point new_pos = points[i].move(0);
      res.push_back({points[i], new_pos});
      points[i] = new_pos;
      new_pos = points[need].move(1);
      res.push_back({points[need], new_pos});
      points[need] = new_pos;
    }
    for (int j = 0; j < need - i; ++j) {
      Point new_pos = points[i].move(3);
      res.push_back({points[i], new_pos});
      points[i] = new_pos;
      new_pos = points[need].move(2);
      res.push_back({points[need], new_pos});
      points[need] = new_pos;
    }
    swap(points[need], points[i]);
  }
  return res;
}

void solve(__attribute__((unused)) bool read) {
  int m;
  //read = false;
  if (read) {
    cin >> n >> m;
  } else {
    n = 50;
    m = 50;
  }
  vector<Move> res;
  set<pair<int, int>> have;
  for (int w = 0; w < 2; ++w) {
    vector<Point> points(m);
    for (int i = 0; i < m; ++i) {
      if (read) {
        cin >> points[i].x >> points[i].y;
      } else {
        do {
          points[i].x = rand() % n + 1;
          points[i].y = rand() % n + 1;
        } while (have.count({points[i].x, points[i].y}));
        have.insert({points[i].x, points[i].y});
      }
      points[i].id = i;
      --points[i].x;
      --points[i].y;
    }
    auto cur_vec = get_moves(points);
    if (w == 1) {
      reverse(all(cur_vec));
      for (auto& item : cur_vec) {
        swap(item.start, item.dest);
      }
    }
    for (auto item : cur_vec) {
      res.push_back(item);
    }
  }
  cout << res.size() << "\n";
  assert(res.size() <= 10800);
  for (auto item : res) {
    cout << item.start.x + 1 << " " << item.start.y + 1 << " " << item.dest.x + 1 << " " << item.dest.y + 1 << "\n";
  }
}